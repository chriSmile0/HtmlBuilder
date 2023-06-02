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
    /*Balise body = createDefaultBody();
	std::string test_line6 = "{article}"; // à tester 
	std::string test_line5 = "article {p}";
	std::string test_line4 = "article {div {{p};{p}}}";
	std::string test_line3 = "article {p {span {1li}}}"; // = {récursivité simple}
	std::string test_line2 = "article {p {span}}";
	std::string test_line = "p 3li;p";
	std::vector<Balise> adds = balise_in_linev2(test_line5);
	for(auto b : adds) 
		body.add_balise(b);

	std::vector<Balise> vec_html = {body};
    HTML one_html{"../test/test.html",vec_html};
	one_html.addinfile();


	std::string line = "article {div {p};div {p}}";*/
	/**
	 * = <article>
	 * 		<div>
	 * 			<p></p>
	 *		</div>
	 *		<div>
	 *			<p></p>
	 *		</div>
	 * 	 </article>
	*/

	
	//on pioche article , on balance {p} dans la moulinette 


	std::string test2 = "{article {div {2p}}}";
	Balise o = demand_in_balisev3(test2);
	//on enleve les accolades 
	//puis moulinette de divisions des blocs avec balise_in_line -> split(str,';')
	//puis on récupère la balise parente 
	//on enleve les accolades 
	//... -> same
	//... -> same 
	Balise null{};
	std::vector<Balise> vec_html = {o,null};
    HTML one_html{"../test/test.html",vec_html};
	one_html.addinfile();
    return 0;
}