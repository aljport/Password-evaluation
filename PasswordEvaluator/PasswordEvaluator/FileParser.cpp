#include "FileParser.h"
#include<sstream>
#include <iostream>
#include <fstream>
//References used for file
//https://cplusplus.com/reference/fstream/ifstream/ for ifstream for reading from file
//Written by Andrew Goldstein

bool FileParser::FileToVector(std::string fileName, int lineLimit, std::vector<std::string> & vec)
{
	//Checks to see if line limit is within acceptable range
	if (lineLimit < 100000 || lineLimit > 999997)
	{
		std::cout << "Please enter a line limit over 100,000 and under 999,997." << std::endl;
		return false;
	}
	else
	{
		//Reads file name from data folder
		std::ifstream file("./data/" + fileName);
		std::string next;

		//Checks to make sure no errors with opening the file
		if (!file.is_open())
		{
			std::cout << "Error with opening file." << std::endl;
			return false;
		}

		//Disregarding first line in data as it's just data titles
		std::getline(file, next);

		//Goes through data up to the line limit and puts it in the given vector
		for (int i = 0; i < lineLimit; i++)
		{
			if (!file.eof())
			{
				std::getline(file, next);
				std::istringstream lineStream(next);
				std::getline(lineStream, next, ',');
				unsigned int rank = std::stoul(next);
				std::getline(lineStream, next);
				vec.push_back(next);
			}

		}

		file.close();

		if (file.is_open())
		{
			std::cout << "Error with closing file." << std::endl;
			return false;
		}

	}
	return true;
}
