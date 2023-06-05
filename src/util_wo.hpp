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


std::vector<Balise> balise_in_line(std::string str) {
	std::vector<std::string> parent_tags = split_str(str,';');
	std::vector<Balise> balise_lines;
	for(auto tag_l : parent_tags)
		balise_lines.push_back(demand_in_balise(tag_l));
	return balise_lines;
}

std::vector<Balise> balise_in_linev2(std::string str) {
	std::vector<std::string> parent_tags = split_str(str,';');
	std::vector<Balise> balise_lines;
	for(auto tag_l : parent_tags)
		balise_lines.push_back(demand_in_balisev2(tag_l));
	return balise_lines;
}

Balise demand_in_balise(std::string str) {
	std::cout << "str ::" << str  << std::endl;
	std::string balise_root = extract_balise(str);
	std::string corresponding_tag = check_balise(balise_root);
	Balise rtn{corresponding_tag,{},{},0,1};
	std::string suite_parse = str.substr(corresponding_tag.length());
	if((suite_parse == "") || (suite_parse[0] == '}')) {
		rtn.setJump(0);
		return rtn;
	}

	int jump = jump_to_next_balise(suite_parse);

	suite_parse = suite_parse.substr(jump);
	std::string digits = extract_digit(suite_parse);

	int size_digit = (digits == "0") ? 0 : digits.length();
	int digit = (size_digit == 0) ? 1 : stoi(digits);
	std::cout << "digit : " << digit << std::endl;
	std::string suite = suite_parse.substr(size_digit);
	std::cout << "suiiite" << suite << std::endl;
	for(int i = 0 ; i < digit ; i++) 
		rtn.add_balise(demand_in_balise(suite));
	return rtn;
}

Balise demand_in_balisev2(std::string str) {
	std::cout << "str ::" << str  << std::endl;
	std::string balise_root = extract_balise(str);
	std::string corresponding_tag = check_balise(balise_root);
	Balise rtn{corresponding_tag,{},{},0,1};
	std::string suite_parse = str.substr(corresponding_tag.length());
	if(suite_parse == "") {
		rtn.setJump(0);
		return rtn;
	}

	suite_parse = suite_parse.substr(1);//jump de 1 pour atteindre les {}
	//Ensuite on cherche la fin de la première accolade puis ainsi de suite 
	std::cout << suite_parse << std::endl;
	


	return rtn;
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



Balise demand_in_balisev3(std::string str) {
	std::string without_acc = str;
	while((without_acc[0] == '{') && (without_acc[without_acc.length()-1] == '}')) {
		without_acc = without_accolade(without_acc);
		std::cout << "passage ici " << std::endl;
	}
	std::string balise_root = extract_balise(without_acc);
	std::string corresponding_tag = check_balise(balise_root);
	Balise rtn{corresponding_tag,{},{},0,1};

	std::string suite_parse = without_acc.substr(corresponding_tag.length());
	if((suite_parse == "") || (suite_parse[0] == '}')) {
		rtn.setJump(0);
		return rtn;
	}
	int jump = jump_to_next_balise(suite_parse);
	suite_parse = suite_parse.substr(jump);
	std::string digits = extract_digit(suite_parse);
	int size_digit = (digits == "0") ? 0 : digits.length();
	int digit = (size_digit == 0) ? 1 : stoi(digits);
	std::string suite = suite_parse.substr(size_digit);
	for(int i = 0 ; i < digit; i++) 
		rtn.add_balise(demand_in_balisev3(suite));
	return rtn;
}

///*********************************/////



Balise demand_in_balisev4(std::string str) {
	return {};
}