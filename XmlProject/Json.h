#ifndef _JSON_H_
#define _JSON_H_

#include <string>
#include "JsonNode.h"

class Json {
private:
	JsonCompoundNode* jsonHeadNode;

public:
	Json();
	JsonCompoundNode* getHeadNode() const;
	void setHeadNode(JsonCompoundNode* jsonHeadNode);
	void appendChild(JsonNode* jsonHeadNode);
	std::string toString() const;
	~Json();
};

#endif /* _JSON_H_ */
