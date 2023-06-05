#ifndef BALISE_H
#define BALISE_H

#include "util.h"

class Balise {
	private:
	    balise b;
		bool named;
        std::string bal_str;
		std::vector<Balise> vec_b;
		std::string bloc_balise = "";
		coordonnees_tag cds_t;
		pairvec pv_o;
		int fin_balise = 0;
		int jump = 1;
	public:
		Balise();
		Balise(std::string bal,int jFb, int jLb, int jLa);
		Balise(balise bal,pairvec pv_options,std::vector<Balise> bal_vec, int with_end,int jump);
		Balise(std::string bal,pairvec pv_options,std::vector<Balise> bal_vec, int with_end, int jump);
		~Balise();

        inline std::string getBal_in_str() const {return bal_str;}
        inline balise getBal() const {return b;}
		inline std::string getBloc_balise() {return bloc_balise;}
		inline int getFinBalise() const {return fin_balise;}

        void setBal(balise bal);
        void setBal_with_str(std::string str);
		std::string setOptionsBalise(pairvec pv, int with_end);
		inline void setJump(int j) {jump = j;}

		
		inline void add_inbloc(std::string addbloc) {bloc_balise += addbloc;}
		void add_balise(Balise new_bal);
		void add_balisev2(Balise new_bal);

		void bal_in_str();
		void str_in_bal();

		int lastendline();
		inline int getVecBalSize() const {return vec_b.size();};
		inline Balise getBalWithIndex(int index) const {return vec_b.at(index);}
		inline pairvec getOptionsBalise() const {return pv_o;}
		std::string pairvec_in_str();

		coordonnees_tag	getCoordonnees() {return cds_t;}
		void setCoordonnees(int dF, int fF, int dL, int fL);
		coordonnees_tag& getRefCoordonnees() {return cds_t;}
		void AddPreciseCoordonnees(int choice, int plus_value);
		void AddCoordonnesWithPreciseValue(int plus_value);

		void printCoordonnees();
};

#include "../src/balise.hpp"

#endif // BALISE_H // 