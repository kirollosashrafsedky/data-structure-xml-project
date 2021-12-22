#ifndef _XML_SYNTAX_AND_CONSISTANCY_
#define _XML_SYNTAX_AND_CONSISTANCY_

#include <string>
#include <stack>
#include "XmlError.h"
#include "XmlDocument.h"

bool checkXmlSyntax(const std::string& xml, XmlError& error);

bool checkXmlConsistancy(const std::string& xmlString, std::string& correctXml, XmlError& error);

void xmlParse(const std::string& xmlString, XmlDocument& xmlDoc);

void generateXmlTree(const std::string& xmlString, int& i, XmlTreeNode* xmlNode);

std::string getStringTill(const std::string& str, int& index, char stopChar1, char stopChar2 = '\0');

static inline void ltrim(std::string& s);

static inline void rtrim(std::string& s);

static inline void trim(std::string& s);

#endif /* _XML_SYNTAX_AND_CONSISTANCY_ */

