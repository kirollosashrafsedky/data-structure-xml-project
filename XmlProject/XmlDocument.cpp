#include "XmlDocument.h"

XmlDocument::XmlDocument() : root{NULL}
{
}

XmlTreeNode* XmlDocument::getRoot() const
{
	return this->root;
}

void XmlDocument::setRoot(XmlTreeNode* root)
{
	this->root = root;
}

void XmlDocument::appendChild(XmlTreeNode* child)
{
	this->root->appendChild(child);
}

void XmlDocument::appendAttribute(XmlAttribute* attribute)
{
	this->root->appendAttribute(attribute);
}

void XmlDocument::toString(XmlTreeNode* node, std::string& output, std::string indentationTabs)
{
	if(indentationTabs != "")
	{
		output += "\n";
	}
	output += indentationTabs + "<" + node->getTagName();

	for (int i = 0; i < node->getAttributes().size(); i++)
	{
		output += " " + node->getAttributes()[i]->getProperty() + "=\"" + node->getAttributes()[i]->getValue() + "\"";
	}
	output += ">";

	for (int i = 0; i < xmlTabSpaceSize; i++)
	{
		indentationTabs += " ";
	}
	if (node->getValue() != "")
	{
		output += "\n" + indentationTabs + node->getValue();
	}

	if (node->getNumberOfChildren() != 0) {
		for (int i = 0; i < node->getNumberOfChildren(); i++) {
			toString(node->children[i], output, indentationTabs);
		}
	}
	for (int i = 0; i < xmlTabSpaceSize; i++)
	{
		indentationTabs.pop_back();
	}
	output += "\n" + indentationTabs + "</" + node->getTagName() + ">";
}


XmlDocument::~XmlDocument()
{
	delete this->root;
}
