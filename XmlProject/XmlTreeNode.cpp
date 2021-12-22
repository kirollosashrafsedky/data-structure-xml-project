#include "XmlTreeNode.h"

XmlTreeNode::XmlTreeNode(std::string tagName) : tagName{tagName}, value{value}, parent{NULL}
{
}

std::string XmlTreeNode::getTagName() const
{
	return this->tagName;
}

void XmlTreeNode::setTagName(std::string tagName)
{
	this->tagName = tagName;
}

std::string XmlTreeNode::getValue() const
{
	return this->value;
}

void XmlTreeNode::setValue(std::string value)
{
	this->value = value;
}

XmlTreeNode* XmlTreeNode::getParent() const
{
	return this->parent;
}

void XmlTreeNode::setParent(XmlTreeNode* parent)
{
	this->parent = parent;
}

std::vector<XmlTreeNode*> XmlTreeNode::getChildren() const
{
	return this->children;
}

void XmlTreeNode::appendChild(XmlTreeNode* child)
{
	child->setParent(this);
	this->children.push_back(child);
}

void XmlTreeNode::popLastChild()
{
	this->children.pop_back();
}

std::vector<XmlAttribute*> XmlTreeNode::getAttributes() const
{
	return this->attributes;
}

void XmlTreeNode::appendAttribute(XmlAttribute* attribute)
{
	this->attributes.push_back(attribute);
}

void XmlTreeNode::popLastAttribute()
{
	this->attributes.pop_back();
}

bool XmlTreeNode::hasChildren() const
{
	return (this->getNumberOfChildren() == 0);
}

int XmlTreeNode::getNumberOfChildren() const
{
	return this->children.size();
}

XmlTreeNode::~XmlTreeNode()
{
	for (auto& node : this->children)
	{
		delete node;
	}
}