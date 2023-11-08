#include "../inc/util_wo.h"
#include <getopt.h>
#include <string.h>


int CheckOpenFile(std::string f, std::string type) {
	std::fstream file(f, std::ios::in);
	int retour = file.fail();
	if(retour == -1) {
		std::cerr << "Error " << f << " not readable, use " << type << " file" << std::endl;
		exit(1);
	}
	file.close();
	return retour;
}

std::string CheckExtension(char *path, std::string extension) {
	std::string tmp = path;
	if(tmp.substr(tmp.find_last_of(".")+1) == extension) 
		if(CheckOpenFile(tmp,extension) != -1)
			return tmp;
}

void checkDAndC(std::string& save_option, int argc, int optind, 
				std::string& out_opt, char *argv[], char& flag_mf_s, char flag_cs_mf_sy) 
{
	if(flag_cs_mf_sy != '-') {
		if(argc-optind == 0) {
			out_opt = "../test/test.html";
		}
		else if(argc-optind == 1) {
			flag_mf_s = 'm';
			out_opt = CheckExtension(argv[optind],"html");
			if(flag_cs_mf_sy != 's') {
				save_option = out_opt;
				if(save_option.substr(save_option.find_last_of(".")+1)=="html")
					out_opt = save_option;
				else 
					out_opt = "../page.html";
				save_option = "";
			}
		}
		else if((argc-optind == 2) && (flag_cs_mf_sy == 'y')) {
			flag_mf_s = 's';
			save_option = CheckExtension(argv[optind+1],"css");//check css
			out_opt = CheckExtension(argv[optind],"html");	//check html
		}
	}
}

void checkL(std::string& save_option, int argc, int optind, 
				std::string& out_opt, std::string& out_opt2, char *argv[], 
				char& flag_mf_s, char flag_cs_mf_sy) 
{
	if(flag_cs_mf_sy != '-') {
		save_option = argv[optind-1];
		out_opt = "../test/test.html";
		std::cout << argc-optind << std::endl;
		std::cout << flag_cs_mf_sy << std::endl;
		if(flag_cs_mf_sy != 'y') {
			if(argc-optind == 1) {
				out_opt = CheckExtension(argv[optind],"html");//check of .html(!)
			}
			else {
				for(int i = optind ; i < argc-1 ;i++)
					save_option = save_option + " "+ argv[i];
				out_opt = CheckExtension(argv[argc-1],"html");
			}
			flag_mf_s = flag_cs_mf_sy;
		}
		else {
			flag_mf_s = 's';
			if(argc-optind == 2) {
				out_opt = CheckExtension(argv[optind],"html"); //check html
				out_opt2 = CheckExtension(argv[optind+1],"css"); //check css
			}
			else {
				for(int i = optind ; i < argc-2 ;i++)
					save_option = save_option + " "+ argv[i];
				out_opt = CheckExtension(argv[argc-2],"html");
				out_opt2 = CheckExtension(argv[argc-1],"css");
			}
		}
	}
}

void checkF(std::string& save_option, int argc, int optind, 
			std::string& out_opt, std::string& out_opt2, char *argv[], 
			char& flag_mf_s, char flag_cs_mf_sy) 
{
	if(flag_cs_mf_sy != '-') {
		save_option = argv[optind-1];
		out_opt = "../test/test.html";
		std::cout << argc-optind << std::endl;
		std::cout << flag_cs_mf_sy << std::endl;
		if(flag_cs_mf_sy != 'y') {
			if(argc-optind == 1)
				out_opt = CheckExtension(argv[optind],"html");//check .html(!)
			flag_mf_s = flag_cs_mf_sy;
		}
		else if((argc-optind == 2) && (flag_cs_mf_sy == 'y')) {
			flag_mf_s = 's';
			out_opt = CheckExtension(argv[optind],"html"); //check html
			out_opt2 = CheckExtension(argv[optind+1],"css"); //check css
		}
	}
}

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
	std::string out_opt2 = "";
	int opt, index = 0;
	char flag = '-'; 
	char flag_cs_mf_sy = 'c';
	char flag_mf_s = '-';
	int cpt = 0;
	while((opt = getopt_long(argc,argv,"sym:f:l:cd",options,&index)) != -1) {
		cpt++;
		flag = (char)opt;
		switch(opt) {
			case 'f': checkF(save_option,argc,optind,out_opt,out_opt2,argv,
						flag_mf_s,flag_cs_mf_sy);
				break;
			case 'l': checkL(save_option,argc,optind,out_opt,out_opt2,argv,
						flag_mf_s,flag_cs_mf_sy);
				break;
			case 'c': checkDAndC(save_option,argc,optind,out_opt,argv,flag_mf_s,
						flag_cs_mf_sy);
				break;
			case 'd': checkDAndC(save_option,argc,optind,out_opt,argv,flag_mf_s,
						flag_cs_mf_sy);
				break;
			case 's'://Construction
				flag_cs_mf_sy = 's';
				break;
			case 'y'://Style
				flag_cs_mf_sy = 'y';
				break;
			case 'm'://Modification
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
		construction = construction.substr(0,construction.length()-1);
	}
	else if(flag == 'l') {
		std::cout << "***Input One Line Process***" << std::endl;
		construction = save_option;
	}
	else if(flag == 'd') {
		std::cout << "***Debug Process***" << std::endl;
	}
	
	std::string test0 = "{article div}";					// ok V5
	std::string test1 = "{article {div p}}";				// ok V5
	std::string test2 = "{article;section}";				// ok V5
	std::string test3 = "{2article;2section}";				// ok V5
	std::string test4 = "{article;section;p}";				// ok V5
	std::string test5 = "{article {div p};article {div p}}";// ok V5
	std::string test6 = "{article {div;p {span li}}}";		// n_ok/ok V5
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
			Tag out;
			if(flag != 'd') 
				out = demandInTag(construction,0);
			else 
				out = demandInTag(test5,0);
			
			std::vector<Tag> vec_html = {out};
			HTML one_html{out_opt,vec_html};
			one_html.addInFile();
		}
	}
	else {
		modification = construction;
		if(((flag != 'd') && (flag != 's')) && 
			((modification == "stop") || (modification == ""))) {
			std::cout << "***Nothing to Modify***" << std::endl;
		}
		else {
			std::cout << "***Possibility to Modify HTML***" << std::endl;
			std::cout << "***Modify IN PROGRESS***" << std::endl;
			if(flag_mf_s == 's')
				if((flag == 'f') || (flag == 'l'))
					save_option = out_opt2;
			std::fstream file(out_opt,std::ios::in | std::ios::out);
			std::string test_modif = "1span sp;1p paragpraphe";	// ok
			std::string styletag_test = "1p id=ID|class=classe;1span id=IDs";// ?
			std::cout << out_opt << std::endl;
			std::cout << modification << std::endl;
			if(flag_mf_s == 's') {
				if(flag == 'd') 
					fileModificationAttributeTags(file,styletag_test,save_option);
				else 
					fileModificationAttributeTags(file,modification,save_option);
			}
			else if(flag_mf_s = 'm') {
				if(flag == 'd') 
					fileModification(file,test_modif);
				else 
					fileModification(file,modification);
			}
		}
	}
    return 0;
}