#include "DOMElement_View.h"

nFrontentFramework::DOMElement_View::DOMElement_View(nXMLReader::XMLTag& tag) : DOMElement(tag)
{
	this->attributesForElement = DOMElement::attributesForElement;
	this->attributesForElement.push_back(DOMElementAttributeType::width);
	this->attributesForElement.push_back(DOMElementAttributeType::height);
}
 
