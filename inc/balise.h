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
	public:
		Balise();
		Balise(std::string bal, pairvec pv_options,std::vector<Balise> bal_vec, int jFb, int jLb, int jLa);
		~Balise();

		//Getters inline
        inline std::string getBal_in_str() const {return bal_str;}
        inline balise getBal() const {return b;}
		inline std::string getBloc_balise() {return bloc_balise;}
		inline int getVecBalSize() const {return vec_b.size();};
		inline Balise getBalWithIndex(int index) const {return vec_b.at(index);}
		inline pairvec getOptionsBalise() const {return pv_o;}
		inline coordonnees_tag getCoordonnees() {return cds_t;}
		inline coordonnees_tag& getRefCoordonnees() {return cds_t;}

        //Setters
		void setBal(balise bal);
        void setBal_with_str(std::string str);

		/**
		 * @brief	Voir pairvec_in_str mais cette fois avec en setter du vecteur
		 * 			pv_o de l'objet balise
		 * @param{pv}	L'ensemble de pair à ajouter au vecteur pv_o
		 * @param{with_end} Savoir si on ajoute '/' à la fin de la balise
		 * @return	La chaine correctement assembler pour debug
		*/
		std::string setOptionsBalise(pairvec pv, int with_end);
		void setCoordonnees(int dF, int fF, int dL, int fL);

		//Adds
		/**
		 * @brief	Afin de placer de manière correcte une balise dans une 
		 * 			balise parent on doit utiliser les différents index de 
		 * 			position de la balise parente afin d'insérer tout le contenu
		 * 			de la balise en paramèètre dans la balise parente.
		 * 
		 * @param{new_bal}	La nouvelle balise à ajouter au parent
		 * @return
		*/
		void add_balisev2(Balise new_bal);
		void AddPreciseCoordonnees(int choice, int plus_value);
		void AddCoordonnesWithPreciseValue(int plus_value);

		//Converter
		void bal_in_str();
		void str_in_bal();
		/**
		 * @brief	Retranscrire les options de l'objet dans la balise
		 * @param{none}
		 * @return	la chaine qui contient les différentes option de la balise
		*/
		std::string pairvec_in_str();

		//Printer
		void printCoordonnees();
};

#include "../src/balise.hpp"

#endif // BALISE_H // 