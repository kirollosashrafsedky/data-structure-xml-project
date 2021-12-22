#ifndef _XML_TO_JSON_
#define _XML_TO_JSON_

#include <string>
#include "Json.h"
#include "JsonNode.h"
#include "XmlDocument.h"

std::string xmlToJson(const XmlDocument& xml);
void generateJsonTree(const XmlTreeNode* xmlNode, JsonNode* jsonNode);

#endif /* _XML_TO_JSON_ */

