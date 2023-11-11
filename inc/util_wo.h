#ifndef UTILWO_H
#define UTILWO_H

#include "html.h"

/**
 * @brief	Remove the '{' '}' of the parameter string
 * @param{str}	string to parse
 * @return	the string without '{'/'}'
*/
std::string withoutBracket(std::string str);


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