#ifndef UTIL_H
#define UTIL_H

#include <unistd.h>
#include <iostream>
#include "util2.h"
#include <fstream>
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
 * @brief
 * @param
 * @return
*/

#include "../src/util.hpp"

#endif // UTIL_H //