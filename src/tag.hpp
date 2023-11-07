#include "../inc/tag.h"

Tag::Tag(std::string tag, pairvec pv_options, std::vector<Tag> tag_vec,int nb_tab ,int jFb, int jLb, int jLa) {
	named = true;
	tag_str = tag;
	strInTag();
	nbtab = nb_tab;
	cds_t.begin_tagF = tag_block.length();
	tag_block += getFpv2(setTagOptions(pv_options,0),jFb,nb_tab);
	cds_t.end_tagF = tag_block.length();
	cds_t.begin_tagL = cds_t.end_tagF + 1;
	tag_block += getLpv2(tag,jLb,jLa,nb_tab);
	cds_t.end_tagL = tag_block.length();
}

Tag::Tag() {
	named = false;
	cds_t.begin_tagF = 0;
	cds_t.end_tagF = 0;
	cds_t.begin_tagL = 0;
	cds_t.end_tagL = 0;
}

void Tag::setTag(enum tags t) {
	tag = t;
	tagInStr();
}
void Tag::setTagWithStr(std::string str) {
	tag_str = str;
	strInTag();
}

std::string Tag::setTagOptions(pairvec pv, int with_end) {
	std::string head_tag = getTagInStr();
    for(auto p : pv) {
        head_tag += +" "+p.first+"="+"\""+p.second+"\"";
		pv_o.push_back(p);
	}
	head_tag += (with_end) ? "/" : "";
    return head_tag;
}

std::string Tag::pairvecInStr() {
	std::string tag_option = "";
    for(auto p : pv_o) 
        tag_option += " "+p.first+"="+"\""+p.second+"\"";
    return tag_option;
}

void Tag::setCoordinates(int dF, int fF, int dL, int fL) {
	cds_t.begin_tagF = dF;
	cds_t.end_tagF = fF;
	cds_t.begin_tagL = dL;
	cds_t.end_tagL = fL;
}

void Tag::addPreciseCoordinates(int choice, int add_value) {
	switch(choice) {
		case 0: cds_t.begin_tagF += add_value;
		case 1: cds_t.end_tagF += add_value;
		case 2: cds_t.begin_tagL += add_value;
		case 3: cds_t.end_tagL += add_value;
		default: 
			break;
	}
}

void Tag::addCoordinatesWithPreciseValue(int add_value) {
	cds_t.begin_tagF += add_value;
	cds_t.end_tagF += add_value;
	cds_t.begin_tagL += add_value;
	cds_t.end_tagL += add_value;
}

void Tag::printCoordinates() {
	std::cout << "begin tagF : " << cds_t.begin_tagF << "end tagF :" << cds_t.end_tagF << std::endl;
	std::cout << "begin tagL : " << cds_t.begin_tagL << "end tagL :" << cds_t.end_tagL << std::endl;
}

void Tag::addTag(Tag new_tag) {
	std::string blo_ntag = new_tag.getBlockTag();
	int begin = cds_t.begin_tagL-1;
	if(!named) 
		begin = (begin < 0) ? 0 : cds_t.begin_tagL;
	new_tag.addCoordinatesWithPreciseValue(begin);
	vec_t.push_back(new_tag);
	tag_block.insert(begin,blo_ntag);
	cds_t.begin_tagL += blo_ntag.length();
	cds_t.end_tagL += blo_ntag.length();
}

Tag::~Tag(){	
}