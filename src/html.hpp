#include "../inc/html.h"

HTML::HTML(std::string name,std::vector<Tag> vec) {
    Filename = name;
    t_vec = vec;
}

HTML& HTML::operator=(HTML const& copy) {
	Filename = copy.Filename;
	t_vec = copy.t_vec;
	return *this;
}

HTML::HTML(HTML const& copy) {
	Filename = copy.Filename;
	t_vec = copy.t_vec;
}


void HTML::addInFile() {
    sfile = std::fstream(Filename, std::ios::in | std::ios::out | std::ios::trunc);
    setFpHtml();
    for(auto tag : t_vec)
        sfile << tag.getBlockTag();
    setLpHtml();
    sfile.close();
}

HTML::~HTML(){
}