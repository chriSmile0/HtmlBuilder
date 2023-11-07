#ifndef BALISE_H
#define BALISE_H

#include "util.h"

class Balise {
	private:
	    enum tags tag;
		bool named;
        std::string bal_str;
		std::vector<Balise> vec_b;
		std::string bloc_balise = "";
		coordonnees_tag cds_t;
		pairvec pv_o;
		int nbtab;
	public:
		Balise();
		Balise(std::string bal, pairvec pv_options,std::vector<Balise> bal_vec,int nb_tab, int jFb, int jLb, int jLa);
		~Balise();

		//Getters inline
        inline std::string getBal_in_str() const {return bal_str;}
        inline enum tags getBal() const {return tag;}
		inline std::string getBloc_balise() {return bloc_balise;}
		inline int getVecBalSize() const {return vec_b.size();};
		inline Balise getBalWithIndex(int index) const {return vec_b.at(index);}
		inline pairvec getOptionsBalise() const {return pv_o;}
		inline coordonnees_tag getCoordonnees() {return cds_t;}
		inline coordonnees_tag& getRefCoordonnees() {return cds_t;}

        //Setters
		void setBal(enum tags t);
        void setBal_with_str(std::string str);

		/**
		
		 * @brief 	pairvec_in_str but the vector is in parameter
		 * @param{pv}	 All pair to add to pv_o
		 * @param{with_end} Known if add '/' at the end of the tag
		 * @return	The string with options and the correct end tag
		*/
		std::string setOptionsBalise(pairvec pv, int with_end);
		void setCoordonnees(int dF, int fF, int dL, int fL);

		//Adds
		/**
		 * @brief	For a corerctly insert a tag in a parent tag. It's use
		 *			differents index of position of the parent tag for insert 
		 * 			the tag content in parameter of the parent tag.
		 * 
		 * @param{new_bal}	The new tag to add in the parent
		 * @return
		*/
		void add_balisev2(Balise new_bal);
		void AddPreciseCoordonnees(int choice, int plus_value);
		void AddCoordonnesWithPreciseValue(int plus_value);

		//Converter
		inline void bal_in_str() {bal_str = toString(tag);}
		inline void str_in_bal() {tag = toAsValue(bal_str);}
		/**
		 * @brief	Copy the object options in this tag
		 * @param{none}
		 * @return	The string which contains the tag options
		*/
		std::string pairvec_in_str();

		//Printer
		void printCoordonnees();
};

#include "../src/balise.hpp"

#endif // BALISE_H // 