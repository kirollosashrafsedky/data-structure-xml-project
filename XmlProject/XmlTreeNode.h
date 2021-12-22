#ifndef _XML_TREE_NODE_
#define _XML_TREE_NODE_

#include<string>
#include<vector>
#include"XmlAttribute.h"

class XmlTreeNode
{
	friend class XmlDocument;
private:
    std::string tagName;
    std::string value;
    XmlTreeNode* parent;
    std::vector <XmlTreeNode*> children;
	std::vector <XmlAttribute*> attributes;

public:
    XmlTreeNode(std::string tagName);

	std::string getTagName() const;
	void setTagName(std::string tagName);
	
	std::string getValue() const;
	void setValue(std::string value);

	XmlTreeNode* getParent() const;
	void setParent(XmlTreeNode* parent);

	std::vector<XmlTreeNode*> getChildren() const;
	void appendChild(XmlTreeNode* child);
	void popLastChild();

	std::vector<XmlAttribute*> getAttributes() const;
	void appendAttribute(XmlAttribute* attribute);
	void popLastAttribute();

	bool hasChildren() const;
	int getNumberOfChildren() const;

	~XmlTreeNode();
};

#endif /* _XML_TREE_NODE_ */

