#include "../inc/html.h"

HTML::HTML(std::string name,std::vector<Balise> vec) {
    Filename = name;
    b_vec = vec;
}

HTML & HTML::operator=(HTML const& copy) {
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
    sfile.close();
}

HTML::~HTML(){
}

/*
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="author" content="Christopher Spitz">
    <meta name="description" content="Projet 'Festival du Jeu">
    <meta charset="UTF-8">
    <link href="style.css" rel="stylesheet"/>
    <link rel="stylesheet" 
          href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" 
          rel="stylesheet">
    <title>Page du Site </title>
*/