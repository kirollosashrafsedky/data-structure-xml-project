#include "XmlAttribute.h"

XmlAttribute::XmlAttribute(std::string property, std::string value) : property {property}, value{value}
{
}

std::string XmlAttribute::getProperty() const
{
	return this->property;
}

void XmlAttribute::setProperty(std::string property)
{
	this->property = property;
}

std::string XmlAttribute::getValue() const
{
	return this->value;
}

void XmlAttribute::setValue(std::string value)
{
	this->value = value;
}
