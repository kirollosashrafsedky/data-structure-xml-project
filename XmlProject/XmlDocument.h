#ifndef _XML_DOCUMENT_
#define _XML_DOCUMENT_

#include <string>
#include "XmlTreeNode.h"
#include "XmlAttribute.h"

const int xmlTabSpaceSize = 4;

class XmlDocument
{
private:
	XmlTreeNode* root;

public:
	XmlDocument();
	XmlTreeNode* getRoot() const;
	void setRoot(XmlTreeNode* root);
	void appendChild(XmlTreeNode* child);
	void appendAttribute(XmlAttribute* attribute);
	static void toString(XmlTreeNode* node, std::string& output, std::string indentationTabs = "");
	~XmlDocument();
};

#endif /* _XML_DOCUMENT_ */

