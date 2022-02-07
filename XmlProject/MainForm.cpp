#include "MainForm.h"
#include "graphFrm.h"
#include <string>
#include "XmlSyntaxAndConsistancy.h"
#include "XmlMinification.h"
#include "xmlToJson.h"
#include "XmlCompression.h"
#include"Xmlgraphrepresentation.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    XmlProject::MainForm mainForm;        //NameOfProject::NameOfForm instanceOfForm;
    Application::Run(% mainForm);
}

void XmlProject::MainForm::checkSyntax(bool showMsg)
{
    if (String::IsNullOrWhiteSpace(this->richTextBoxInput->Text))
    {
        MessageBox::Show("Empty text", "Error");
        return;
    }
    if (this->richTextBoxInput->Tag == "cxml")
    {
        MessageBox::Show("This operation is for xml files only (.xml), not compressed xml files", "Error");
        return;
    }
    std::string xmlStr = msclr::interop::marshal_as< std::string >(this->richTextBoxInput->Text);
    XmlError error;
    if (!checkXmlSyntax(xmlStr, error))
    {
        std::string errorMsg = error.getErrorMsg() + "\nat line: " + std::to_string(error.getRow()) + ", and col: " + std::to_string(error.getCol());
        MessageBox::Show(gcnew String(errorMsg.c_str()), "Xml Syntax Results");
    }
    else
    {
        if (showMsg)
        {
            MessageBox::Show("Correct XML Syntax", "Xml Syntax Results");
        }
        isSyntaxChecked = true;
    }
}

void XmlProject::MainForm::checkConsistancy(bool showMsg)
{
    std::string xmlStr = msclr::interop::marshal_as< std::string >(this->richTextBoxInput->Text);
    std::string correctXml;
    XmlError error;
    if (checkXmlConsistancy(xmlStr, correctXml, error))
    {
        if (showMsg)
        {
            MessageBox::Show("Correct XML Tags", "Xml Syntax Results");
        }
        isConsistancyChecked = true;
        xmlParse(xmlStr, *(this->xmlTree));
    }
    else
    {
        String^ errorMsg = gcnew String(error.getErrorMsg().c_str());
        String^ errorMsgRowCol = errorMsg + " at line: " + error.getRow().ToString() + ", col: " + error.getCol().ToString();
        MessageBox::Show(errorMsgRowCol + "\nThe error was solved, now the xml syntax is valid but it may result is logical error, Please revise it again.");
        String^ sysStr = gcnew String(correctXml.c_str());
        this->richTextBoxInput->Text =sysStr;

    }
    
}

void XmlProject::MainForm::minify()
{
    std::string xmlStr = msclr::interop::marshal_as< std::string >(this->richTextBoxInput->Text);
    std::string minifiedXml = minifcation(xmlStr);
    this->richTextBoxOutput->Tag = "xml";
    this->richTextBoxOutput->Text = gcnew String(minifiedXml.c_str());
}

void XmlProject::MainForm::prettify()
{
    std::string xmlStr;
    XmlDocument::toString(this->xmlTree->getRoot(), xmlStr);
    this->richTextBoxOutput->Tag = "xml";
    String^ sysStr = gcnew String(xmlStr.c_str());
    sysStr = sysStr->Replace("\n", "\r\n");
    this->richTextBoxOutput->Text = sysStr;

}

void XmlProject::MainForm::toJson()
{
    std::string json = xmlToJson(*(this->xmlTree));
    this->richTextBoxOutput->Tag = "json";
    String^ sysStr = gcnew String(json.c_str());
    sysStr = sysStr->Replace("\n", "\r\n");
    this->richTextBoxOutput->Text = sysStr;
}

void XmlProject::MainForm::compress()
{
    if (this->richTextBoxInput->Tag == "cxml")
    {
        MessageBox::Show("This operation is for xml files only (.xml), not compressed xml files", "Error");
        return;
    }
    std::string xmlStr = msclr::interop::marshal_as< std::string >(this->richTextBoxInput->Text);
    std::string compressedStr = compressXml(xmlStr);
    char* compressedStrArr = new char[compressedStr.size() + 1];
    std::copy(compressedStr.begin(), compressedStr.end(), compressedStrArr);
    compressedStrArr[compressedStr.size()] = '\0';
    String^ test = gcnew String(compressedStrArr, 0, compressedStr.length());
    test = test->Replace("\0", "<null>");
    this->richTextBoxOutput->Text = test;
    this->richTextBoxOutput->Tag = "cxml";

}

void XmlProject::MainForm::decompress()
{
    if (this->richTextBoxInput->Tag == "xml")
    {
        MessageBox::Show("This operation is for compressed xml files only (.cxml), not regular xml files", "Error");
        return;
    }
    String^ xmlStrSystem = this->richTextBoxInput->Text->Replace("<null>", "\0");
    std::string xmlStr = msclr::interop::marshal_as< std::string >(xmlStrSystem);

    std::string decompressedStr = decompressXml(xmlStr);

    char* compressedStrArr = new char[decompressedStr.size() + 1];
    std::copy(decompressedStr.begin(), decompressedStr.end(), compressedStrArr);
    compressedStrArr[decompressedStr.size()] = '\0';
    String^ test = gcnew String(compressedStrArr, 0, decompressedStr.length());
    test = test->Replace("\0", "<null>");

    this->richTextBoxOutput->Text = test;
}

void XmlProject::MainForm::showGraph()
{
   Graph g= Xml_DFS(this->xmlTree->getRoot());
   socialVisualizeDraw(g.getVertex(), g.getEgdes());
    
}

void XmlProject::MainForm::socialVisualizeDraw(std::vector<std::string>& ids, std::vector<std::vector<int>>& edges)
{
    std::ofstream myfile("ss.dot");
    myfile << "digraph test{\nnode[shape=\"record\" color=\"blue\"]\n";
    for (int i = 0; i < ids.size(); i++)
    {
        myfile << i + 1 << "[ label =\"{" << ids[i] << "}\" ]\n" << std::endl;
        for (int j = 0; j < edges.size(); j++)
        {
            if (edges[i][j])
            {
                myfile << i + 1 << "->"
                    << "{" << j + 1 << "}" << std::endl;
            }
        }
    }
    myfile << "}";
    myfile.close();
    std::system("dot -Tpng -O ss.dot");
    Form^ rgForm = gcnew graphFrm();
    rgForm->Show();
}