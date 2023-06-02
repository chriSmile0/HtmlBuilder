#ifndef UTILWO_H
#define UTILWO_H

#include "html.h"

/**
 * @brief
 * @param
 * @return
*/
std::vector<std::string> split_str(std::string str, char split);

/**
 * @brief
 * @param
 * @return
*/
std::string extract_balise(std::string str);

/**
 * @brief
 * @param
 * @return
*/
std::string extract_digit(std::string str);

/**
 * @brief
 * @param
 * @return
*/
std::string check_balise(std::string);

/**
 * @brief
 * @param
 * @return
*/

Balise demand_in_balise(std::string str);

Balise demand_in_balisev2(std::string str);

std::string without_accolade(std::string str);

Balise demand_in_balisev3(std::string str);



#include "../src/util_wo.hpp"

#endif // UTIL_WO_H