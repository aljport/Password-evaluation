#pragma once
#include <string>
#include <vector>
class FileParser
{
public:
	bool FileToVector(std::string fileName, int lineLimit, std::vector<std::string> & vec);
};

