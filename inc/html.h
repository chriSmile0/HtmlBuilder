#ifndef HTML_H
#define HTML_H

#include "tag.h"
#include <vector>

class HTML {
	private:
		std::string Filename;
    	std::string title;
		std::fstream sfile;
		std::vector<Tag> t_vec;

	public:
		HTML() {Filename = "/tmp/123456";}
		HTML(std::string name,std::vector<Tag> vec);
		HTML(HTML const& copy);
		HTML& operator=(HTML const& copy);
		~HTML();

		//Setters
		inline void setFpHtml() {sfile << getFpv2("!DOCTYPE html",0,0) +"\n" + getFpv2("html lang=\"fr\"",0,0);}
		inline void setLpHtml() {sfile << getLpv2("html",1,0,0);}
		
		//AddInFile
		/**
		 * @brief	Add blocks of each tag in the html file
		 * @param{none}
		 * @return
		*/
		void addInFile();
};

#include "../src/html.hpp"

#endif // HTML_H //