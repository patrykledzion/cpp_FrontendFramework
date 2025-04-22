#pragma once
#include <iostream>
#include <map>
#include "Document.h"
namespace nFrontendFramework {

	struct NavigationElement {
		std::string path;
		std::shared_ptr<Document> document;
	};

	class Navigation
	{
	private:
		std::shared_ptr<std::map<std::string, std::shared_ptr<Document>>> documents;
		std::string defaultPath;
		NavigationElement currentDocument;

	public:
		Navigation();
		~Navigation() = default;
		void Init();
		void Add(std::string path, std::shared_ptr<Document> document);
		void Navigate(std::string path);
		void SetDefault(std::string path);

	};
}
