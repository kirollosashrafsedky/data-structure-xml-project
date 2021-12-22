#include "Json.h"

Json::Json() : jsonHeadNode{new JsonCompoundNode(JsonObjectNodeType)}
{
}

JsonCompoundNode* Json::getHeadNode() const
{
	return this->jsonHeadNode;
}

void Json::setHeadNode(JsonCompoundNode* jsonHeadNode)
{
	this->jsonHeadNode = jsonHeadNode;
}

void Json::appendChild(JsonNode* jsonHeadNode)
{
	this->jsonHeadNode->appendChild(jsonHeadNode);
}

std::string Json::toString() const
{
	return this->jsonHeadNode->toString();
}

Json::~Json()
{
	delete this->jsonHeadNode;
}

