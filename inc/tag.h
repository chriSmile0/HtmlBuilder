#ifndef TAG_H
#define TAG_H

#include "util.h"

class Tag {
	private:
	    enum tags tag;
		bool named;
        std::string tag_str;
		std::vector<Tag> vec_t;
		std::string tag_block = "";
		coordinates_tag cds_t;
		pairvec pv_o;
		int nbtab;
	public:
		Tag();
		Tag(std::string tag, pairvec pv_options,std::vector<Tag> tag_vec,int nb_tab, int jFb, int jLb, int jLa);
		~Tag();

		//Getters inline
        inline std::string getTagInStr() const {return tag_str;}
        inline enum tags getTag() const {return tag;}
		inline std::string getBlockTag() {return tag_block;}
		inline int getVecTagSize() const {return vec_t.size();};
		inline Tag getTagWithIndex(int index) const {return vec_t.at(index);}
		inline pairvec getTagOptions() const {return pv_o;}
		inline coordinates_tag getCoordinates() {return cds_t;}
		inline coordinates_tag& getRefCoordinates() {return cds_t;}

        //Setters
		void setTag(enum tags t);
        void setTagWithStr(std::string str);

		/**
		
		 * @brief 	pairvec_in_str but the vector is in parameter
		 * @param{pv}	 All pair to add to pv_o
		 * @param{with_end} Known if add '/' at the end of the tag
		 * @return	The string with options and the correct end tag
		*/
		std::string setTagOptions(pairvec pv, int with_end);
		void setCoordinates(int dF, int fF, int dL, int fL);

		//Adds
		/**
		 * @brief	For a corerctly insert a tag in a parent tag. It's use
		 *			differents index of position of the parent tag for insert 
		 * 			the tag content in parameter of the parent tag.
		 * 
		 * @param{new_Tag}	The new tag to add in the parent
		 * @return
		*/
		void addTag(Tag new_tag);
		void addPreciseCoordinates(int choice, int add_value);
		void addCoordinatesWithPreciseValue(int add_value);

		//Converter
		inline void tagInStr() {tag_str = toString(tag);}
		inline void strInTag() {tag = toAsValue(tag_str);}
		/**
		 * @brief	Copy the object options in this tag
		 * @param{none}
		 * @return	The string which contains the tag options
		*/
		std::string pairvecInStr();

		//Printer
		void printCoordinates();
};

#include "../src/tag.hpp"

#endif // TAG_H // 