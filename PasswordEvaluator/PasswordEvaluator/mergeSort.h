#pragma once
#include <vector>
#include <string>
class mergeSort
{
private:
	void merge(std::vector<std::string>& vec, int beg, int mid, int end);
public:
	void mSort(std::vector<std::string>& vec, int beg, int end);
	void printVector(std::vector<std::string> vec);
};
