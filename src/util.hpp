#include "../inc/util.h"
#include "../inc/util2.h"
#include <cmath>

std::vector<int> splitOrNot(std::string str, char splitter) {
	std::vector<int> vec_index_split;
	char split = splitter;
	int i = 0;
	int found_bracko = 0;
	int found_brackc = 0;
	int break_index = 0;
	while(str[i] != '\0') {
		if(str[i] == '{') 
			found_bracko++;
		if(str[i] == '}')
			found_brackc++;
		if(str[i] == split)
			if(found_brackc == found_bracko) {
				break_index = i;
				vec_index_split.push_back(break_index);
				break_index = 0;
			}
		i++;
	}
	return vec_index_split;
}

std::vector<std::string> splitStrHomemade(std::string str, char splitter) {
	std::vector<int> split_index = splitOrNot(str,splitter);
	std::vector<std::string> vec_str;
	std::string tmp = "";
	int start = 0;
	int end = 0;
	for(auto i : split_index) {
		end = i; 
		tmp = str.substr(start,end-start);//end-start = size;
		vec_str.push_back(tmp);
		tmp = "";
		start = end+1;
	}
	tmp = str.substr(start,str.length());
	vec_str.push_back(tmp);
	return vec_str;
}

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

std::vector<modif_struct> extractLineContent(std::string str, char mode) {
	std::vector<modif_struct> content;
	std::vector<std::string> lines = parseLine(str,';');
	for(auto l : lines) {
		modif_struct m_s;
		std::vector<tag_and_index> t_i;
		int digit = 0;
		std::string digits;
		std::string tag;
		std::string l_content;
		if(mode == '2') { //CUT LINE with ">" not necessary -> 1p>1p = 2p
			std::vector<std::string> split_l = parseLine(l,'>');
			int size_split_l = split_l.size() - 1;
			if (size_split_l == 0)
				mode = '1';
			else {
				int i = 0;
				for(i = 0 ; i < size_split_l  ;i++) {
					std::string tmp_digit = extractDigit(split_l.at(i));
					int tag_digit = stoi(tmp_digit);
					std::string in_tag = extractTag(split_l.at(i).substr(tmp_digit.length()));
					t_i.push_back({in_tag,tag_digit});
					digits += split_l.at(i)+">";
					//CHECK VALIDITY OF TAG AGAIN HERE -> NEXT
				}
				l = l.substr(digits.length());
				digits = extractDigit(l);
				int last_digit = stoi(digits); 
				l = l.substr(digits.length());
				tag = extractTag(l);
				for(auto t_and_i : t_i) 
					if(t_and_i.tag == tag) 
						digit = t_and_i.index + last_digit;
				l = l.substr(tag.length()); 
			}
		}
		if(mode != '2') {
			digits = extractDigit(l);
			digit = stoi(digits); 
			l = l.substr(digits.length());
			tag = extractTag(l);
			l = l.substr(tag.length());
		}
		m_s.index = digit;
		m_s.tag = tag;
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
	for(auto m_f : extractLineContent(str,'1')) {
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
		index = 0;
		goon = ((index = inLine(result_line,true_tag)) == -1) ? 1 : 0; 
		if(goon == 1) {
			goon = ((index = inLine(result_line,true_TagNEmpty)) == -1) ? 1 : 0;
			isempty = (!goon) ? false : true;
		}
		past = (index != -1) ? past+1 : past;
		if(past < num) {
			total_block += result_line + "\n";
			goon = 1;
		}

	}
	std::string *tag_ptr = (isempty) ? &true_tag : &true_TagNEmpty;
	int true_index = total_block.length() + index + tag_ptr->length()-1;
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
	int new_size = out_str.size()-1;
	out_str.resize(new_size);
	lo.str = out_str;
	lo.tag = tag;
	return lo;
}

void insertLineInFileCss(std::string f_in, std::ofstream &f, 
		std::vector<option_and_value> vecs, std::vector<Tag_opts> tags_opts) {
	std::vector<option_and_value> vecs_options;
	std::vector<std::string> tags = {"*","html","body","header","section",
								"article","div","p","footer","span"};//TO BE CONTINUED -> TAGS in HTML2 Use storeStrEnum() ;-)
	std::fstream file(f_in,std::ios::in | std::ios::out);
	//DEFAULT_CSS_CONTENT
	std::string dflt_css_ctt = "\tmargin: auto;\n";
	//END DEFAULT_CSS_CONTENT
	std::vector<std::string> tree = treeOfHtml(file);
	std::string res = profondeurMaxTree(tree,0);
	std::vector<std::string> all_paths;
	std::vector<std::string> split = splitStrHomemade(res,';');
	for(auto spl : split) {
		int size_spl = spl.size();
		std::string copy_spl = spl;
		int nb_inh = 0;
		for(int i = 0 ; i < size_spl ; i++) {
			if(spl[i] == '>') {
				if(nb_inh > 0) // Because you have unique selector in other tab
					all_paths.push_back(copy_spl.substr(0,i));
				all_paths.push_back(copy_spl.substr(i+1));
				nb_inh++;
			}
			if(i + 1 == size_spl) // Because you have unique selector in other tab
				all_paths.pop_back(); 
		}
	}
	for(auto t_opts : tags_opts) {
		tags.push_back(t_opts.tag);
		for(auto opts : t_opts.vec_ov) 
			vecs_options.push_back(opts);
	}
	
	std::sort(tags.begin(),tags.end(),sortStr);
	std::sort(tags.begin(),tags.end(),sortCssTags);
	tags.erase(std::unique(tags.begin(),tags.end(),uniqueTag),tags.end());
	

	std::sort(vecs_options.begin(),vecs_options.end(),sortOv);	
	vecs_options.erase(std::unique(vecs_options.begin(),vecs_options.end(),multiClassUniqueId),vecs_options.end());

	f << "/** UNIQUE SELECTOR **/\n" << std::endl;
	for(auto tag : tags) 
		f << tag + " {\n"+dflt_css_ctt+"}\n" << std::endl;
	
	f << "/** UNIQUE ID_CLASS **/\n" << std::endl;
	for(auto ov : vecs_options) {
		if(ov.option == "id") 
			f <<  "#"+ov.value+" {\n"+dflt_css_ctt+"}\n\n";
		else if(ov.option == "class") 
			f << "."+ov.value+" {\n"+dflt_css_ctt+"}\n\n";
		else 
			std::cerr << "option not recognize " << std::endl;
	}

	f << "/** SELECTOR.CLASS **/\n" << std::endl;
	for(auto t_opts : tags_opts) {
		for(auto ov : t_opts.vec_ov) 
			if(ov.option == "class") 
				f << t_opts.tag + "."+ov.value+" {\n"+dflt_css_ctt+"}\n\n";
	}
	f << "/** SELECTOR>SELECTOR **/\n" << std::endl;
	std::sort(all_paths.begin(),all_paths.end(),sortStr);
	all_paths.erase(std::unique(all_paths.begin(),all_paths.end(),uniqueHtmlTree),all_paths.end());
	for(auto path : all_paths) {
		f << path + " {\n"+dflt_css_ctt+"}\n\n";
	}
	f << "/** OTHERS **/\n" << std::endl;
}

void fileModificationAttributeTags(std::string f_in,std::fstream& f, std::string str, std::string fileout) {
	int flagout_css = (fileout != "") ? 1 : 0;
	vecOV v_o;
	vecTagOpts v_t_o;
	std::ofstream f_out(fileout);
	for(auto m_f : extractLineContent(str,'2')) {
		int index = searchTagInFileForStyle(f,m_f.index,m_f.tag);
		line_options lineAttrLine = lineInAttributLine(m_f.tag,m_f.content);
		std::string str_line = lineAttrLine.str;
		vecOV ov = lineAttrLine.v;
		insertLineInFile(f," "+str_line,index);
		if(flagout_css) {
			v_t_o.push_back({lineAttrLine.tag,ov});
			for(auto o_v : ov)
				v_o.push_back(o_v);
		}
	}
	if(flagout_css)
		insertLineInFileCss(f_in,f_out,v_o,v_t_o);
}



std::vector<std::string> treeOfHtml(std::fstream& f) {
	std::string result_line;
	std::vector<std::string> tags = storeStrEnum();
	std::vector<std::string> tree;
	int tags_size = sizeNameTags();
	int i = 0;
	int find = -1;
	int level_in = 0; // level of inheritance
	while(getline(f,result_line)) {
		i = 0; // search tags in file
		while(i < tags_size) {
			if((find = result_line.find("<"+tags[i]+">") != -1) 
				|| (find = result_line.find("<"+tags[i]+" ") != -1))  {
				tree.push_back(std::to_string(level_in)+"<"+tags[i]);
				level_in++;
			}
			if(find = result_line.find("</"+tags[i]+">") != -1) {
				level_in--;
				tree.push_back(std::to_string(level_in)+">"+tags[i]);
				break;
			}
			i++;
		}
		find = -1;
	}
	return tree;
}

std::string profondeurMaxTree(std::vector<std::string> tree, int level) {
	if (tree.size() == 1) { 
		return tree.at(0).substr(2); // We keept it for <a /> 
	}
	else if(tree.size() == 2) {
		int level_a = stoi(extractDigit(tree.at(0)));
		int level_b = stoi(extractDigit(tree.at(1)));
		if ((level_a == level_b) && (level_a == level))
			return tree.at(0).substr(2)+";";
	}
	else {
		std::string this_selector = tree.at(0).substr(2);
		int index = 0; 
		int nb_next_level = 0;
		std::vector<int> cuts_in_tree; 
		for(int i = 0; i < tree.size() ;i++) {
			int level_ = stoi(extractDigit(tree.at(i)));
			if (level_ == level) {
				tree.erase(tree.begin()+i);
				i--;
			}
			else if (level_ == level + 1) {
				nb_next_level++;
				cuts_in_tree.push_back(i);
			}
		}
		int level_up = level + 1;
		nb_next_level /= 2;
		std::string res_final = "";
		std::vector<std::string> all_childs;
		int j = 0;
		for(int i = 0 ; i < nb_next_level ; i++) {
			int cut1 = cuts_in_tree.at(j);
			int cut2 = cuts_in_tree.at(j+1);
			std::vector<std::string> sub_tree = {tree.begin()+cut1, tree.begin()+cut2+1};
			j += 2;
			all_childs.push_back(this_selector + ">" +profondeurMaxTree(sub_tree,level_up));
		}
		for(auto child : all_childs)
			res_final += child ;
		return res_final;
	}
	return "";
}