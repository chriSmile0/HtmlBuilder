#include "../inc/util_wo.h"
#include <getopt.h>

int main(int argc, char *argv[]) {
	static struct option options[] = {
		{"f",required_argument,NULL,'f'},
		{"l",required_argument,NULL,'l'},
		{"c",optional_argument,NULL,'c'},
		{"d",optional_argument,NULL,'d'},
		{"sy",optional_argument,NULL,'y'},
		{"ts",optional_argument,NULL,'s'},
		{"mf",optional_argument,NULL,'m'},
		{NULL, 0, NULL,0}
	};

	std::string save_option = "";
	std::string out_opt = "";
	int opt, index = 0;
	char flag = '-'; 
	char flag_cs_mf_sy = 'c';
	char flag_mf_s = '-';
	int cpt = 0;
	std::cout << "argc : " << argc << std::endl;
	while((opt = getopt_long(argc, argv, "sym:f:l:cd", options, &index)) != -1) {
		cpt++;
		switch(opt) {
			case 'f': 
				std::cout << "f " << std::endl;
				flag = 'f';
				if(flag_cs_mf_sy != '-') {
					save_option = argv[optind];
					//std::cout << "optarg : " << argv[optind] << std::endl;
					if(flag_cs_mf_sy != 's') {
						out_opt = argv[optind+1];
						if(out_opt.substr(out_opt.find_last_of(".")+1)=="html")
							flag_mf_s = 'm';
					}
				}
				break;
			case 'l': 
				std::cout << "l " << std::endl;
				flag = 'l';
				if(flag_cs_mf_sy != '-') {
					save_option = argv[optind];
					//std::cout << "optarg : " << argv[optind] << std::endl;
					if(flag_cs_mf_sy != 's') {
						out_opt = argv[optind+1];
						if(out_opt.substr(out_opt.find_last_of(".")+1)=="html")
							flag_mf_s = 'm';
					}
				}
				break;
			case 'c': flag = 'c';
				std::cout << "c" << std::endl;
				if(flag_cs_mf_sy != '-') {
					if(argc-optind >= 1) {
						std::cout << "passage ici" << std::endl;
						flag_mf_s = 'm';
						out_opt = argv[optind];
						if(out_opt.substr(out_opt.find_last_of(".")+1)=="html")
							save_option = out_opt;
						out_opt = "";
					}
					else if(argc==optind == 1) {
						flag_mf_s = 'm';
						save_option = "../test/test.html";
					}
				}
				break;
			case 'd': flag = 'd';
				std::cout << "d " << std::endl;
				if(flag_cs_mf_sy != '-') {
					if(argc-optind == 0) {
						std::cout << "sans param" << std::endl;
						flag_mf_s = 'm';
						save_option = "../test/test.html";
					}
					else if(argc-optind == 1) {
						std::cout << "avec param" << std::endl;
						flag_mf_s = 'm';
						save_option = argv[optind];
					}
				}
				break;
			/*case 's': flag = 's';
				std::cout << "s " << std::endl;
				if(argc >= 3) {
					flag_cs_mf = 'm';
					save_option = "../test2.html";
					if(argc == 4) {
						out_opt = "../test2style.css"; //-> V2-3
						flag_mf_s = 's';
					}
				}
				break;*/
			case 's'://Construction
				std::cout << "s " << std::endl;
				flag = 's';
				flag_cs_mf_sy = 's';
				break;
			case 'y'://Style
				std::cout << "y " << std::endl;
				flag = 'y';
				flag_cs_mf_sy = 'y';
				break;
			case 'm'://Modification
				std::cout << "m " << std::endl;
				flag = 'm';
				flag_cs_mf_sy = 'm';
				break;
			default: 
				return EXIT_FAILURE;
				break;
		}
	}

	if((flag == 's') || (flag == 'y') || (flag == 'm')) {
		std::cerr << "Error minimum 2 options " << std::endl;
		return 1;
	}

	std::cout << "s_opt: " << save_option << " out_opt: " << out_opt << std::endl;

	std::string construction = "";
	std::string modification = "";
	std::string recup_line = "";


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
		std::cout << construction << std::endl;
		construction = construction.substr(0,construction.length()-1);
	}
	else if(flag == 'l') {
		std::cout << "***Input One Line Process***" << std::endl;
		construction = save_option;
	}
	else if(flag == 'd') {
		std::cout << "***Debug Process***" << std::endl;
		//construction = save_option;
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

	std::cout << flag_cs_mf_sy << std::endl;
	if(flag_cs_mf_sy == 's') { 
		if((flag != 'd') && ((construction == "stop") || (construction == ""))) 
			std::cout << "***Nothing to Build***" << std::endl;
		else {
			std::cout << "***Possibility to Build HTML***" << std::endl;
			std::cout << "***BUILD IN PROGRESS***" << std::endl;
			Balise out;
			if(flag != 'd') 
				out = demand_in_balisev4(construction,0);
			else 
				out = demand_in_balisev4(test5,0);
			
			std::vector<Balise> vec_html = {out};
			HTML one_html{save_option,vec_html};
			//CSS on_css{"../test/test.css",vec_html};
			one_html.addinfile();
			//on_css.addinfile();
		}
	}
	/*else {
		modification = construction;
		if(((flag != 'd') && (flag != 's')) && ((modification == "stop") || (modification == ""))) 
			std::cout << "***Nothing to Modify***" << std::endl;
		else {
			std::cout << "***Possibility to Modify HTML***" << std::endl;
			std::cout << "***Modify IN PROGRESS***" << std::endl;
			if((flag == 'f') || (flag == 'l'))
				save_option = out_opt;
			std::fstream file(save_option,std::ios::in | std::ios::out);
			std::string test_modif = "1span sp;1p paragpraphe";	// ok
			std::string test_modifn = "";
			std::string stylebalise_test = "1p id=ID|class=classe;1span id=IDs";// ?
			//
			//
			//
			//ileModification(file,test_modif);	//GOOD
			//file,..file 					 	//GOOD
			//Manque la gestion des erreurs		
			if((flag != 'd') && (flag != 's')) 
				fileModification(file,modification);
			else {
				if(flag == 's') 
					fileModificationAttributeTags(file,stylebalise_test,"../test2.css");
				else 
					fileModificationAttributeTags(file,test_modif,"../test2.css");
			}
		}
	}*/
	//std::cout << share_attr.at(Body).at(0) << std::endl;
	/*for(auto s : share_attr.at(Article))
		std::cout << s << std::endl;*/
	//std::cout << IsAssociateAttribute(Body,"onerror") << std::endl;
    return 0;
}