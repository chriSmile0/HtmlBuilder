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
	Balise j{"article",0,1,0};
	Balise k{"section",0,1,0};
	Balise l{"p",0,1,0};
	
	
	Balise g{};
	g.printCoordonnees();
	g.add_balisev2(j);
	g.printCoordonnees();
	g.add_balisev2(k);
	g.printCoordonnees();
	g.add_balisev2(l);
	g.printCoordonnees();

	std::string test1 = "{article div}";					// ok 
	std::string test2 = "{article {div p}}";				// ok 
	std::string test3 = "{article;section}";				// ok
	std::string test4 = "{article;section;p}";				// ok
	std::string test5 = "{article {div p};article {div p}}";// ok
	std::string test6 = "{article {div;p {span li}}}";		// ?
	Balise in = demand_in_balisev4(test6);

	std::vector<Balise> vec_html = {in};
    HTML one_html{"../test/test.html",vec_html};
	one_html.addinfile();

    return 0;
}