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
	std::string tag;
	int index;
} tag_and_index;

typedef struct {
	std::string option;
	std::string value;
} option_and_value;

typedef struct {
	int begin_tagF;
	int end_tagF;
	int begin_tagL;
	int end_tagL;
} coordinates_tag;

typedef struct {
	int index;
	std::string tag;
	std::string content;
} modif_struct;

typedef struct {
	int idx;
	int nb_tabs;
} idx_tabs;


using vecOV = std::vector<option_and_value>;

typedef struct {
	std::string tag;
	std::vector<option_and_value> vec_ov;
} Tag_opts;

using vecTagOpts = std::vector<Tag_opts>;

typedef struct {
	std::string str;
	vecOV v;
	std::string tag;
} line_options;



/**
 * @brief	Write a line in the In file
 * @param{line} the line to write in file
 * @param{f}	In file
 * @return 
*/
inline void writeLine(std::string line, std::fstream f) {f << line;}

/**
 * @brief	Write all lines of a file in a string vector
 * @param{f}	file to read
 * @return	All lines of the file
*/
std::vector<std::string> readLines(std::fstream f);

/**
 * @brief	Re writing of the close file function
 * @param{f}	file to close
 * @return
*/
inline void closeFile(std::fstream f) {f.close();}

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
 * @brief	Function which allows to write the first part of a tag
 * @param{s}	tag to create
 * @param{jump}	Jump before the tag ?
 * @return	the string which contains the tag opener
*/
std::string getFpv2(std::string s, int jump, int nb_tab);

/**
 * @brief	Fonction qui permet d'écrire le second bloc balise d'une balise
 * @brief 	Function which allows to write the last part of a tag
 * @param{s}	tag to create
 * @param{jb}	Jump before the tag ?
 * @param{ja}	Jump after the tag ?
 * @return	the stirng which contains the tag closer
*/
std::string getLpv2(std::string s, int jb, int ja, int nb_tab);

/**
 * @brief	Extract the tag of the string like "{ p }" -> 'p'
 * @param{str}	string to parse
 * @return 	the string in parameter or the tag if there is things to parse
*/
std::string extractTag(std::string str);

/**
 * @brief	Extract an integer of a string like "2p" -> '2'
 * @param{str} string to parse
 * @return 	the corresponding digit or "0" if not digit in the string
 */
std::string extractDigit(std::string str);

/**
 * @brief 	Return the tag in string if he corresponds to a recognize tag.
 * 			Else return a empty string
 * @param{str}	The string In
 * @return	The string In or empty string
*/
std::string checkTag(std::string str);

/**
 * @brief	Jump the '{''}' and the spaces if it's necessary for known the 
 * 			next part of the string
 * @param{str}	string to parse
 * @return 	The integer which represent the number of jumps to reach the 
 * 			following
*/
int jumpToNextTag(std::string str);

/**
 * @brief	Grow up target file
 * @param{f}	target file
 * @return
*/
void growUpFile(std::fstream& f, int extend_size);

/**
 * @brief	Insert a line in the file
 * @param{f}	target file
 * @param{str}	string to insert
 * @param{index}	index of the start of the string
 * @return
*/
void insertLineInFile(std::fstream& f, std::string str, int index);

/**
 * @brief		Update/Insert a line in the file
 * @param{f}	target file
 * @param{l_o}	the line options
 * @param{index}	index of the start of the string (0 ?)
 * @return
*/
void updateBlockStyle(std::string file, vecOV v_o, int index); // USELESS INDEX -> ALWAYS 0 

/**
 * @brief	Split a string with a splitter
 * 			
 * @param{str}	string to parse
 * @param{splitter} the splitter 
 * @return	a vector of strings
*/
std::vector<std::string> parseLine(std::string str);

/**
 * @brief	Extract of a split string differents informations like as the tag
 * 			, the content or the tag index in the target page
 * 
 * @param{str}	The string to extract lines 
 * @param{mode} The utilisation mode {html(1),css(2),update_css(3)} for example
 * @return 	A vector of modif_struct, a struct which contains two strings which 
 * 			was the content and the tag.
*/
std::vector<modif_struct> extractLineContent(std::string str, char mode);

/**
 * @brief	Search the index in a file of a tag in function of this name and a 
 * 			number
 * 
 * @param{f}		In file to research
 * @param{num}		The n tag to correspond at this name
 * @param{balise}	The research tag
 * @return The index for the insertion content and a number of tabs
*/
idx_tabs searchTagInFile(std::fstream& f, int num, std::string tag);

/**
 * @brief	Search a token in a string
 * 
 * @param{str}	The stirng to search the token
 * @param{token}	The token
 * @return  A digit who is the index of start of the token in the string
*/
int inLine(std::string str, std::string token);

/**
 * @brief	Insert a string in a file like as content of a tag. For example
 * 			the content of a 'p' tag.
 * 
 * @param{f}	File to modify
 * @param{str}	The string to insert in file
 * @return	
*/
void fileModification(std::fstream& f, std::string str);

/**
 * @brief	Update and insert the css file for example for seletor 'p'
 * 			old margin is 10px, now it's 20px
 * 			If a priority is here just replace the line by the new line
 * 			Or insert at the of the block.
 * 
 * @param{f_inout}	File to modify
 * @param{str}		The string to insert or update in file
 * @return	
*/
void fileModificationCss(std::string f_inout , std::string str);

/**
 * @brief	Like 'searchBaliseInFile' but this time we insert the attributes in 
 * 			the tag not in the content. 
 * @param{f}		File to research the tag
 * @param{num}		The n tag
 * @param{balise}	The tag to research
 * @return 	Not need to return a number of tabs. This time we return the index
 * 			of the start of the insert -> <p> -> <p{INSERT}>
*/
int searchTagInFileForStyle(std::fstream& f, int num, std::string tag);

/**
 * @brief	Parse a line 'id=Id|class=Class for to adds as attributes of a tag
 * 
 * @param{balise}	The target tag
 * @param{str}		string to analyze 
 * @param{mode}		The utilisation mode {html(1),css(2),update_css(3)} for example
 * @return 	A struct which contains the string to insert and one vector of 
 * 			option_and_value who is a struct who associate an option to one 
 * 			value
*/
line_options lineInAttributLine(std::string tag, std::string str, char mode);


/**
 * @brief	Insert of a CSS field -> a valid option in the css language
 * 
 * @param{fout}	The css file where the insert is make
 * @param{vecs} All options and values what contains launcher options
 * @return
*/
void insertLineInFileCss(std::string f_in, std::ofstream &fout,
							std::vector<option_and_value> vecs);

/**
 * @brief	Create tree of inheritance (like demandeInTag)
 * @param{f} The html file to analyze
 * @return	tree of this shape -> {0body,1p,1p,0body} for this code 
 			<body><p></p></body>
*/
std::vector<std::string> treeOfHtml(std::fstream& f);

/**
 * @brief	Determine the depth of a tag in the html page 
 * 			The tree is initialize by the function treeOfHtml who 
 * 			list the tag in the html file with the associate level 
 * 			of inheritance in the file
 * @param{tree}	The tree create with treeOfHtml function
 * @param{level} 0 generally 
 * @return 'body>div>p' for an example
*/
std::string depthMaxTree(std::vector<std::string> tree, int level);

/**
 * @brief	For differents type of vector it's possible to search an element
 * 			for known if it's present or not
 * @param{vec}	A vector of type T 
 * @param{token}The token to search 
 * @return True or False
*/

template<typename T>
bool inVector(std::vector<T> vec, T token);

/**
 * @brief	Search a string in the strings of vector of strings
 * @param{vec} The vector to search the substring
 * @param{token} The research token
 * @return True or False
*/
bool inSubVector(std::vector<std::string> vec, std::string token);

/**
 * @brief	Search a string in the strings of vector of strings
 * @param{vec} The vector to search the substring
 * @param{token} The research token
 * @return The index of token in vector
*/
int inIndexSubVector(std::vector<std::string> vec, std::string token);

/**
 * @brief	Delete duplicate item where the token is.
 * @param{vec} The vector to search the substring
 * @param{token} The research token
 * @return The vector with token appears once time
*/
std::vector<std::string> uniqueTokenInVector(std::vector<std::string> vec,
												std::string token);

//************************* CSS **********************//
/**
 * @brief	Detect the presence of many similar ID for two differents tags
 * 			and write just one time this tag.
 * 			In future version the inheritance change this behavior
 * @param{a,b}	Compare a and b struct
 * @return True for delete False for ignore 
*/

bool multiClassUniqueId(option_and_value a, option_and_value b)
{
    if(((a.option == "id") && (b.option == "id")) 
		|| ((a.option == "class") && (b.option == "class")))
		if(a.value == b.value) 
			return 1;
	return 0;
}

/**
 * @brief
 * @param{a,b}
 * @return 
*/
inline bool uniqueTag(std::string a, std::string b) {return (a == b);}

/**
 * @brief	Sort the strings a and b 
 * @param{a,b}	Compare a and b strings
 * @return True for sort False for ignore 
*/

inline bool sortStr(std::string a, std::string b) {return (a <= b) ? 1 : 0;}

/**
 * @brief	Sort Css tags a and b  
 * @param{a,b}	Compare a and b csstags
 * @return True for sort False for ignore 
*/

bool sortCssTags(std::string a, std::string b) {
	if(a == "html") {
		if (b == "*")
			return 0;
		return 1;
	}
	if(a == "body") {
		if(b == "article")
			return 1;
		else 
			if (a <= b)
				return 0;
	}
	if(a == "header") {
		if(b == "article")
			return 1;
		if(b == "aside")
			return 1;
		if(b == "div")
			return 1;
		if(b == "footer") 
			return 1;
		else
			if(a <= b)
				return 0;
	}
	if(b == "footer") 
		if((a == "p") || (a == "section") || (a == "span"))
			return 1;
	return 0;
}

/**
 * @brief	Unique the tree
 * @param{a,b}	Compare a and b struct
 * @return True for sort False for ignore 
*/
bool uniqueHtmlTree(std::string a, std::string b) {
	int level_a = stoi(extractDigit(a));
	int level_b = stoi(extractDigit(b));
	if(a == b)
		return 1;
	return 0;
}

/**
 * @brief	Sort the struct a and b 
 * @param{a,b}	Compare a and b struct
 * @return True for sort False for ignore 
*/

inline bool sortOv(option_and_value a, option_and_value b) {return ((a.option < b.option) && (a.value < b.option)) ? 1 : 0;}

#include "../src/util.hpp"

#endif // UTIL_H //