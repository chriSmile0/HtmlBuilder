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
	return (jump) ? ("\n"+tabulations+"<"+s+">") : ("<" + s + ">");
}
std::string getLpv2(std::string s, int jb, int ja, int nb_tab) {
	std::string tabs = "";
	for(int i = 0 ; i < nb_tab;i++)
		tabs += "\t";
	return (jb) ? ((!ja) ? ("\n"+tabs+"</" + s + ">") : (("\n"+tabs+"</" + s + ">\n"))) : ("</" + s + ">");
}


std::string checkTag(std::string str) {
	if((str == "div") || (str == "p") || (str == "head") || (str == "head") 
		|| (str == "li") || (str == "article") || (str == "section") 
		|| (str == "span"))
		return str;//TO BE CONTINUED 
	return "";
}

std::string extractTag(std::string str) {
	int i = 0;
	while((str[i] != ' ') && (str[i] != '}') && (str[i] != '\0'))
		i++;
	return (i==0) ? str : str.substr(0,i);
}

int jumpToNextTag(std::string str) {
	int i = 0;
	while(((str[i] == ' ') || (str[i] == '{')) && (str[i] != '\0'))  
		i++;
	return i;
}

std::string extractDigit(std::string str) {
	int i = 0;
	while(((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
		i++;
	return (i == 0) ? "0" : str.substr(0,i);
}


inline void growUpFile(std::fstream& f, int extend_size) { f.seekp(extend_size,std::ios::end);}

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
	int start = 0;
	for(i = 0 ; i < size; i++)
		if(str[i] == splitter) {
			lines.push_back(str.substr(start,i-start));
			start = i+1;
		}
	lines.push_back(str.substr(start,i));
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
		std::string digits = extractDigit(l);
		m_s.index = stoi(digits);
		l = l.substr(digits.length());
		std::string tag = extractTag(l);
		m_s.tag = tag;
		l = l.substr(tag.length());
		l = l.substr(jumpToNextTag(l));
		m_s.content = l;
		content.push_back(m_s);
	}	
	return content;
}

inline int inLine(std::string str, std::string token) {return str.find(token);}

idx_tabs searchTagInFile(std::fstream& f, int num, std::string tag) {
	idx_tabs i_t;
	f.seekp(0,std::ios::beg);
	std::string true_tag = "</"+tag+">"; // OR <tag> true_index += tag.length()
	std::string recup_line;
	std::string total_block;
	int goon = 1;
	int index = 0;
	int past = 0;
	while(((goon) && (past < num)) && (getline(f,recup_line))) {
		goon = ((index = inLine(recup_line,true_tag)) == -1) ? 1 : 0; 
		past = (index != -1) ? past+1 : past;
		if(past < num) 
			total_block += recup_line + "\n";
	}
	bool isbloc = toIsBlock(toAsValue(tag));
	int nb_tab = countTab(recup_line);
	i_t.nb_tabs = (isbloc) ? nb_tab : 0;

	int true_index = total_block.length() + index; //+ (nb_tab-1);
	i_t.idx = true_index;
	return i_t;
}

void fileModification(std::fstream& f, std::string str) {
	for(auto m_f : extractLineContent(str)) {
		idx_tabs i_t = searchTagInFile(f,m_f.index,m_f.tag);
		if(i_t.nb_tabs != 0) {
			m_f.content += "\n";
			for(int i = 0 ; i < i_t.nb_tabs; i++) 
				m_f.content += "\t";
		}
		insertLineInFile(f,m_f.content,i_t.idx);
	}
}

int searchTagInFileForStyle(std::fstream& f, int num, std::string tag) {
	f.seekp(0,std::ios::beg);
	std::string true_tag = "<"+tag+">"; // OR <tag> true_index += tag.length()
	std::string true_TagNEmpty = "<"+tag+" ";
	std::string result_line;
	std::string total_block;
	int goon = 1;
	int index = 0;
	int past = 0;
	bool isempty = true;
	while(((goon) && (past < num)) && (getline(f,result_line))) {
		goon = ((index = inLine(result_line,true_tag)) == -1) ? 1 : 0; 
		if(goon == 1) {
			goon = ((index = inLine(result_line,true_TagNEmpty)) == -1) ? 1 : 0;
			isempty = (!goon) ? false : true;
		}
		past = (index != -1) ? past+1 : past;
		if(past < num) 
			total_block += result_line + "\n";
	}
	std::string *tag_ptr = (isempty) ? &true_tag : &true_TagNEmpty ;
	int true_index = total_block.length() + index + tag_ptr->length()-1; //+ (nb_tab-1);
	return true_index;
}


line_options lineInAttributLine(std::string tag, std::string str) {
	std::vector<std::string> vec_str = parseLine(str,'|');
	std::string out_str = "";
	line_options lo;
	std::string option = "";
	std::string value = "";
	for(auto v : vec_str) {
		option_and_value ov;
		std::vector<std::string> sv_str = parseLine(v,'=');
		option = sv_str.at(0);
		if(!IsAssociateAttribute(toAsValue(tag),option)) {
			std::cerr << "\n***Error option not recognize : ***[" << option + "]\n" << std::endl;
			exit(1);
		}
		value = sv_str.at(1);
		out_str += option+"=";
		out_str += "\""+value+"\" ";
		ov.option = option;
		ov.value = value;
		lo.v.push_back(ov);
	}
	lo.str = out_str;
	return lo;
}

void insertLineInFileCss(std::string fout, std::vector<option_and_value> vecs) {
	std::ofstream f(fout);
	std::sort(vecs.begin(),vecs.end(),sortOv);	
	vecs.erase(std::unique(vecs.begin(),vecs.end(),multiClassUniqueId),vecs.end());
	for(auto ov : vecs) {
		if(ov.option == "id") 
			f <<  "#"+ov.value+" {\n}\n";
		else if(ov.option == "class") 
			f << "."+ov.value+" {\n}\n";
		else 
			std::cerr << "option not recognize " << std::endl;
	}
}

void fileModificationAttributeTags(std::fstream& f, std::string str, std::string fileout) {
	int flagout_css = (fileout != "") ? 1 : 0;
	vecOV v_o;
	for(auto m_f : extractLineContent(str)) {
		int index = searchTagInFileForStyle(f,m_f.index,m_f.tag);
		line_options lineAttrLine = lineInAttributLine(m_f.tag,m_f.content);
		std::string str_line = lineAttrLine.str;
		vecOV ov = lineAttrLine.v;
		insertLineInFile(f," "+str_line,index);
		if(flagout_css) 
			for(auto o_v : ov)
				v_o.push_back(o_v);
	}
	if(flagout_css)
		insertLineInFileCss(fileout,v_o);
}