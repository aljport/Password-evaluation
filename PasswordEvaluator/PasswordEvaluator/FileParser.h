#pragma once
#include <string>
#include <vector>
class FileParser
{
public:
	bool FileToVector(std::string fileName, int lineLimit, std::vector<std::pair<unsigned int, std::string>>& vec);
private:
	void ScrambleVector(std::vector<std::pair<unsigned int, std::string>>& vec, int seed);
};

