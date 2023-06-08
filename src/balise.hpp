#include "../inc/balise.h"

Balise::Balise(std::string bal, pairvec pv_options, std::vector<Balise> bal_vec,int nb_tab ,int jFb, int jLb, int jLa) {
	named = true;
	bal_str = bal;
	str_in_bal();
	nbtab = nb_tab;
	cds_t.debut_tagF = bloc_balise.length();
	bloc_balise += getFpv2(setOptionsBalise(pv_options,0),jFb,nb_tab);
	cds_t.fin_tagF = bloc_balise.length();
	cds_t.debut_tagL = cds_t.fin_tagF + 1;
	bloc_balise += getLpv2(bal,jLb,jLa,nb_tab);
	cds_t.fin_tagL = bloc_balise.length();
}

Balise::Balise() {
	named = false;
	cds_t.debut_tagF = 0;
	cds_t.fin_tagF = 0;
	cds_t.debut_tagL = 0;
	cds_t.fin_tagL = 0;
}

void Balise::setBal(balise bal) {
	b = bal;
	bal_in_str();
}
void Balise::setBal_with_str(std::string str) {
	bal_str = str;
	str_in_bal();
}

void Balise::bal_in_str() {
	switch(b) {
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
	if(bal_str == "div") 
		b = Div;
	else if(bal_str == "head") 
		b = Head;
	else if(bal_str == "body") 
		b = Body;
	else if(bal_str == "article") 
		b = Article;
	else if(bal_str == "section") 
		b = Section;
	else if(bal_str == "span") 
		b = Span;
}

std::string Balise::setOptionsBalise(pairvec pv, int with_end) {
	std::string head_balise = getBal_in_str();
    for(auto p : pv) {
        head_balise += +" "+p.first+"="+"\""+p.second+"\"";
		pv_o.push_back(p);
	}
	head_balise += (with_end) ? "/" : "";
    return head_balise;
}

std::string Balise::pairvec_in_str() {
	std::string balise_option = "";
    for(auto p : pv_o) 
        balise_option += " "+p.first+"="+"\""+p.second+"\"";
    return balise_option;
}

void Balise::setCoordonnees(int dF, int fF, int dL, int fL) {
	cds_t.debut_tagF = dF;
	cds_t.fin_tagF = fF;
	cds_t.debut_tagL = dL;
	cds_t.fin_tagL = fL;
}

void Balise::AddPreciseCoordonnees(int choice, int plus_value) {
	switch(choice) {
		case 0: cds_t.debut_tagF += plus_value;
		case 1: cds_t.fin_tagF += plus_value;
		case 2: cds_t.debut_tagL += plus_value;
		case 3: cds_t.fin_tagL += plus_value;
		default: 
			break;
	}
}

void Balise::AddCoordonnesWithPreciseValue(int plus_value) {
	cds_t.debut_tagF += plus_value;
	cds_t.fin_tagF += plus_value;
	cds_t.debut_tagL += plus_value;
	cds_t.fin_tagL += plus_value;
}

void Balise::printCoordonnees() {
	std::cout << "debut tagF : " << cds_t.debut_tagF << "fin tagF :" << cds_t.fin_tagF << std::endl;
	std::cout << "debut tagL : " << cds_t.debut_tagL << "fin tagL :" << cds_t.fin_tagL << std::endl;
}

void Balise::add_balisev2(Balise new_bal) {
	std::string blo_nbal = new_bal.getBloc_balise();
	int debut = cds_t.debut_tagL-1;
	if(!named) 
		debut = (debut < 0) ? 0 : cds_t.debut_tagL;
	new_bal.AddCoordonnesWithPreciseValue(debut);
	vec_b.push_back(new_bal);
	bloc_balise.insert(debut,blo_nbal);
	cds_t.debut_tagL += blo_nbal.length();
	cds_t.fin_tagL += blo_nbal.length();
}

Balise::~Balise(){	
}