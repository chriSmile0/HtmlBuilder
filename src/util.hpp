#include "../inc/util.h"

std::vector<std::string> readLines(std::fstream f) {
	std::string line;
	std::vector<std::string> vec;
	while(getline(f,line))
		vec.push_back(line);
	return vec;
}

int count_jumpline(std::string str) {
	int j = 0;
	int size = str.length();
	for(int i = 0 ; i < size ;i++)
		if(str[i] == '\n')
			j++;
	return j;
}