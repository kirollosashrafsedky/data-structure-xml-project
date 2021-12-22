#include "JsonNode.h"

// JsonNode

JsonNode::JsonNode(std::string nodeName, JsonNodeType nodeType)
	: nodeName{nodeName}, nodeType{nodeType}, parent {NULL}
{
}

std::string JsonNode::getNodeName() const
{
	return this->nodeName;
}

void JsonNode::setNodeName(std::string nodeName)
{
	this->nodeName = nodeName;
}

JsonNodeType JsonNode::getNodeType() const
{
	return this->nodeType;
}

void JsonNode::setNodeType(JsonNodeType nodeType)
{
	this->nodeType = nodeType;
}

JsonNode* JsonNode::getParent() const
{
	return this->parent;
}

void JsonNode::setParent(JsonNode* parent)
{
	this->parent = parent;
}


JsonNode::~JsonNode()
{
}

// JsonFinalNode

JsonFinalNode::JsonFinalNode(std::string nodeName, std::string nodeText)
	: JsonNode(nodeName, JsonFinalNodeType), nodeText{nodeText}
{
}

std::string JsonFinalNode::getNodeText() const
{
	return this->nodeText;
}

void JsonFinalNode::setNodeText(std::string nodeText)
{
	this->nodeText = nodeText;
}

std::string JsonFinalNode::toString(std::string indentationTabs) const
{
	if (getParent() != NULL && getParent()->getNodeType() == JsonArrayNodeType)
		return indentationTabs + "\"" + this->nodeText + "\"";
	else
		return indentationTabs + "\"" + this->getNodeName() + "\": \"" + this->nodeText + "\"";
}


JsonFinalNode::~JsonFinalNode()
{
	// do nothing
}

// jsonCompundNode

JsonCompoundNode::JsonCompoundNode(JsonNodeType nodeType, std::string nodeName)
	: JsonNode(nodeName, nodeType)
{
}

std::vector<JsonNode*> JsonCompoundNode::getNodeArray() const
{
	return this->children;
}

void JsonCompoundNode::setNodeArray(std::vector<JsonNode*> children)
{
	this->children = children;
}

void JsonCompoundNode::appendChild(JsonNode* child)
{
	child->setParent(this);
	this->children.push_back(child);
}

std::string JsonCompoundNode::toString(std::string indentationTabs) const
{
	std::string out;

	if (getParent() == NULL || getParent()->getNodeType() == JsonArrayNodeType)
	{
		out = indentationTabs;
		this->getNodeType() == JsonArrayNodeType ? out += "[\n" : out += "{\n";
	}
	else
	{
		out = indentationTabs + "\"" + this->getNodeName() + "\" : ";
		this->getNodeType() == JsonArrayNodeType ? out += "[\n" : out += "{\n";
	}

	for (int i = 0; i < tabSpaceSize; i++)
	{
		indentationTabs += " ";
	}

	for (int i = 0; i < this->children.size(); i++)
	{
		out += this->children[i]->toString(indentationTabs);
		if (i != this->children.size() - 1)
		{
			out += ",\n";
		}
	}

	for (int i = 0; i < tabSpaceSize; i++)
	{
		indentationTabs.pop_back();
	}

	out += +"\n" + indentationTabs;
	this->getNodeType() == JsonArrayNodeType ? out += "]" : out += "}";
	return out;
}

bool JsonCompoundNode::searchChildren(std::string nodeName, JsonNode** parentNode)
{
	for (auto& child : this->children)
	{
		if (child->getNodeName() == nodeName)
		{
			*parentNode = child;
			return true;
		}
	}
	*parentNode = this;
	return false;
}

void JsonCompoundNode::deleteChild(JsonNode* child)
{
	int i;
	for (i = 0; i < this->children.size() ; i++)
	{
		if (this->children.at(i) == child)
		{
			break;
		}
	}
	std::vector<JsonNode*>::iterator it;

	it = this->children.begin() + i;
	this->children.erase(it);

}

JsonCompoundNode::~JsonCompoundNode()
{
	for (auto& child : this->children)
	{
		delete child;
	}
}

//// JsonObjectNode
//
//JsonObjectNode::JsonObjectNode(std::string nodeName)
//	: JsonNode(nodeName, JsonObjectNodeType)
//{
//}
//
//std::vector<JsonNode*> JsonObjectNode::getNodeArray() const
//{
//	return this->children;
//}
//
//void JsonObjectNode::setNodeArray(std::vector<JsonNode*> children)
//{
//	this->children = children;
//}
//
//void JsonObjectNode::appendChild(JsonNode* child)
//{
//	child->setParent(this);
//	this->children.push_back(child);
//}
//
//std::string JsonObjectNode::toString(std::string indentationTabs) const
//{
//	std::string out;
//	
//	if (getParent() == NULL || getParent()->getNodeType() == JsonArrayNodeType)
//	{
//		out = indentationTabs + "{\n";
//	}
//	else
//	{
//		out = indentationTabs + "\"" + this->getNodeName() + "\" : " + "{\n";
//	}
//
//	for (int i = 0; i < tabSpaceSize; i++)
//	{
//		indentationTabs += " ";
//	}
//
//	for (int i = 0; i < this->children.size(); i++)
//	{
//		out += this->children[i]->toString(indentationTabs);
//		if (i != this->children.size() - 1)
//		{
//			out += ",\n";
//		}
//	}
//
//	for (int i = 0; i < tabSpaceSize; i++)
//	{
//		indentationTabs.pop_back();
//	}
//
//	out += + "\n" + indentationTabs + "}";
//	return out;
//}
//
//JsonObjectNode::~JsonObjectNode()
//{
//	for (auto& child : this->children)
//	{
//		delete child;
//	}
//}
//
//// JsonArrayNode
//
//JsonArrayNode::JsonArrayNode(std::string nodeName)
//	: JsonNode(nodeName, JsonArrayNodeType)
//{
//}
//
//std::vector<JsonNode*> JsonArrayNode::getNodeArray() const
//{
//	return this->children;
//}
//
//void JsonArrayNode::setNodeArray(std::vector<JsonNode*> children)
//{
//	this->children = children;
//}
//
//void JsonArrayNode::appendChild(JsonNode* child)
//{
//	child->setParent(this);
//	this->children.push_back(child);
//}
//
//std::string JsonArrayNode::toString(std::string indentationTabs) const
//{
//	std::string out;
//
//	if (getParent() == NULL || getParent()->getNodeType() == JsonArrayNodeType)
//	{
//		out = indentationTabs + "[\n";
//	}
//	else
//	{
//		out = indentationTabs + "\"" + this->getNodeName() + "\" : " + "[\n";
//	}
//
//	for (int i = 0; i < tabSpaceSize; i++)
//	{
//		indentationTabs += " ";
//	}
//
//	for (int i = 0; i < this->children.size(); i++)
//	{
//		out += this->children[i]->toString(indentationTabs);
//		if (i != this->children.size() - 1)
//		{
//			out += ",\n";
//		}
//	}
//
//	for (int i = 0; i < tabSpaceSize; i++)
//	{
//		indentationTabs.pop_back();
//	}
//
//	out += +"\n" + indentationTabs + "]";
//	return out;
//}
//
//JsonArrayNode::~JsonArrayNode()
//{
//	for (auto& child : this->children)
//	{
//		delete child;
//	}
//}
