#ifndef _JSON_NODE_H_
#define _JSON_NODE_H_

#include <string>
#include <vector>
#include <iostream>

const int tabSpaceSize = 4;

enum JsonNodeType {
	JsonFinalNodeType, JsonObjectNodeType, JsonArrayNodeType
};

class JsonNode {
private:
	std::string nodeName;
	JsonNodeType nodeType;
	JsonNode* parent;

public:
	JsonNode(std::string nodeName = "null", JsonNodeType nodeType = JsonFinalNodeType);
	std::string getNodeName() const;
	void setNodeName(std::string nodeName);
	JsonNodeType getNodeType() const;
	void setNodeType(JsonNodeType nodeType);
	JsonNode* getParent() const;
	void setParent(JsonNode* parent);
	virtual std::string toString(std::string indentationTabs = "") const = 0;
	virtual ~JsonNode();
};


class JsonFinalNode : public JsonNode {
private:
	std::string nodeText;

public:
	JsonFinalNode(std::string nodeName = "null", std::string nodeText = "");
	std::string getNodeText() const;
	void setNodeText(std::string nodeText);
	std::string toString(std::string indentationTabs = "") const;
	~JsonFinalNode();
};

class JsonCompoundNode : public JsonNode {
private:
	std::vector<JsonNode*> children;

public:
	JsonCompoundNode(JsonNodeType nodeType, std::string nodeName = "null");
	std::vector<JsonNode*> getNodeArray() const;
	void setNodeArray(std::vector<JsonNode*> children);
	void appendChild(JsonNode* child);
	std::string toString(std::string indentationTabs = "") const;
	bool searchChildren(std::string nodeName, JsonNode** parentNode);
	void deleteChild(JsonNode* child);
	~JsonCompoundNode();
};


#endif /* _JSON_NODE_H_ */
