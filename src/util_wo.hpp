/**
 * UTIL WITH PROJECT OBJECT
*/

#include "../inc/util_wo.h"

std::string check_balise(std::string str) {
	if((str == "div") || (str == "p") || (str == "head") || (str == "li")
		|| (str == "article") || (str == "section") || (str == "span"))
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


/***
 * @brief : Recursion  
 * Step 0 : Article {p {span} {span}}
 * Step 1 : Article -> Création article 
 * Step 2 : <article>p -> création p </article>
 * Step 3 : <article><p>-> création span ; création span</p></article>
 * Step 4 : <article><p><span></span><span></span></p></article>
*/

std::string without_accolade(std::string str) {
	int i = 0;
	int depart = 0;
	int fin = str.length();
	while(str[i] != '\0') {
		i++;
		if(str[i-1] == '{') {
			depart = i;
			break;
		}
	}
	
	int j = fin;
	while(j > depart) {
		j--;
		if(str[j+1] == '}') {
			fin = j;
			break;
		}
	}
	if((depart == 0) && (fin == str.length()))
		return str;
	return str.substr(depart,fin);
}


std::vector<int> split_or_not(std::string str, char splitter) {
	std::vector<int> vec_index_split;
	char split = splitter;
	int i = 0;
	int found_acco = 0;
	int found_accc = 0;
	int break_index = 0;
	while(str[i] != '\0') {
		if(str[i] == '{') 
			found_acco++;
		if(str[i] == '}')
			found_accc++;
		if(str[i] == split)
			if(found_accc == found_acco) {
				break_index = i;
				vec_index_split.push_back(break_index);
				break_index = 0;
			}
		i++;
	}
	return vec_index_split;
	
}

std::vector<std::string> split_str_homemade(std::string str, char splitter) {
	std::vector<int> split_index = split_or_not(str,splitter);
	std::vector<std::string> vec_str;
	std::string tmp = "";
	int depart = 0;
	int fin = 0;
	for(auto i : split_index) {
		fin = i; 
		tmp = str.substr(depart,fin-depart);//fin-depart = size;
		vec_str.push_back(tmp);
		tmp = "";
		depart = fin+1;
	}
	tmp = str.substr(depart,str.length());
	vec_str.push_back(tmp);
	return vec_str;
}	



Balise demand_in_balisev4(std::string str) {
	std::string without_acc = str;
	while((without_acc[0] == '{') && (without_acc[without_acc.length()-1] == '}')) 
		without_acc = without_accolade(without_acc);
	
	std::vector<std::string> split_first_level = split_str_homemade(without_acc,';');
	std::vector<Balise> vec_rtn;
	for(auto str_level1 : split_first_level) {
		std::string digts = extract_digit(str_level1);
		int sz_digit = (digts == "0") ? 0 : digts.length();
		int dt = (sz_digit == 0) ? 1 : stoi(digts);
		std::string suite_top = str_level1.substr(sz_digit);

		std::string balise_root = extract_balise(suite_top);
		std::string corresponding_tag = check_balise(balise_root);
		std::string suite_parse = suite_top.substr(corresponding_tag.length());
		int jFb = 0; // Option de mise en forme
		int jLb = 0; // ""
		int jLa = 0; // ""
		if(suite_parse == "") {
			jFb = 1;
			jLb = 1;
		}
		else {
			jFb = 1;
			jLb = 1;
		}
		
		for(int i = 0 ; i < dt; i++) {
			Balise rtn{corresponding_tag,{},{},jFb,jLb,jLa};
			if((suite_parse == "") || (suite_parse[0] == '}')) {
				vec_rtn.push_back(rtn);
				continue;
			}
			int jump = jump_to_next_balise(suite_parse);
			suite_parse = suite_parse.substr(jump);
			std::string digits = extract_digit(suite_parse);
			int size_digit = (digits == "0") ? 0 : digits.length();
			int digit = (size_digit == 0) ? 1 : stoi(digits);
			std::string suite = suite_parse.substr(size_digit);
			for(int i = 0 ; i < digit; i++) 
				rtn.add_balisev2(demand_in_balisev4(suite));
			vec_rtn.push_back(rtn);
		}
	}
	Balise global{};
	for(auto b : vec_rtn) 
		global.add_balisev2(b);
	return global;
}