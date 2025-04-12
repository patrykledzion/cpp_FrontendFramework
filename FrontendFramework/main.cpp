#include <XMLReader.h>

int main()
{
	nXMLReader::XMLReader reader = nXMLReader::XMLReader("src/testfile.xml");

	reader.Read();
	for (int i = 0; i < reader.GetTags()->size(); i++)
	{
		nXMLReader::XMLTag& tag = reader.GetTags()->at(i);
		tag.PrintTag(0);
		int x = 2137;
	}
	return 0;
}