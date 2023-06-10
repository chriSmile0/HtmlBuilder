#ifndef CSS_H
#define CSS_H

#include "balise.h"
#include <vector>

class CSS {
	private:
		std::string Filename;
		std::fstream sfile;
		std::vector<Balise> vec_b;
	public:
		CSS() {Filename = "/tmp/1234567";}
		CSS(std::string name,std::vector<Balise> vec_balise);
		CSS(CSS const& copy);
		CSS & operator=(CSS const& copy);
		~CSS();

		void addinfile();
		options_and_tags add_in_rec(Balise b);
		std::vector<std::string> all_tags_invec(std::string tags);
		std::vector<option_and_value> all_opts_invec(std::string opts);
		std::string truncate_option(std::string option);
};

#include "../src/css.hpp"

#endif // CSS_H // 