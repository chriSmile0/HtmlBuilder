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


std::string check_balise(std::string str) {
	if((str == "div") || (str == "p") || (str == "head") || (str == "head") 
		|| (str == "li") || (str == "article") || (str == "section") 
		|| (str == "span"))
		return str;//TO BE CONTINUED 
	return "";
}

std::string extract_balise(std::string str) {
	int i = 0;
	while((str[i] != ' ') && (str[i] != '}') && (str[i] != '\0'))
		i++;
	return (i==0) ? str : str.substr(0,i);
}

int jump_to_next_balise(std::string str) {
	int i = 0;
	while(((str[i] == ' ') || (str[i] == '{')) && (str[i] != '\0'))  
		i++;
	return i;
}

std::string extract_digit(std::string str) {
	int i = 0;
	while(((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
		i++;
	if(i == 0)
		return "0";//tag = 1tag
	return str.substr(0,i);
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
    f.seekp(index,std::ios::beg);
	f << str << save_after_index;
}

std::vector<std::string> parseLine(std::string str, char splitter) {
	int i = 0;
	int size = str.length();
	std::vector<std::string> lines;
	int depart = 0;
	for(i = 0 ; i < size; i++)
		if(str[i] == splitter) {
			lines.push_back(str.substr(depart,i));
			depart = i+1;
		}
	lines.push_back(str.substr(depart,i));
	return lines;
}

std::vector<modif_struct> extractLineContent(std::string str) {
	std::vector<modif_struct> content;
	std::vector<std::string> lines = parseLine(str,';');
	for(auto l : lines) {
		modif_struct m_s;
		std::string digits = extract_digit(l);
		m_s.index = stoi(digits);
		l = l.substr(digits.length());
		std::string balise = extract_balise(l);
		m_s.balise = balise;
		l = l.substr(balise.length());
		l = l.substr(jump_to_next_balise(l));
		m_s.contenu = l;
		content.push_back(m_s);
	}	
	return content;
}


int inLine(std::string str, std::string token) {
	return str.find(token);
}

int searchBaliseInFile(std::fstream& f, int num, std::string balise) {
	std::string true_balise = "<"+balise+">";
	std::string recup_line;
	std::string total_bloc;
	int goon = 1;
	int index = 0;
	int past = 0;
	while(getline(f,recup_line) && (goon && (past < num))) {
		goon = ((index = inLine(recup_line,true_balise)) == -1) ? 1 : 0; 
		past = (index != -1) ? past+1 : past;
		if(past < num) 
			total_bloc += recup_line + "\n";
	}
	int true_index = total_bloc.length() + index + true_balise.length();
	return true_index;
}

void fileModification(std::fstream& f, std::string str) {
	for(auto m_f : extractLineContent(str))
		insertLineInFile(f,m_f.contenu,searchBaliseInFile(f,m_f.index,m_f.balise));
}