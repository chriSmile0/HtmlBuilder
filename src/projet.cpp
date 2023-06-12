#include "../inc/util_wo.h"
#include <getopt.h>

int main(int argc, char *argv[]) {
	static struct option options[] = {
		{"f", required_argument,NULL,'f'},
		{"l", required_argument,NULL,'l'},
		{"c", optional_argument,NULL,'c'},
		{"d", optional_argument,NULL,'d'},
		{NULL, 0, NULL,0}
	};

	std::string save_option = "";
	int opt, index = 0;
	char flag = '-'; 
	char flag_cs_mf = 'c';
	int cpt = 0;
	while((opt = getopt_long(argc, argv, "flc", options, &index)) != -1) {
		cpt++;
		switch(opt) {
			case 'f': save_option = argv[2];
				flag = 'f';
				if(save_option.substr(save_option.find_last_of(".") + 1) == "html")
					flag_cs_mf = 'm';
				break;
			case 'l': save_option = argv[2];
				flag = 'l';
				if(save_option.substr(save_option.find_last_of(".") + 1) == "html")
					flag_cs_mf = 'm';
				break;
			case 'c': flag = 'c';
				if(argc == 3)
					flag_cs_mf = 'm';
				break;
			case 'd': flag = 'd';
				if(argc == 3)
					flag_cs_mf = 'm';
				break;
			default: 
				return EXIT_FAILURE;
				break;
		}
	}

	std::string construction = "";
	std::string modification = "";
	std::string recup_line = "";
	Balise out;
	if(flag == 'c') {
		std::cout << "***Command Line Process***" << std::endl;
		int goon = 1;
		while(goon) {
			getline(std::cin, recup_line);
			if(recup_line == "stop")
				goon = 0;
			construction += recup_line;
			if(goon == 1)
				construction += ";";
		}
		construction = construction.substr(0,construction.length()-5);
	}
	else if(flag == 'f') {
		std::cout << "***Read File Process***" << std::endl;
		std::ifstream readfile(save_option);
		while(getline(readfile,recup_line))
			construction += recup_line+";";
		readfile.close();
		construction = construction.substr(0,construction.length()-1);
	}
	else if(flag == 'l') {
		std::cout << "***Input One Line Process***" << std::endl;
		construction = save_option;
	}
	
	std::string test0 = "{article div}";					// ok V5
	std::string test1 = "{article {div p}}";				// ok V5
	std::string test2 = "{article;section}";				// ok V5
	std::string test3 = "{2article;2section}";				// ok V5
	std::string test4 = "{article;section;p}";				// ok V5
	std::string test5 = "{article {div p};article {div p}}";// ok V5
	std::string test6 = "{article {div;p {span li}}}";		// n_ok/ok V5
	//On pourrais forcer le fait de forcer le li comme un inline pour ne pas
	//casser le inline du span
	std::string test7 = "{article {div;p span}}";			// ok V5
	std::string testREADME = "{p {1div {{p};{p}}}}";		// ok V5
	std::string testAltREADME = "{p {1div {p;p}}}";			// ok V5
	std::string testAltREADME2 = "{p {2div {p;p}}}";		// ok V5
	std::string testAltREADMEn = "{2section;2article}";		// ok V5

	std::cout << flag_cs_mf << std::endl;
	if(flag_cs_mf == 'c') { 
		if((flag != 'd') && ((construction == "stop") || (construction == ""))) 
			std::cout << "***Nothing to Build***" << std::endl;
		else {
			std::cout << "***Possibility to Build HTML***" << std::endl;
			std::cout << "***BUILD IN PROGRESS***" << std::endl;
			if(flag != 'd') 
				out = demand_in_balisev4(construction,0);
			else 
				out = demand_in_balisev4(test5,0);
		}
	}
	else {
		modification = construction;
		if((flag != 'd') && ((modification == "stop") || (modification == ""))) 
			std::cout << "***Nothing to Modify***" << std::endl;
		else {
			std::cout << "***Possibility to Modify HTML***" << std::endl;
			std::cout << "***Modify IN PROGRESS***" << std::endl;
			/*if(flag != 'd') 
				out = demand_in_balisev4(construction,0);
			else 
				out = demand_in_balisev4(test5,0);*/
			
		}
	}

	std::vector<Balise> vec_html = {out};
    HTML one_html{"../test/test.html",vec_html};
	//CSS on_css{"../test/test.css",vec_html};
	one_html.addinfile();
	//on_css.addinfile();

	std::cout << extract_balise("p paragraphe") << std::endl;
	for(auto line : parseLine("coucou;c'estmoi",';'))
		std::cout << line << std::endl;

	std::vector<modif_struct> contenu = extractLineContent("1p paragraphe");
	std::cout << contenu.at(0).contenu << std::endl;

	std::fstream file("../test2.html",std::ios::in | std::ios::out);
	fileModification(file,"1body bodybal");
    return 0;
}