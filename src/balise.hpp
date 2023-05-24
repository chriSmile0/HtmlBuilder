#include "../inc/balise.h"

Balise::Balise(balise bal,pairvec pv_options,std::vector<Balise> bal_vec, int with_end) {
	b = bal;
	bal_in_str();
	vec_b = bal_vec;
	bloc_balise += getFp(setOptionsBalise(pv_options,with_end));
	bloc_balise += (!with_end) ? getLp(getBal_in_str()) : "\n";
}
Balise::Balise(std::string bal,pairvec pv_options,std::vector<Balise> bal_vec, int with_end) {
	bal_str = bal;
	str_in_bal();
	vec_b = bal_vec;
	bloc_balise += getFp(setOptionsBalise(pv_options,with_end));
	bloc_balise += (!with_end) ? getLp(getBal_in_str()) : "\n";
}


void Balise::setBal(balise bal) {
	b = bal;
	bal_in_str();
	//Setup_str
}
void Balise::setBal_with_str(std::string str) {
	bal_str = str;
	str_in_bal();
	//setup_bal
}

void Balise::bal_in_str() {
	switch (b) {
		case Head: bal_str = "head";
			break;
		case Body: bal_str = "body";
			break;
		case Div: bal_str = "div";
			break;
		case Article: bal_str = "article";
			break;
		case Section: bal_str = "section";
			break;
		case Span: bal_str = "span";
			break;
		default:
			break;
	}

}

void Balise::str_in_bal() {
	if (bal_str == "div") 
		b = Div;
	else if (bal_str == "head") 
		b = Head;
	else if (bal_str == "body") 
		b = Body;
	else if (bal_str == "article") 
		b = Article;
	else if (bal_str == "section") 
		b = Section;
	else if (bal_str == "span") 
		b = Span;
}

std::string Balise::setOptionsBalise(pairvec pv, int with_end) {
	//pareil que pour l'head dans html 
	std::string head_balise = getBal_in_str();
	//pv_o = pv;
	//std::cout << pv.at(0).first << std::endl;
    for (auto p : pv) {
        head_balise += +" "+p.first+"="+"\""+p.second+"\"";
		pv_o.push_back(p);
	}
	head_balise += (with_end) ? "/" : "";
	std::cout << head_balise << std::endl;
    return head_balise;
}

void Balise::add_balise(Balise new_bal) {
	std::string blo_nbal = new_bal.getBloc_balise();
	vec_b.push_back(new_bal); 
	bloc_balise.insert(lastendline(),blo_nbal);
}

int Balise::lastendline() {
	int depart = bloc_balise.length()-2;
	for(; depart > -1 ; depart--)
		if(bloc_balise[depart]=='\n')
			return depart+1;
	return 0;
}

std::string Balise::pairvec_in_str() {
	std::string balise_option = "";
    for (auto p : pv_o) 
        balise_option += " "+p.first+"="+"\""+p.second+"\"";
    return balise_option;
}

Balise::~Balise(){	
}
