#ifndef UTILWO_H
#define UTILWO_H

#include "html.h"

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
std::string check_balise(std::string str);

/**
 * @brief
 * @param
 * @return
*/

std::string without_accolade(std::string str);

/**
 * @brief
 * @param
 * @return
*/
std::vector<std::string> split_str_homemade(std::string str, char splitter);

/**
 * @brief
 * @param
 * @return
*/
std::vector<int> split_or_not(std::string str, char splitter);
/**
 * @brief
 * @param
 * @return
*/
Balise demand_in_balisev4(std::string str);

#include "../src/util_wo.hpp"

#endif // UTIL_WO_H