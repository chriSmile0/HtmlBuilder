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

Balise demand_in_balise(std::string str) {
	std::cout << "strrr : " << str << std::endl;

	std::string balise_root = extract_balise(str);
	std::cout << "extract ok: balise : " << balise_root  << std::endl;
	std::string corresponding_tag = check_balise(balise_root);
	std::cout << "corresponding tag ok , tag :" << corresponding_tag << std::endl;
	//std::vector<std::string> 
	Balise rtn{corresponding_tag,{},{},0,1};
	std::string suite_parse = str.substr(corresponding_tag.length());
	std::cout << "s_p" << suite_parse << std::endl;
	if((suite_parse == "") || (suite_parse[0] == '}')) {
		rtn.setJump(0);
		return rtn;
	}

	suite_parse = suite_parse.substr(2);
	std::cout << "suite parseee : " << suite_parse << std::endl;

	std::string digits = extract_digit(suite_parse);

	//FINIR LE BUG ICI 
	
	int size_digit = (digits == "0") ? 0 : stoi(digits);
	int digit = (size_digit == 0) ? 1 : size_digit; 
	std::string suite = suite_parse.substr(size_digit);
	std::cout << "|" << suite << "|" << std::endl;
	for(int i = 0 ; i < digit ; i++) 
		rtn.add_balise(demand_in_balise(suite));


	

	//Voir pour la faire sur une str comme -> p 3li a 1b 
	//Ce qui donne ceci en langage balise 
	/**
	 * <p>
	 * 		<ul>
	 * 			<li><a><b></b></a></li>
	 * 			<li><a><b></b></a></li>
	 * 			<li><a><b></b></a></li>
	 * 		</ul>
	 * </p>
	*/

	//On peut caller des séparateurs comme ';' pour distinguer les différents groupes
	//Exemple : p 3li; p 
	/**
	 * <p>
	 * 		<ul>
	 * 			<li></li>
	 * 			<li></li>
	 * 			<li></li>
	 * 		</ul>
	 * </p>
	 * <p>
	 * </p>
	*/


	return rtn;
}