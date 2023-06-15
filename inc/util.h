#ifndef UTIL_H
#define UTIL_H

#include <unistd.h>
#include <iostream>
#include "util2.h"
#include <fstream>
#include <algorithm>
#include <vector>

/** LOREM IPSUM
[32] Sed ut perspiciatis, unde omnis iste natus error sit voluptatem 
accusantium doloremque laudantium, totam rem aperiam eaque ipsa, 
quae ab illo inventore veritatis et quasi architecto beatae vitae 
dicta sunt, explicabo. Nemo enim ipsam voluptatem, quia voluptas 
sit, aspernatur aut odit aut fugit, sed quia consequuntur magni 
dolores eos, qui ratione voluptatem sequi nesciunt, neque porro 
quisquam est, qui dolorem ipsum, quia dolor sit, amet, consectetur
, adipisci velit, sed quia non numquam eius modi tempora incidunt, 
ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad 
minima veniam, quis nostrum exercitationem ullam corporis suscipit 
laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem 
vel eum iure reprehenderit, qui in ea voluptate velit esse, quam 
nihil molestiae consequatur, vel illum, qui dolorem eum fugiat, 
quo voluptas nulla pariatur? [33] At vero eos et accusamus et iusto 
odio dignissimos ducimus, qui blanditiis praesentium voluptatum 
deleniti atque corrupti, quos dolores et quas molestias excepturi 
sint, obcaecati cupiditate non provident, similique sunt in culpa, 
qui officia deserunt mollitia animi, id est laborum et dolorum fuga.
Et harum quidem rerum facilis est et expedita distinctio. Nam 
libero tempore, cum soluta nobis est eligendi optio, cumque nihil 
impedit, quo minus id, quod maxime placeat, facere possimus, omnis 
voluptas assumenda est, omnis dolor repellendus. Temporibus autem 
quibusdam et aut officiis debitis aut rerum necessitatibus saepe 
eveniet, ut et voluptates repudiandae sint et molestiae non 
recusandae. Itaque earum rerum hic tenetur a sapiente delectus, 
ut aut reiciendis voluptatibus maiores alias consequatur 
aut perferendis doloribus asperiores repellat.
*/

std::string lorem_ipsum = "lorem ipsum";

using pair = std::pair<std::string, std::string>;
using pairvec = std::vector<pair>;


typedef struct {
	std::string tags;
	std::string options;
} options_and_tags;

typedef struct {
	std::string option;
	std::string value;
} option_and_value;

typedef struct {
	int debut_tagF;
	int fin_tagF;
	int debut_tagL;
	int fin_tagL;
} coordonnees_tag;

typedef struct {
	int index;
	std::string balise;
	std::string contenu;
} modif_struct;

typedef struct {
	int idx;
	int nb_tabs;
} idx_tabs;

using vecOV = std::vector<option_and_value>;

typedef struct {
	std::string str;
	vecOV v;
} line_options;



/*enum balise {Head,Body,Section,Article,Div,Span,Footer,Img,

				h1,h2,h3,h4,h5,h6,a,br,pre,hr,p,button,form,textarea,
				table,th,tr,td,caption,colgroup,col,thead,tbody,tfoot,
				ul,li,ol,dt,dd,dl,iframe,Link,meta};*/
//enum bloc {address,article,aside,blockquote,canvas,dd,div,dl,dt,fieldset,figcaption,figure,footer,form,h1,h2,h3,h4,h5,h6,header,hr,li,main,nav,noscript,ol,p,pre,section,table,tfoot,ul,video};
//enum inlin {a,abbr,acronym,b,bdo,big,br,button,cite,code,dfn,em,i,img,input,kbd,label,map,object,output,q,samp,script,select,small,span,strong,sub,sup,textarea,time,tt,var};


/**
 * @brief	Ecriture d'une ligne ligne dans le fichier en entrée
 * @param{line} la ligne à écrire dans le fichier
 * @param{f}	le fichier en entrée
 * @return
*/
inline void writeLine(std::string line, std::fstream f) {f << line;}

/**
 * @brief	Écrit toutes les lignes d'un fichier dans un vecteur
 * 			de chaine
 * @param{f}	le fichier à lire
 * @return	L'ensemble des lignes du fichier
*/
std::vector<std::string> readLines(std::fstream f);

/**
 * @brief	Réecriture de la fermeture de la fonction close d'un fichier
 * @param{f}	le fichier à cloturer
 * @return
*/
inline void closeFile(std::fstream f) {f.close();}

/**
 * @brief	Fonction qui permet d'écrire le premier bloc balise d'une balise
 * @param{s}	la balise à créer
 * @param{jump}	Jump avant la balise ?
 * @return	la chaine qui contient la balise ouvrante
*/
std::string getFpv2(std::string s, int jump, int nb_tab);

/**
 * @brief	Fonction qui permet d'écrire le second bloc balise d'une balise
 * @param{s}	la balise à créer
 * @param{jb}	Jump avant la balise ?
 * @param{ja}	Jump après la balise ?
 * @return	la chaine qui contient la balise fermante
*/
std::string getLpv2(std::string s, int jb, int ja, int nb_tab);


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
 * @brief	Agrandir le fichier cible 
 * @param{f}	le fichier cible
 * @return
*/
void growUpFile(std::fstream& f, int extend_size);

/**
 * @brief	Insérer une ligne dans un fichier
 * @param{f}	Le fichier cible
 * @param{str}	La chaine à insérer
 * @param{index}	L'index de d"part de la chaine
 * @return
*/
void insertLineInFile(std::fstream& f, std::string str, int index);

/**
 * @brief
 * @param
 * @return
*/
std::vector<std::string> parseLine(std::string str);

/**
 * @brief
 * @param
 * @return
*/
std::vector<modif_struct> extractLineContent(std::string str);

/**
 * @brief
 * @param
 * @return L'index précis pour l'insertion du contenu 
*/
idx_tabs searchBaliseInFile(std::fstream& f, int num, std::string balise);


/**
 * @brief
 * @param
 * @return
*/
int inLine(std::string str, std::string token);

/**
 * @brief
 * @param
 * @return
*/
void fileModification(std::fstream& f, std::string str);


/**
 * @brief
 * @param
 * @return
*/
line_options lineInAttributLine(std::string balise, std::string str);


/**
 * @brief
 * @param
 * @return
*/
void insertLineInFileCss(std::string fout, std::vector<option_and_value> vecs);

/**
 * @brief
 * @param
 * @return
*/


//************************* CSS **********************//
bool m_class_u_id(option_and_value a, option_and_value b)
{
    if(((a.option == "id") && (b.option == "id")) 
		|| ((a.option == "class") && (b.option == "class")))
		if(a.value == b.value)
			return 1;
	return 0;
}

bool sort_ov(option_and_value a, option_and_value b)
{
	if((a.option < b.option) && (a.value < b.option))
		return 1;
	return 0;
}

#include "../src/util.hpp"

#endif // UTIL_H //