#include "../inc/html.h"

HTML::HTML(std::string name,std::vector<Balise> vec) {
    Filename = name;
    b_vec = vec;
}

HTML& HTML::operator=(HTML const& copy) {
	Filename = copy.Filename;
	b_vec = copy.b_vec;
	return *this;
}

HTML::HTML(HTML const& copy) {
	Filename = copy.Filename;
	b_vec = copy.b_vec;
}


void HTML::addinfile() {
    sfile = std::fstream(Filename, std::ios::in | std::ios::out | std::ios::trunc);
    setFpHtml();
    for(auto bal : b_vec)
        sfile << bal.getBloc_balise();
    setLpHtml();
    insertLineInFile(sfile,"paragraphe",55);
    sfile.close();
}

HTML::~HTML(){
}