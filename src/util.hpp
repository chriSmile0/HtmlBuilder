#include "../inc/util.h"
#include "../inc/util2.h"

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
			lines.push_back(str.substr(depart,i-depart));
			depart = i+1;
		}
	
	lines.push_back(str.substr(depart,i));
	return lines;
}

int countTab(std::string str) {
	int cpt = 0;
	for(auto c : str)
		if(c == '\t')
			cpt++;
	return cpt;
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

/*int eolInStr(std::string str) {
	int i = 0;
	int size = str.length();
	while((i < size) && (str[i] != '\n'))
		i++;
	return i;
}*/

idx_tabs searchBaliseInFile(std::fstream& f, int num, std::string balise) {
	idx_tabs i_t;
	f.seekp(0,std::ios::beg);
	std::string true_balise = "</"+balise+">"; // OU <balise> true_index += balise.length()
	std::string recup_line;
	std::string total_bloc;
	int goon = 1;
	int index = 0;
	int past = 0;
	while(((goon) && (past < num)) && (getline(f,recup_line))) {
		goon = ((index = inLine(recup_line,true_balise)) == -1) ? 1 : 0; 
		past = (index != -1) ? past+1 : past;
		if(past < num) 
			total_bloc += recup_line + "\n";
		//std::cout << countTab(recup_line) << std::endl;
	}
	//ici on peut compter les tabs en fonction du type de balise !!!
	bool isbloc = toIsBloc(toAsValue(balise));
	int nb_tab = countTab(recup_line);
	if(isbloc)
		i_t.nb_tabs = nb_tab;
	else 
		i_t.nb_tabs = 0;

	int true_index = total_bloc.length() + index; //+ (nb_tab-1);

	i_t.idx = true_index;
	return i_t;
}

void fileModification(std::fstream& f, std::string str) {
	for(auto m_f : extractLineContent(str)) {
		idx_tabs i_t = searchBaliseInFile(f,m_f.index,m_f.balise);
		if(i_t.nb_tabs != 0) {
			m_f.contenu += "\n";
			for(int i = 0 ; i < i_t.nb_tabs; i++) 
				m_f.contenu += "\t";
		}
		insertLineInFile(f,m_f.contenu,i_t.idx);

	}
}



int searchBaliseInFileForStyle(std::fstream& f, int num, std::string balise) {
	f.seekp(0,std::ios::beg);
	std::string true_balise = "<"+balise+">"; // OU <balise> true_index += balise.length()
	std::string true_baliseNEmpty = "<"+balise+" ";
	std::string recup_line;
	std::string total_bloc;
	int goon = 1;
	int index = 0;
	int past = 0;
	bool isempty = true;
	while(((goon) && (past < num)) && (getline(f,recup_line))) {
		goon = ((index = inLine(recup_line,true_balise)) == -1) ? 1 : 0; 
		if(goon == 1) {
			goon = ((index = inLine(recup_line,true_baliseNEmpty)) == -1) ? 1 : 0;
			isempty = (!goon) ? false : true;
		}
		past = (index != -1) ? past+1 : past;
		if(past < num) 
			total_bloc += recup_line + "\n";
	}
	std::cout << "is empty : " << isempty << std::endl;
	//ici on peut compter les tabs en fonction du type de balise !!!
	int true_index = total_bloc.length() + index; //+ (nb_tab-1);
	return true_index;
}


std::string lineInAttributLine(std::string str) {
	std::vector<std::string> vec_str = parseLine(str,'|');
	//On défini le fait que l'on peut avoir une ligne comme celle ci : 
		// 1p id=ID|classe=CLASSE|style=styler
	std::string out_str = "";
	for(auto v : vec_str) {
		std::cout << v << std::endl;
		/*std::vector<std::string> sv_str = parseLine(v,'=');
		out_str += sv_str.at(0)+"=";
		out_str += "\""+sv_str.at(1)+"\" ";*/
	}
	return out_str;
}

void fileModificationAttributeTags(std::fstream& f, std::string str) {
	for(auto m_f : extractLineContent(str)) {
		int index  = searchBaliseInFileForStyle(f,m_f.index,m_f.balise);
		//il faut ici parser le contenu potentiellement 
		insertLineInFile(f,m_f.contenu,index);

	}
}