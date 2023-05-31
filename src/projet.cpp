#include "../inc/util_wo.h"

Balise createDefaultHead() {
	Balise head("head",{},{},0,1);
	return head;
}

Balise createDefaultBody() {
	Balise body{"body",{},{},0,1};
	return body;
}


int main() {
    Balise body = createDefaultBody();

	std::string test_line2 = "article 2p;section 1p";
	std::string test_line = "p 3li;p";
	std::vector<Balise> adds = balise_in_line(test_line2);
	for(auto b : adds) 
		body.add_balise(b);

	std::vector<Balise> vec_html = {body};
    HTML one_html{"../test/test.html",vec_html};
	one_html.addinfile();
	

	

    return 0;
}