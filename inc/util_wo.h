#ifndef UTILWO_H
#define UTILWO_H

#include "html.h"
#include "css.h"

/**
 * @brief	Extraire la balise d'une chaine comme {  p }
 * 			ce qui donne 'p'
 * @param{str}	la chaine à parser
 * @return	la chaine en entrée ou la balise si il y'a des choses à parser
*/
std::string extract_balise(std::string str);

/**
 * @brief	Extraire un entier d'une chaine comme 2p 
 * 			ce qui donne '2'
 * @param{str} la chaine à parser
 * @return	le digit correspondant ou "0" si pas de digit dans la chaine
 */
std::string extract_digit(std::string str);

/**
 * @brief	Renvoyer la balise d'entrée si elle correspond à une balise reconnue
 * 			Sinon renvoyer chaine vide 
 * @param{str}	la chaine en entrée	
 * @return	la chaine en entrée ou une chaine vide
*/
std::string check_balise(std::string str);

/**
 * @brief	Sauter les accolades et les espaces blancs si nécessaire 
 * 			pour connaître la suite de la chaine
 * @param{str}	la chaine à parser
 * @return	l'entier qui représente le nombre de sauts jusqu'au début de la suite
*/
int jump_to_next_balise(std::string str);

/**
 * @brief	Il s'agit là d'effacer de la chaine les '{'/'}' de la chaine en 
 * 			entrée
 * @param{str}	la chaine à parser
 * @return	la chaine sans les '{'/'}' à condition que ces caractères soit présent
*/
std::string without_accolade(std::string str);

/**
 * @brief	Création d'un split maison afin de split avec un caractère précis
 * 			mais des chaines qui sont au même niveau c'est à dire qui ont le
 * 			même parent
 * @param{str}	la chaine à découper
 * @param{spliiter}	le caractère de split
 * @return	la chaine découper en plusieurs parties dans un vecteur
*/
std::vector<std::string> split_str_homemade(std::string str, char splitter);

/**
 * @brief	Savoir si on peut couper la chaine en entrée avec le caractère 
 * 			demandé
 * @param{str}	la chaine à découper
 * @param{splitter}	le caractère de split
 * @return	un vecteur d'index qui signifie les endroits où l'on coupe la chaine
*/
std::vector<int> split_or_not(std::string str, char splitter);

/**
 * @brief	Le corps même du projet.
 * 			Il s'agit là d'une fonction récursive qui découpe chaque chaine de 
 * 			même niveau en plusieurs parties afin d'en extraire de manière 
 * 			récursive le contenu.
 * 
 * @param{str} la chaine à parser
 * @return	Une balise qui contient toutes les balises qu'il est possible de 
 * 			construire dans la chaine passer paramètre.
*/
Balise demand_in_balisev4(std::string str);

#include "../src/util_wo.hpp"

#endif // UTIL_WO_H