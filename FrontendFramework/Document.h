#pragma once
#include <unordered_map>
#include <iostream>
#include "DOMElement.h"

namespace nFrontendFramework {

	struct DOMTree {
		std::unordered_map<std::string, std::shared_ptr<DOMElement>> byId;
		std::unordered_map<std::string, std::shared_ptr<DOMElement>> byClassName;
		std::unordered_map<std::string, std::shared_ptr<DOMElement>> byTagName;
		std::vector<std::shared_ptr<DOMElement>> tree;
	};

	class Document
	{
	private:
		std::unique_ptr<DOMTree> domTree;
		void LoadFile(std::string path);
	public:
		Document();
		~Document() = default;

		std::shared_ptr<DOMElement> getElementById(std::string id);
		std::shared_ptr<DOMElement> getElementByClassName(std::string className);
		std::shared_ptr<DOMElement> getElementsByTagName(std::string tagName);

		static void createElement();
		void AppendChild(std::shared_ptr<DOMElement> element);
	};
}
