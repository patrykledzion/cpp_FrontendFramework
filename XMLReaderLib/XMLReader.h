#pragma once
#include <iostream>
#include <vector>
#include "File.h"
#include "XMLTag.h"
#include "Tokenizer_v2.h"
#include "Token.h"

namespace nXMLReader {
	enum class XMLReaderError {
		OK,
		OTHER_PROBLEM,
		TAG_NOT_ENDED,
		TAG_NOT_STARTED,
		UNEXPECTED_TOKEN,
	};


	class XMLReader
	{
		std::unique_ptr<File> file;// = > {filename: "", content : "", filesize : 0}
		int pos = 0;
		std::unique_ptr<XMLTag> openedTag;
		std::shared_ptr<std::vector<XMLTag>> currTags;
		std::shared_ptr<std::vector<XMLTag>> tags;// => {tag: "", properties:[{name,value},...], innerXML: ""}
		std::unique_ptr<std::vector<Token>> tokens;
		bool bracketOpened = false;

		Token* GetLastToken() { return this->tokens != nullptr && this->tokens->size() > 0 ? &(this->tokens->at(this->tokens->size() - 1)) : nullptr; }
		Token* GetCurrentToken() { return this->tokens != nullptr && this->tokens->size() > this->pos ? &(this->tokens->at(this->pos)) : nullptr; }
		XMLTag* GetLastCurrTag() { return this->currTags != nullptr && this->currTags->size() > 0 ?  &(this->currTags->at(this->currTags->size() - 1)) : nullptr; }
		XMLTag* GetLastTag() { return this->tags != nullptr && this->tags->size() > 0 ?  &(this->tags->at(this->tags->size() - 1)) : nullptr; }

		XMLReaderError Tokenize();
		XMLReaderError InterpretTokens();
		XMLReaderError HandleOpeningBracket();
		XMLReaderError HandleTagName();
		XMLReaderError HandleClosingSlash();
		XMLReaderError HandlePropertyName();
		XMLReaderError HandlePropertyValue();
		XMLReaderError HandleClosingBracket();
		XMLReaderError HandleText();

		XMLReaderError PrintError(XMLReaderError err);

	public:
		static std::map < XMLReaderError, std::string> err_str;
		XMLReader(std::string filename);
		XMLReaderError Read();
		std::shared_ptr<std::vector<XMLTag>> GetTags() { return this->tags; }

	};
}

