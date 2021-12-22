#ifndef _XML_ATTRIBUTE_
#define _XML_ATTRIBUTE_

#include<string>

class XmlAttribute
{
private:
	std::string property;
	std::string value;

public:
	XmlAttribute(std::string property, std::string value);

	std::string getProperty() const;
	void setProperty(std::string property);

	std::string getValue() const;
	void setValue(std::string value);

};

#endif /* _XML_ATTRIBUTE_ */