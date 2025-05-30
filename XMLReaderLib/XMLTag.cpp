﻿#include "XMLTag.h"

namespace nXMLReader {

	void XMLTag::AddProperty(std::string name, std::string value)
	{
		this->properties->push_back(std::make_shared<XMLProperty>(name, value));
	}

	bool XMLTag::isTagNameCharacter(char c)
	{
		if (c == '-' || c == '.' || c == 0xB7)			return true;
		if (isdigit(c))									return true;
		if (c >= 0x300 && c <= 0x036f)					return true;
		if (c >= 0x203F && c <= 0x2040)					return true;
		if (XMLTag::isTagNameStartCharacter(c))			return true;
		return false;
	}

	bool XMLTag::isTagNameStartCharacter(char c)
	{
		if (c == ':' || c == '_')						return true;
		if (isalpha(c))									return true;
		if (c >= 0xD8 && c <= 0xD6)						return true;
		if (c >= 0xD8 && c <= 0xf6)						return true;
		if (c >= 0xF8 && c <= 0x2FF)					return true;
		if (c >= 0x370 && c <= 0x37D)					return true;
		if (c >= 0x37F && c <= 0x1FFF)					return true;
		if (c >= 0x200C && c <= 0x200D)					return true;
		if (c >= 0x2070 && c <= 0x218F)					return true;
		if (c >= 0x2C00 && c <= 0x2FEF)					return true;
		if (c >= 0x3001 && c <= 0xD7FF)					return true;
		if (c >= 0xF900 && c <= 0xFDCF)					return true;
		if (c >= 0xFDF0 && c <= 0xFFFD)					return true;
		if (c >= 0x10000 && c <= 0xEFFFF)				return true;
		return false;
	}

	XMLTag::XMLTag(std::string tag) : tag(std::move(tag))
	{
		this->children = std::make_shared<std::vector<XMLTag>>();
		this->properties = std::make_unique<std::vector<std::shared_ptr<XMLProperty>>>();
	}

	XMLTag::XMLTag(const XMLTag& other)
	{  
		this->tag = other.tag;
		 
		if (other.properties) {
			this->properties = std::make_unique<std::vector<std::shared_ptr<XMLProperty>>>();
			for (const auto& prop : *other.properties) {
				this->properties->push_back(prop); 
			}
		}
		 
		this->innerXML = other.innerXML;
		 
		if (other.children) {
			this->children = std::make_shared<std::vector<XMLTag>>();
			for (const auto& child : *other.children) {
				this->children->push_back(child);   
			}
		}
	}

	void XMLTag::SetProperty(std::string name, std::string value)
	{
		bool found = false;
		//find property
		for (int i = 0; i < this->properties->size(); i++)
		{
			std::shared_ptr<XMLProperty> _prop = this->properties->at(i);
			if (_prop->GetName() == name)
			{
				found = true;
				_prop->SetValue(value);
			}
		}

		if (!found)
		{
			this->AddProperty(name, value);
		}
	}

	void XMLTag::SetInnerXML(std::string value)
	{
		this->innerXML = value;
	}

	void XMLTag::AddChild(XMLTag& child)
	{ 
		this->children->push_back(child); 
	}

	void XMLTag::PrintTag(int level)
	{
		for (int i = 0; i < level; i++)std::cout << "	";
		std::cout << this->tag << std::endl;
		if (!this->innerXML.empty())
		{
			for (int i = 0; i < level; i++)std::cout << "	";
			std::cout << "   \"" << this->innerXML << "\"" << std::endl;
		}

		for (int i = 0; i < this->properties->size(); i++)
		{
			for (int i = 0; i < level; i++)std::cout << "	";
			std::cout << "   - " << this->properties->at(i)->GetName() << ": " << this->properties->at(i)->GetValue() << std::endl;
		}

		for (int i = 0; i < this->children->size(); i++)
		{
			this->children->at(i).PrintTag(level + 1);
		}
	}
}