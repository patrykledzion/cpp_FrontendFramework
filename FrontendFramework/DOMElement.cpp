#include "DOMElement.h"

nFrontendFramework::DOMElement::DOMElement(nXMLReader::XMLTag& tag)
{
	this->attributes = std::make_unique<std::unordered_map<DOMElementAttributeType, std::string>>();

	//this->attributesForElement.push_back(DOMElementAttributeType::id);
	//this->attributesForElement.push_back(DOMElementAttributeType::className);
} 

void nFrontendFramework::DOMElement::SetAttribute(DOMElementAttributeType type, std::string value)
{
	this->attributes->at(type) = value;
}

void nFrontendFramework::DOMElement::AppendChild(std::shared_ptr<DOMElement> element)
{
	this->children->push_back(element);
}
