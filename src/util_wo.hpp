/**
 * UTIL WITH PROJECT OBJECT
*/

#include "../inc/util_wo.h"

std::string withoutBracket(std::string str) {
	int i = 0;
	int start = 0;
	int end = str.length();
	while(str[i] != '\0') {
		i++;
		if(str[i - 1] == '{') {
			start = i;
			break;
		}
	}
	int j = end;
	while(j > start) {
		j--;
		if(str[j + 1] == '}') {
			end = j;
			break;
		}
	}
	return ((start == 0) && (end == str.length())) ? str : str.substr(start,
																		end);
}

Tag demandInTag(std::string str, int tabulation) {
	std::string without_brack = str;
	while((without_brack[0] == '{') && (without_brack[without_brack.length() - 1] == '}')) 
		without_brack = withoutBracket(without_brack);
	
	std::vector<std::string> split_first_level = splitStrHomemade(without_brack,
																	';');
	std::vector<Tag> vec_rtn;
	int old_tab = tabulation;
	tabulation++;
	for(auto str_level1 : split_first_level) {
		std::string digts = extractDigit(str_level1);
		int sz_digit = (digts == "0") ? 0 : digts.length();
		int dt = (sz_digit == 0) ? 1 : stoi(digts);
		std::string next_top = str_level1.substr(sz_digit);

		std::string tag_root = extractTag(next_top);
		std::string corresponding_tag = checkTag(tag_root);
		std::string next_parse = next_top.substr(corresponding_tag.length());
		int jFb = 0; // Format option
		int jLb = 0; // ""
		int jLa = 0; // ""
		bool is_block = toIsBlock(toAsValue(corresponding_tag));
		if(is_block == true) {
			jFb = 1;
			jLb = 1;
		}
		for(int i = 0 ; i < dt ; i++) {
			Tag rtn{corresponding_tag, {}, {}, old_tab, jFb, jLb, jLa};
			if((next_parse == "") || (next_parse[0] == '}')) {
				vec_rtn.push_back(rtn);
				continue;
			}
			int jump = jumpToNextTag(next_parse);
			next_parse = next_parse.substr(jump);
			std::string digits = extractDigit(next_parse);
			int size_digit = (digits == "0") ? 0 : digits.length();
			int digit = (size_digit == 0) ? 1 : stoi(digits);
			std::string next = next_parse.substr(size_digit);
			for(int i = 0 ; i < digit ; i++) 
				rtn.addTag(demandInTag(next, tabulation));
			vec_rtn.push_back(rtn);
		}
	}
	Tag global{};
	for(auto b : vec_rtn) 
		global.addTag(b);
	return global;
}