#pragma once
#include <map>
#include <iostream>
#include <vector>
#include <XMLTag.h>
#include <unordered_map>


namespace nFrontendFramework {

	enum class DOMElementAttributeType;
	enum class DOMElementType;


	class DOMElement
	{
	private:
		std::shared_ptr<DOMElement> parent;
		std::unique_ptr<std::vector<std::shared_ptr<DOMElement>>> children;
		std::unique_ptr<std::unordered_map<DOMElementAttributeType, std::string>> attributes;
		//StyleSheet style
		//
	public:
		DOMElement(nXMLReader::XMLTag& tag);
		~DOMElement() = default;

		void SetAttribute(DOMElementAttributeType type, std::string value);
		void AppendChild(std::shared_ptr<DOMElement> element);

		static std::map<DOMElement, std::string> DOMElementTypes;
		static std::vector<DOMElementAttributeType> attributesForElement;
	};

	enum class DOMElementAttributeType
	{
		id,
		width,
		height,
		className,
	};
	 
	enum class DOMElementType
	{
		View,
		Text,
	};


}

 