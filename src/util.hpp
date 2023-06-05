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

std::string getFpv2(std::string s, int jump) {
	if(jump)
		return ("\n<"+s+">");
	return  ("<" + s + ">");
}
std::string getLpv2(std::string s, int jb, int ja) {
	if((jb) && (!ja))
		return ("\n</" + s + ">");
	if((jb) && (ja))
		return (("\n</" + s + ">\n"));
	return ("</" + s + ">");
}