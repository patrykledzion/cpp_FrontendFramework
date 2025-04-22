#include "Navigation.h"

nFrontendFramework::Navigation::Navigation()
{
	this->documents = std::make_shared<std::map<std::string, std::shared_ptr<Document>>>();
	

}

void nFrontendFramework::Navigation::Init()
{
	this->currentDocument = { this->defaultPath, this->documents->at(this->defaultPath) };
}
