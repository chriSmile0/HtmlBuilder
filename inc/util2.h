//X-MACROS
#ifndef UTIL2_H
#define UTIL2_H

#define TAGS \
X(Address, "address", true) \
X(Article, "article", true) \
X(Aside, "aside", true) \
X(Blockquote, "blockquote", true) \
X(Body, "body", true) \
X(Canvas, "canvas", true) \
X(Dd, "dd", true) \
X(Div, "div", true) \
X(Dl, "dl", true) \
X(Dt, "dt", true) \
X(Fieldset, "fieldset", true) \
X(Figcaption, "figcaption", true) \
X(Figure, "figure", true) \
X(Footer, "footer", true) \
X(Form, "form", true) \
X(H1, "h1", true) \
X(H2, "h2", true) \
X(H3, "h3", true) \
X(H4, "h4", true) \
X(H5, "h5", true) \
X(H6, "h6", true) \
X(Head, "head", true) \
X(Header, "header", true) \
X(Hr, "hr", true) \
X(Li, "li", true) \
X(Main, "main", true) \
X(Nav, "nav", true) \
X(Noscript, "noscript", true) \
X(Ol, "ol", true) \
X(P, "p", true) \
X(Pre, "pre", true) \
X(Section, "section", true) \
X(Table, "table", true) \
X(Tfoot, "tfoot", true) \
X(Ul, "ul", true) \
X(Video, "video", true) \
X(A, "a", false) \
X(Abbr, "abbr", false) \
X(Acronym, "acronym", false) \
X(B, "b", false) \
X(Bdo, "bdo", false) \
X(Big, "big", false) \
X(Br, "br", false) \
X(Button, "button", false) \
X(Cite, "cite", false) \
X(Code, "code", false) \
X(Dfn, "dfn", false) \
X(Em, "em", false) \
X(I, "i", false) \
X(Img, "img", false) \
X(Input, "input", false) \
X(Kbd, "kbd", false) \
X(Label, "label", false) \
X(Map, "map", false) \
X(Object, "object", false) \
X(Output, "output", false) \
X(Q, "q", false) \
X(Samp, "samp", false) \
X(Script, "script", false) \
X(Select, "select", false) \
X(Small, "small", false) \
X(Span, "span", false) \
X(Strong, "strong", false) \
X(Sub, "sub", false) \
X(Sup, "sup", false) \
X(Textarea, "textarea", false) \
X(Time, "time", false) \
X(Tt, "tt", false) \
X(Var, "var", false) 
//À COMPLÉTER ...// 

#define X(num, name, is_bloc_level) num,
enum tags : size_t
{
    TAGS
};
#undef X

#define X(num, name, is_bloc_level) name,
const char *name_tags[] =
{
    TAGS
};
#undef X

#define X(num, name, is_bloc_level) is_bloc_level,
bool inline_Bloc[]
{
    TAGS
};
#undef X

inline std::string toString(enum tags value) {return name_tags[value];}

inline bool toIsBloc(enum tags value) {return inline_Bloc[value];}

enum tags toAsValue(std::string str) {
    int i = 0;
    int size = sizeof(name_tags)/sizeof(name_tags[0]);
    while((i < size) && (name_tags[i] != str))
       i++;
    if(i == size)
        i = -1;//erreur pas présent
    return (enum tags)i;
}

#endif // UTIL2_H // 