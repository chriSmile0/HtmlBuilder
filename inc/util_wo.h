#ifndef UTILWO_H
#define UTILWO_H

#include "html.h"

/**
 * @brief	Il s'agit là d'effacer de la chaine les '{'/'}' de la chaine en 
 * 			entrée
 * @brief	Remove the '{' '}' of the parameter string
 * @param{str}	string to parse
 * @return	the string without '{'/'}'
*/
std::string withoutBracket(std::string str);

/**
 * @brief	Homemade split with a precise character. But these string must 
 * 			have the same parent
 * @param{str}	the stirng to split
 * @param{spliiter}	split character
 * @return	the split string in diffetrents vector
*/
std::vector<std::string> splitStrHomemade(std::string str, char splitter);

/**
 * @brief	Known if it's possible to split the string
 * @param{str}	the string to split
 * @param{splitter}	split character
 * @return 	an index vector which means where the string is cut
*/
std::vector<int> splitOrNot(std::string str, char splitter);

/**
 * @brief	The project body.
 * 			This is a recursive function which split every string of the same 
 * 			level in many parts for extract the content.
 * 
 * @param{str} string to parse
 * @return  A tag which contains all tags there is possible to build in the 
 * 			string parameter
*/
Tag demandInTag(std::string str);

#include "../src/util_wo.hpp"

#endif // UTIL_WO_H