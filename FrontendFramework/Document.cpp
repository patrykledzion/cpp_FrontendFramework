#include "Document.h"

nFrontendFramework::Document::Document()
{
	this->domTree = std::make_unique<DOMTree>();
}

std::shared_ptr<nFrontendFramework::DOMElement> nFrontendFramework::Document::getElementById(std::string id)
{
	return this->domTree->byId.at(id);
}

std::shared_ptr<nFrontendFramework::DOMElement> nFrontendFramework::Document::getElementByClassName(std::string className)
{
	return this->domTree->byClassName.at(className);
}

std::shared_ptr<nFrontendFramework::DOMElement> nFrontendFramework::Document::getElementsByTagName(std::string tagName)
{
	return this->domTree->byTagName.at(tagName);
}

void nFrontendFramework::Document::AppendChild(std::shared_ptr<DOMElement> element)
{
	std::unordered_map<std::string, std::shared_ptr<DOMElement>>::const_iterator got = this->domTree->byTagName.find("Root");
	
	if (got == this->domTree->byTagName.end())
	{
		std::cout << "No root element";
		return;
	}
	std::shared_ptr<DOMElement> root = got->second;
	root->AppendChild(element);

}
