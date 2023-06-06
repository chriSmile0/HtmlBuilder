#include "../inc/util.h"

std::vector<std::string> readLines(std::fstream f) {
	std::string line;
	std::vector<std::string> vec;
	while(getline(f,line))
		vec.push_back(line);
	return vec;
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