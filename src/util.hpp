#include "../inc/util.h"

std::vector<std::string> readLines(std::fstream f) {
	std::string line;
	std::vector<std::string> vec;
	while(getline(f,line))
		vec.push_back(line);
	return vec;
}

std::string getFpv2(std::string s, int jump, int nb_tab) {
	std::string tabulations = "";
	for(int i = 0 ; i < nb_tab;i++)
		tabulations += "\t";
	if(jump)
		return ("\n"+tabulations+"<"+s+">");
	return  ("<" + s + ">");
}
std::string getLpv2(std::string s, int jb, int ja, int nb_tab) {
	std::string tabulations = "";
	for(int i = 0 ; i < nb_tab;i++)
		tabulations += "\t";
	if((jb) && (!ja))
		return ("\n"+tabulations+"</" + s + ">");
	if((jb) && (ja))
		return (("\n"+tabulations+"</" + s + ">\n"));
	return ("</" + s + ">");
}