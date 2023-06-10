#include "../inc/css.h"
#include <algorithm>

//Attention car on peut avoir plusieurs classe dans le 
//cadre de l'héritage 
//On pourrais créer cette héritage directement 
//en fonction de la balise du parent 
bool m_class_u_id(option_and_value a, option_and_value b)
{
    if(((a.option == "id") && (b.option == "id")) 
		|| ((a.option == "class") && (b.option == "class")))
		if(a.value == b.value)
			return 1;
	return 0;
}

CSS::CSS(std::string name,std::vector<Balise> vec_balise) {
    Filename = name;
    vec_b = vec_balise;
    //sfile = openFile(Filename);
}

CSS::CSS(CSS const& copy) {
	Filename = copy.Filename;
	vec_b = copy.vec_b;
}

CSS & CSS::operator=(CSS const& copy) {
	Filename = copy.Filename;
	vec_b = copy.vec_b;
	return *this;
}

void CSS::addinfile() {
    sfile = std::fstream(Filename, std::ios::in | std::ios::out | std::ios::trunc);
    //on cherche ici les classes de bases à mettre 
	//Pour chaque balise on doit créer une section de style dans le .css
	
	options_and_tags to;
	std::string tag = "";
	std::string opt = "";
	for(auto bal : vec_b) {
		to = add_in_rec(bal);
		tag += to.tags;
		opt += to.options;
	}
	std::cout << tag << std::endl;
	std::cout << opt << std::endl;

	std::vector<std::string> all_tags = all_tags_invec(tag);
	std::sort(all_tags.begin(),all_tags.end());
	for(auto tag : all_tags)
		std::cout << tag << std::endl;
    all_tags.erase(std::unique(all_tags.begin(), all_tags.end()),all_tags.end());
	for(auto tag : all_tags)
		std::cout << tag << std::endl;
	std::vector<option_and_value> all_opts = all_opts_invec(opt);
    all_opts.erase(std::unique(all_opts.begin(), all_opts.end(),m_class_u_id)
		,all_opts.end());
	



	for(auto b : all_tags) {
		sfile << b + " {\n}\n";
	}
	for(auto ov : all_opts) {
		if(ov.option == "class")
			sfile << "."+truncate_option(ov.value)+" {\n}\n";
		else if(ov.option == "id") {
			sfile << "#"+truncate_option(ov.value)+" {\n}\n";
		}
	}
	sfile.close();
}

options_and_tags CSS::add_in_rec(Balise b) {
	if(vec_b.size()==0)
		return {"",""};
	std::string tags = (b.getBal_in_str() != "") ? (b.getBal_in_str()+",") : "";
	std::string options = b.pairvec_in_str()+";";
	int sizeBvec = b.getVecBalSize();
	//Voir ici pour récuperer le niveau de tab pour pouvoir
	//faire l'héritage directement pour le css 
	for(int i = 0 ; i < sizeBvec;i++) {
		tags += add_in_rec(b.getBalWithIndex(i)).tags;
		options += add_in_rec(b.getBalWithIndex(i)).options;
	}
	options_and_tags ot = {tags,options};
	return ot;
}

std::vector<std::string> CSS::all_tags_invec(std::string tags) {
	int i = 0;
	int length = tags.length();
	int begin = (!length) ? 1 : 0; 
	std::vector<std::string> save_tags;
	std::string word = "";
	for(int i = 0 ; i < length; i++) {
		if(tags[i] == ',') {
			i++;
			save_tags.push_back(word);
			word = "";
		}
		else if(tags[i] == '\n')
			break;
		word += tags[i];
	}
	return save_tags;
}

std::vector<option_and_value> CSS::all_opts_invec(std::string opts) {
	int i = 0;
	int length = opts.length();
	int begin = (!length) ? 1 : 0; 
	std::vector<option_and_value> save_o_a_v;
	std::string value = "";
	std::string option = "";
	for(int i = 2 ; i < length; i++) {
		if(opts[i]=='=') {
			begin = 3;
			i++;
		}
		if(begin == 3)
			value += opts[i];
		else 
			option += opts[i];
		if((opts[i] == ';') && (opts[i+1] != ';')){
			i++;
			save_o_a_v.push_back({option,value});
			option = "";
			value = "";
			begin = 1;
		}
		else if(opts[i] == '\n')
			break;
	}
	return save_o_a_v;
}

std::string CSS::truncate_option(std::string option) {
	//option[0] = '\0'; casse le fichier -> fonctionne pour du terminal
	//option[0] = '\0';
	//option[5] = '\0'; casse le fichier -> fait bien un trou dans la chaine
	int taille = option.length()-3;
	std::string rtn = option.substr(1,taille);
	//on suppr les " qui entoure notre option et le ';' si il est présent
	return rtn;
}


CSS::~CSS() {
}