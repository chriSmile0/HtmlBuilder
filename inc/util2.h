//X-MACROS
#ifndef UTIL2_H
#define UTIL2_H
#include <iostream>
#include <vector>
using vec_attr = std::vector<std::string>;
const char* str = "accesskey;class;contenteditable;data-*;dir;draggable;hidden;id;lang;spellcheck;style;tabindex;title;translate";

#define TAGS \
X(Address, "address", true, "") \
X(Article, "article", true,"") \
X(Aside, "aside", true,"") \
X(Blockquote, "blockquote", true,"cite;") \
X(Body, "body", true,"onafterprint;onbeforeprint;onbeforeunload;onerror;onhashchange;onload;onoffline;ononline;onpagehide;onpageshow;onpopstate;onresize;onstorage;onunload;") \
X(Canvas, "canvas", true,"height;width") \
X(Dd, "dd", true,"") \
X(Div, "div", true,"") \
X(Dl, "dl", true,"") \
X(Dt, "dt", true,"") \
X(Fieldset, "fieldset", true,"disabled;form;name;") \
X(Figcaption, "figcaption", true,"") \
X(Figure, "figure", true,"") \
X(Footer, "footer", true,"") \
X(Form, "form", true,"accept-charset;action;autocomplete;enctype;formaction;method;name;novalidate;onreset;onsubmit;rel;target;") \
X(H1, "h1", true,"") \
X(H2, "h2", true,"") \
X(H3, "h3", true,"") \
X(H4, "h4", true,"") \
X(H5, "h5", true,"") \
X(H6, "h6", true,"") \
X(Head, "head", true,"") \
X(Header, "header", true,"") \
X(Hr, "hr", true,"") \
X(Li, "li", true,"value") \
X(Main, "main", true,"") \
X(Nav, "nav", true,"") \
X(Noscript, "noscript", true,"") \
X(Ol, "ol", true,"reversed;start;") \
X(P, "p", true,"") \
X(Pre, "pre", true,"") \
X(Section, "section", true,"") \
X(Table, "table", true,"") \
X(Tfoot, "tfoot", true,"") \
X(Ul, "ul", true,"") \
X(Video, "video", true,"autoplay;controls;height;loop;muted;onabort;oncanplay;oncanplaythrough;onduractionchange;onemptied;onended;onerror;onloadeddata;onloadedmetadata;onloadstart;onpause;onplay;onplaying;onprogress;onratechange;onseeked;onseeking;onsted;onsuspend;ontimeupdate;onvolumechange;onwaiting;poster;preload;src;width;") \
X(A, "a", false, "download;href;hreflang;media;rel;target;type;") \
X(Abbr, "abbr", false, "") \
X(Acronym, "acronym", false, "") \
X(B, "b", false, "") \
X(Bdo, "bdo", false, "") \
X(Big, "big", false, "") \
X(Br, "br", false, "") \
X(Button, "button", false, "autofocus;disabled;form;formaction;name;type;value;") \
X(Cite, "cite", false, "") \
X(Code, "code", false, "") \
X(Dfn, "dfn", false, "") \
X(Em, "em", false, "") \
X(I, "i", false, "") \
X(Img, "img", false, "alt;height;ismap;onabort;onerror;onload;sizes;src;srcset;usemap;width;") \
X(Input, "input", false, "accept;alt;autocomplete;autofocus;checked;dirname;disabled;form;formaction;height;list;max;maxlength;min;multiple;name;onload;onsearch;pattern;placeholder;readonly;required;size;src;step;type;value;") \
X(Kbd, "kbd", false, "") \
X(Label, "label", false, "for;form;") \
X(Map, "map", false, "name;") \
X(Object, "object", false, "data;formheight;name;onabort;oncanplay;onerror;type;usemap;;width;") \
X(Output, "output", false, "for;form;name;") \
X(Q, "q", false, "cite;") \
X(Samp, "samp", false, "") \
X(Script, "script", false, "async;charset;defer;onerror;onload;src;type;") \
X(Select, "select", false, "autofocus;disabled;form;multiple;name;required;size;") \
X(Sm, "sm", false, "") \
X(Span, "span", false, "") \
X(Strong, "strong", false, "") \
X(Sub, "sub", false, "") \
X(Sup, "sup", false, "") \
X(Textarea, "textarea", false, "autofocus;cols;dirname;disabled;form;maxlength;name;placeholder;readonly;required;rows;wrap;") \
X(Time, "time", false, "datetime;") \
X(Tt, "tt", false, "") \
X(Var, "var", false, "") 
// TO COMPLETE ...// 


#define X(num, name, is_bloc_level, attributes) num,
enum tags : size_t
{
    TAGS
};
#undef X

#define X(num, name, is_bloc_level, attributes) name,
const char *name_tags[] =
{
    TAGS
};
#undef X

#define X(num, name, is_bloc_level, attributes) is_bloc_level,
bool inline_Block[] 
{
    TAGS
};
#undef X

#define X(num, name, is_bloc_level, attributes) attributes,
const char *attributes[] = 
{
    TAGS
};
#undef X


std::vector<std::string> parseLine(std::string str, char splitter);

std::vector<vec_attr> attributes_toVecstr() {
    std::vector<vec_attr> vec;
    for(auto a : attributes) 
        vec.push_back(parseLine((std::string(a))+(str),';'));
    return vec;
}

std::vector<vec_attr> share_attr = attributes_toVecstr();

inline std::string toString(enum tags value) {return name_tags[value];}

inline std::string toStringAttr(enum tags value) {return ((std::string)attributes[value])+str;}

inline vec_attr toVecAttr(enum tags value) {return share_attr.at(value);}

bool IsAssociateAttribute(enum tags value, std::string attribute) {
    for(auto v : toVecAttr(value))
        if(v == attribute)
            return true;
    return false;        
}

inline bool toIsBlock(enum tags value) {return inline_Block[value];}

enum tags toAsValue(std::string str) {
    int i = 0;
    int size = sizeof(name_tags)/sizeof(name_tags[0]);
    while((i < size) && (name_tags[i] != str))
       i++;
    if(i == size)
        i = -1;
    return (enum tags)i;
}

void printEnum() {
    int nb_tags = sizeof(name_tags)/sizeof(name_tags[0]); 
    for(int i = 0 ; i < nb_tags ; i++) 
        std::cout << name_tags[i] << std::endl;
}

inline int sizeNameTags() {return sizeof(name_tags)/sizeof(name_tags[0]);}

std::vector<std::string> storeStrEnum() {
    std::vector<std::string> store;
    int nb_tags = sizeof(name_tags)/sizeof(name_tags[0]); 
    for(int i = 0 ; i < nb_tags ; i++) 
        store.push_back(name_tags[i]);
    return store;
}

#endif // UTIL2_H // 