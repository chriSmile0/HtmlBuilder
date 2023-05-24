#ifndef HTML_H
#define HTML_H

#include "util.h"
#include "balise.h"
#include <vector>

class HTML {
	private:
		std::string Filename;
    	std::string title;
		std::fstream sfile;
		std::vector<Balise> b_vec;

	public:
		HTML() {Filename = "/tmp/123456";}
		HTML(std::string name,std::vector<Balise> vec);
		HTML(HTML const& copy);
		HTML & operator=(HTML const& copy);
		~HTML();


		inline void setFpHtml() {sfile << getFp("!DOCTYPE html") +"\n" + getFp("html lang=\"fr\"")+"\n";}
		inline void setLpHtml() {sfile << getLp("html");}
		void addinfile();
};




#include "../src/html.hpp"

#endif // HTML_H //