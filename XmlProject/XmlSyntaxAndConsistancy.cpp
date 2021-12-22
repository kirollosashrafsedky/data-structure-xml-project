#include "XmlSyntaxAndConsistancy.h"

bool checkXmlSyntax(const std::string& xml, XmlError& error)
{
    bool isCorrect = false;
    error.setErrorMsg("No tags were sene");
    bool isFirstTime = true;
    std::stack <char> st;
    int numberOfBreakLines = 0;
    int posOfLastBreakLine = 0;
    int i;
    for (i = 0; i < xml.size(); i++)
    {
        if ((xml[i] == '<')) {
            if (isFirstTime)
            {
                isCorrect = true;
                isFirstTime = false;
            }
            if (!st.empty()) {
                isCorrect = false;
                error.setErrorMsg("Opening bracket \'<\' was seen without seeing closing bracket \'>\'");
                break;
            }
            st.push('<');
        }
        else if (xml[i] == '>')
        {
            if (st.empty()) {
                isCorrect = false;
                error.setErrorMsg("Closing bracket \'>\' was seen without seeing opening bracket \'<\'");
                break;
            }
            else
            {
                st.pop();
                if (!st.empty())
                {
                    isCorrect = false;
                    break;
                }
            }
        }
        else if (xml[i] == '\r')
        {
            numberOfBreakLines++;
            posOfLastBreakLine = i;
        }
    }
    if (!st.empty()) {
        isCorrect = false;
        error.setErrorMsg("Opening bracket \'<\' was seen without seeing closing bracket \'>\'");
    }

    if (!isCorrect)
    {
        error.setRow(numberOfBreakLines + 1);
        error.setCol(i - posOfLastBreakLine);
    }

    return isCorrect;
}

bool checkXmlConsistancy(const std::string& xmlString, std::string& correctXml, XmlError& error)
{
    std::stack <std::string> STags;
    std::string Tag;
    std::string ctag;
    bool isCorrect = 1;
    int numberOfBreakLines = 0;
    int posOfLastBreakLine = 0;
    int i;
    for (i = 0; i < xmlString.size(); i++) {
        int initialIndex = i;
        if (xmlString[i] == '<') {
            i++;
            if (xmlString[i] != '/') {
                while (xmlString[i] != '>' && !isspace(xmlString[i])) {
                    Tag += xmlString[i];
                    i++;
                }
                STags.push(Tag);
                Tag = "";
            }
            
            else
            {
                i++;
                while (xmlString[i] != '>') {
                    ctag += xmlString[i];
                    i++;
                }
                if (STags.empty())
                {
                    if (isCorrect)
                    {
                        error.setErrorMsg("Parent xml tag wasn't found");
                        error.setRow(numberOfBreakLines + 1);
                        error.setCol(i - posOfLastBreakLine);
                    }
                    isCorrect = 0;
                    break;
                }
                else
                {
                    if (STags.top() == ctag)
                    {
                        STags.pop();
                        ctag = "";
                    }
                    else
                    {
                        if (STags.size() != 1)
                        {
                            correctXml.append("</" + STags.top() + ">");
                            STags.pop();

                        }
                        if (isCorrect)
                        {
                            error.setErrorMsg("Tags mismatch found");
                            error.setRow(numberOfBreakLines + 1);
                            error.setCol(i - posOfLastBreakLine);
                        }
                        isCorrect = 0;
                        ctag = "";
                        continue;
                    }
                }
                
            }
        }
        else if (xmlString[i] == '\r')
        {
            numberOfBreakLines++;
            posOfLastBreakLine = i;
        }
        for (int j = initialIndex; j <= i; j++)
        {
            correctXml.push_back(xmlString[j]);
        }
    }
    while (!STags.empty())
    {
        if (isCorrect)
        {
            error.setErrorMsg("Tags mismatch found");
            error.setRow(numberOfBreakLines + 1);
            error.setCol(i - posOfLastBreakLine);
        }
        isCorrect = 0;
        correctXml.append("</" + STags.top() + ">");
        STags.pop();
    }
    return isCorrect;
}

void xmlParse(const std::string& xmlString, XmlDocument& xmlDoc)
{
    int i = 0;
    bool readingTagName = false;
    std::string tagName = "";
    while (xmlString[i] != '<')
        i++;
    i++;
    while (!readingTagName || (xmlString[i] != '>' && !isspace(xmlString[i])))
    {
        if (!isspace(xmlString[i]))
        {
            readingTagName = true;
        }
        tagName += xmlString[i];
        i++;
    }
    trim(tagName);
    XmlTreeNode* tag = new XmlTreeNode(tagName);
    xmlDoc.setRoot(tag);
    generateXmlTree(xmlString, i, xmlDoc.getRoot());
}

void generateXmlTree(const std::string& xmlString, int& i, XmlTreeNode* xmlNode)
{
    std::string nodeText = "";
    // attributes
    while (xmlString[i] != '>')    // there are attributes
    {
        std::string attrName = getStringTill(xmlString, i, '=');
        getStringTill(xmlString, i, '\"');
        i++;
        std::string attrValue = getStringTill(xmlString, i, '\"');
        //cout << attrName + "=\"" + attrValue + "\"" << endl;
        i++;
        xmlNode->appendAttribute(new XmlAttribute(attrName, attrValue));
    }
    i++;
    while (isspace(xmlString[i]))
        i++;
    //if(xmlString[i] != '<')
    nodeText = getStringTill(xmlString, i, '<');
    //cout << nodeText << endl;
    i++;
    while (true)
    {
        while (isspace(xmlString[i]))
            i++;
        if (xmlString[i] == '/')
        {
            getStringTill(xmlString, i, '>');
            i++;
            break;
        }
        else
        {
            std::string tagName = "";

            bool readingTagName = false;
            while (!readingTagName || (xmlString[i] != '>' && !isspace(xmlString[i])))
            {
                if (!isspace(xmlString[i]))
                {
                    readingTagName = true;
                }
                tagName += xmlString[i];
                i++;
            }

            XmlTreeNode* tag = new XmlTreeNode(tagName);
            xmlNode->appendChild(tag);
            generateXmlTree(xmlString, i, tag);
            nodeText += getStringTill(xmlString, i, '<');
            i++;
        }
    }
    xmlNode->setValue(nodeText);
}

std::string getStringTill(const std::string& str, int& index, char stopChar1, char stopChar2)
{
    std::string out = "";
    bool reading = false;
    while (str[index] != stopChar1 && (stopChar2 == '\0' || str[index] != stopChar2))
    {
        out += str[index];
        index++;
    }
    trim(out);
    return out;
}

static inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

static inline void trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}