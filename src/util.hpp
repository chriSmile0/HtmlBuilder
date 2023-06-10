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

void growUpFile(std::fstream& f, int extend_size) {//HOME
	f.seekp(extend_size,std::ios::end);
}

void insertLineInFile(std::fstream& f, std::string str, int index) {
	int size_line = str.length();
	std::string save_after_index = "";
	std::string recup;
	f.seekp(index,std::ios::beg);
	while(getline(f,recup)) 
		save_after_index += recup + "\n";
	f.clear();
	//f << agrandissement;
    f.seekp(index,std::ios::beg);
	f << str << save_after_index;
	//growUpFile(f,size_line);
    //f.clear();//IMPORTANT!
    //insertLineInFile(f);
    //f << "coucou" ;
    //std::cout << save_after_index;
	//f.seekp(0,std::ios::end);
	//growUpFile(f,size_line);
	//f.seekp(index,std::ios::beg);
	//f << str ;//<< save_after_index;
}