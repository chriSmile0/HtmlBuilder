#ifndef UTILWO_H
#define UTILWO_H

#include "html.h"
#include "css.h"

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