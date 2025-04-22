#pragma once
#include <iostream>
#include <vector>

class XMLDOM
{
private:
	std::shared_ptr<std::vector<std::shared_ptr<int>>> xmlTree;
public:
	XMLDOM();
	~XMLDOM();

};

