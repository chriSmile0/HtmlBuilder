/**
 * UTIL WITH PROJECT OBJECT
*/

#include "../inc/util_wo.h"

std::vector<std::string> split_str(std::string str, char split) {
	std::vector<std::string> vec_str;
	int size = str.length();
	int j = 0; //depart de la str
	std::string tmp = "";
	for(int i = 0 ; i < size ; i++) {
		if(str[i] == split) {
			i++;
			vec_str.push_back(tmp);
			tmp = "";
		}
		tmp += str[i];
	}
	vec_str.push_back(tmp);
	return vec_str;
}

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

/////**************CHANGEMENT DE STRAT*********************/////

std::string without_accolade(std::string str) {
	int i = 0; //parcours
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


///*********************************/////
std::vector<int> split_or_not(std::string str,char splitter) {//Splitter = ';' ou ',' à voir 
	//on check si il y'a des accolades entre le splitter et le debut de la str
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
				std::cout << "break : " << break_index << std::endl;
				vec_index_split.push_back(break_index);
				break_index = 0;
			}
		i++;
	}
	std::cout << "facco : " << found_accc << " found accc : " << found_accc << std::endl;
	std::cout << "break index : " << break_index << std::endl;
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
		std::cout << "depart : " << depart << ", fin : " << fin << std::endl;
		tmp = str.substr(depart,fin-depart);//fin-depart = size;
		std::cout << "str : " << str << std::endl;
		std::cout << "tmp cut : " << tmp << std::endl;
		vec_str.push_back(tmp);

		//suite
		tmp = "";
		depart = fin+1;
	}
	tmp = str.substr(depart,str.length());
	std::cout << "tmp final " << tmp << std::endl;
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
		std::cout << " > " << str_level1 << std::endl;


		std::string balise_root = extract_balise(str_level1);
		std::string corresponding_tag = check_balise(balise_root);
		std::string suite_parse = str_level1.substr(corresponding_tag.length());
		int jFb = 0; // Option de mise en forme
		int jLb = 0; // ""
		int jLa = 0; // ""
		if(suite_parse == "") {
			jFb = 1;
			jLb = 1;
		}
		else {
			jFb = 1; //À voir 
			jLb = 1;
		}
		
		Balise rtn{corresponding_tag,jFb,jLb,jLa};

		if((suite_parse == "") || (suite_parse[0] == '}')) {
			rtn.setJump(0);
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
		rtn.setJump(0);
		vec_rtn.push_back(rtn);
	}
	Balise global{};
	for(auto b : vec_rtn) {
		std::cout << b.getBloc_balise() << std::endl;
		global.add_balisev2(b);
		std::cout << global.getBloc_balise() << std::endl;
	}
	return global;
}