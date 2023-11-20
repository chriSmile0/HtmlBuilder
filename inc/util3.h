//X-MACROS
#ifndef UTIL2_H
#define UTIL2_H
#include <iostream>
#include <vector>
using vec_prop = std::vector<std::string>;

#define PROPERTY \
X(accent-color, "accent-color") \
X(agn-content, "agn-content") \
X(agn-items, "agn-items") \
X(align-self, "align-self") \
X(animation, "animation") \
X(animation-delay, "animation-delay") \
X(animation-direction, "animation-direction") \
X(animation-duration, "animation-duration") \
X(animation-fill-mode, "animation-fill-mode") \
X(animation-iteration-count, "animation-iteration-count") \
X(animation-name, "animation-name") \
X(animation-play-state, "animation-play-state") \
X(animation-timing-function, "animation-timing-function") \
X(aspect-ratio, "aspect-ratio") \
X(backdrop-filter, "backdrop-filter") \
X(backface-visibility, "backface-visibility") \
X(background, "background") \
X(background-attachment, "background-attachment") \
X(background-blend-mode, "background-blend-mode") \
X(background-clip, "background-clip") \
X(background-color, "background-color") \
X(background-image, "background-image") \
X(background-origin, "background-origin") \
X(background-position, "background-position") \
X(background-position-x, "background-position-x") \
X(background-position-y, "background-position-y") \
X(background-repeat, "background-repeat") \
X(background-size, "background-size") \
X(block-size, "block-size") \
X(border, "border") \
X(border-block, "border-block") \
X(border-block-color, "border-block-color") \
X(border-block-end, "border-block-end") \
X(border-block-end-color, "border-block-end-color") \
X(border-block-end-style, "border-block-end-style") \
X(border-block-end-width, "border-block-end-width") \
X(border-block-start, "border-block-start") \
X(border-block-start-color, "border-block-start-color") \
X(border-block-start-style, "border-block-start-style") \
X(border-block-start-width, "border-block-start-width") \
X(border-block-style, "border-block-style") \
X(border-block-width, "border-block-width") \
X(border-bottom, "border-bottom") \
X(border-bottom-color, "border-bottom-color") \
X(border-bottom-left-radius, "border-bottom-left-radius") \
X(border-bottom-right-radius, "border-bottom-right-radius") \
X(border-bottom-style, "border-bottom-style") \
X(border-bottom-width, "border-bottom-width") \
X(border-collapse, "border-collapse") \
X(border-color, "border-color") \
X(border-end-end-radius, "border-end-end-radius") \
X(border-end-start-radius, "border-end-start-radius") \
X(border-image, "border-image") \
X(border-image-outset, "border-image-outset") \
X(border-image-repeat, "border-image-repeat") \
X(border-image-slice, "border-image-slice") \
X(border-image-source, "border-image-source") \
X(border-image-width, "border-image-width") \
X(border-inline, "border-inline") \
X(border-inline-color, "border-inline-color") \
X(border-inline-end, "border-inline-end") \
X(border-inline-end-color, "border-inline-end-color") \
X(border-inline-end-style, "border-inline-end-style") \
X(border-inline-end-width, "border-inline-end-width") \
X(border-inline-start, "border-inline-start") \
X(border-inline-start-color, "border-inline-start-color") \
X(border-inline-start-style, "border-inline-start-style") \
X(border-inline-start-width, "border-inline-start-width") \
X(border-inline-style, "border-inline-style") \
X(border-inline-width, "border-inline-width") \
X(border-left, "border-left") \
X(border-left-color, "border-left-color") \
X(border-left-style, "border-left-style") \
X(border-left-width, "border-left-width") \
X(border-radius, "border-radius") \
X(border-right, "border-right") \
X(border-right-color, "border-right-color") \
X(border-right-style, "border-right-style") \
X(border-right-width, "border-right-width") \
X(border-spacing, "border-spacing") \
X(border-start-end-radius, "border-start-end-radius") \
X(border-start-start-radius, "border-start-start-radius") \
X(border-style, "border-style") \
X(border-top, "border-top") \
X(border-top-color, "border-top-color") \
X(border-top-left-radius, "border-top-left-radius") \
X(border-top-right-radius, "border-top-right-radius") \
X(border-top-style, "border-top-style") \
X(border-top-width, "border-top-width") \
X(border-width, "border-width") \
X(bottom, "bottom") \
X(box-decoration-break, "box-decoration-break") \
X(box-reflect, "box-reflect") \
X(box-shadow, "box-shadow") \
X(box-sizing, "box-sizing") \
X(break-after, "break-after") \
X(break-before, "break-before") \
X(break-inside, "break-inside") \
X(caption-side, "caption-side") \
X(caret-color, "caret-color") \
X(@charset, "@charset") \
X(clear, "clear") \
X(clip, "clip") \
X(clip-path, "clip-path") \
X(color, "color") \
X(column-count, "column-count") \
X(column-fill, "column-fill") \
X(column-gap, "column-gap") \
X(column-rule, "column-rule") \
X(column-rule-color, "column-rule-color") \
X(column-rule-style, "column-rule-style") \
X(column-rule-width, "column-rule-width") \
X(column-span, "column-span") \
X(column-width, "column-width") \
X(columns, "columns") \
X(content, "content") \
X(counter-increment, "counter-increment") \
X(counter-reset, "counter-reset") \
X(counter-set, "counter-set") \
X(cursor, "cursor") \
X(direction, "direction") \
X(display, "display") \
X(empty-cells, "empty-cells") \
X(filter, "filter") \
X(flex, "flex") \
X(flex-basis, "flex-basis") \
X(flex-direction, "flex-direction") \
X(flex-flow, "flex-flow") \
X(flex-grow, "flex-grow") \
X(flex-shrink, "flex-shrink") \
X(flex-wrap, "flex-wrap") \
X(float, "float") \
X(font, "font") \
X(@font-face, "@font-face") \
X(font-family, "font-family") \
X(font-feature-settings, "font-feature-settings") \
X(@font-feature-values, "@font-feature-values") \
X(font-kerning, "font-kerning") \
X(font-language-override, "font-language-override") \
X(font-size, "font-size") \
X(font-size-adjust, "font-size-adjust") \
X(font-stretch, "font-stretch") \
X(font-style, "font-style") \
X(font-synthesis, "font-synthesis") \
X(font-variant, "font-variant") \
X(font-variant-alternates, "font-variant-alternates") \
X(font-variant-caps, "font-variant-caps") \
X(font-variant-east-asian, "font-variant-east-asian") \
X(font-variant-ligatures, "font-variant-ligatures") \
X(font-variant-numeric, "font-variant-numeric") \
X(font-variant-position, "font-variant-position") \
X(font-weight, "font-weight") \
X(grid, "grid") \
X(grid-area, "grid-area") \
X(grid-auto-columns, "grid-auto-columns") \
X(grid-auto-flow, "grid-auto-flow") \
X(grid-auto-rows, "grid-auto-rows") \
X(grid-column, "grid-column") \
X(grid-column-end, "grid-column-end") \
X(grid-column-gap, "grid-column-gap") \
X(grid-column-start, "grid-column-start") \
X(grid-gap, "grid-gap") \
X(grid-row, "grid-row") \
X(grid-row-end, "grid-row-end") \
X(grid-row-gap, "grid-row-gap") \
X(grid-row-start, "grid-row-start") \
X(grid-template, "grid-template") \
X(grid-template-areas, "grid-template-areas") \
X(grid-template-columns, "grid-template-columns") \
X(grid-template-rows, "grid-template-rows") \
X(hanging-punctuation, "hanging-punctuation") \
X(height, "height") \
X(hyphens, "hyphens") \
X(hyphenate-character, "hyphenate-character") \
X(image-rendering, "image-rendering") \
X(@import, "@import") \
X(inline-size, "inline-size") \
X(inset, "inset") \
X(inset-block, "inset-block") \
X(inset-block-end, "inset-block-end") \
X(inset-block-start, "inset-block-start") \
X(inset-inline, "inset-inline") \
X(inset-inline-end, "inset-inline-end") \
X(inset-inline-start, "inset-inline-start") \
X(isolation, "isolation") \
X(justify-content, "justify-content") \
X(justify-items, "justify-items") \
X(justify-self, "justify-self") \
X(@keyframes, "@keyframes") \
X(left, "left") \
X(letter-spacing, "letter-spacing") \
X(line-break, "line-break") \
X(line-height, "line-height") \
X(list-style, "list-style") \
X(list-style-image, "list-style-image") \
X(list-style-position, "list-style-position") \
X(list-style-type, "list-style-type") \
X(margin, "margin") \
X(margin-block, "margin-block") \
X(margin-block-end, "margin-block-end") \
X(margin-block-start, "margin-block-start") \
X(margin-bottom, "margin-bottom") \
X(margin-inline, "margin-inline") \
X(margin-inline-end, "margin-inline-end") \
X(margin-inline-start, "margin-inline-start") \
X(margin-left, "margin-left") \
X(margin-right, "margin-right") \
X(margin-top, "margin-top") \
X(mask, "mask") \
X(mask-clip, "mask-clip") \
X(mask-composite, "mask-composite") \
X(mask-image, "mask-image") \
X(mask-mode, "mask-mode") \
X(mask-origin, "mask-origin") \
X(mask-position, "mask-position") \
X(mask-repeat, "mask-repeat") \
X(mask-size, "mask-size") \
X(mask-type, "mask-type") \
X(max-block-size, "max-block-size") \
X(max-height, "max-height") \
X(max-inline-size, "max-inline-size") \
X(max-width, "max-width") \
X(@media, "@media") \
X(min-block-size, "min-block-size") \
X(min-inline-size, "min-inline-size") \
X(min-height, "min-height") \
X(min-width, "min-width") \
X(mix-blend-mode, "mix-blend-mode") \
X(@namespace, "@namespace") \
X(object-fit, "object-fit") \
X(object-position, "object-position") \
X(offset, "offset") \
X(offset-anchor, "offset-anchor") \
X(offset-distance, "offset-distance") \
X(offset-path, "offset-path") \
X(offset-position, "offset-position") \
X(offset-rotate, "offset-rotate") \
X(opacity, "opacity") \
X(order, "order") \
X(orphans, "orphans") \
X(outline, "outline") \
X(outline-color, "outline-color") \
X(outline-offset, "outline-offset") \
X(outline-style, "outline-style") \
X(outline-width, "outline-width") \
X(overflow, "overflow") \
X(overflow-anchor, "overflow-anchor") \
X(overflow-wrap, "overflow-wrap") \
X(overflow-x, "overflow-x") \
X(overflow-y, "overflow-y") \
X(overscroll-behavior, "overscroll-behavior") \
X(overscroll-behavior-block, "overscroll-behavior-block") \
X(overscroll-behavior-inline, "overscroll-behavior-inline") \
X(overscroll-behavior-x, "overscroll-behavior-x") \
X(overscroll-behavior-y, "overscroll-behavior-y") \
X(padding, "padding") \
X(padding-block, "padding-block") \
X(padding-block-end, "padding-block-end") \
X(padding-block-start, "padding-block-start") \
X(padding-bottom, "padding-bottom") \
X(padding-inline, "padding-inline") \
X(padding-inline-end, "padding-inline-end") \
X(padding-inline-start, "padding-inline-start") \
X(padding-left, "padding-left") \
X(padding-right, "padding-right") \
X(padding-top, "padding-top") \
X(@page, "@page") \
X(page-break-after, "page-break-after") \
X(page-break-before, "page-break-before") \
X(page-break-inside, "page-break-inside") \
X(paint-order, "paint-order") \
X(perspective, "perspective") \
X(perspective-origin, "perspective-origin") \
X(place-content, "place-content") \
X(place-items, "place-items") \
X(place-self, "place-self") \
X(pointer-events, "pointer-events") \
X(position, "position") \
X(quotes, "quotes") \
X(resize, "resize") \
X(right, "right") \
X(rotate, "rotate") \
X(row-gap, "row-gap") \
X(scale, "scale") \
X(scroll-behavior, "scroll-behavior") \
X(scroll-margin, "scroll-margin") \
X(scroll-margin-block, "scroll-margin-block") \
X(scroll-margin-block-end, "scroll-margin-block-end") \
X(scroll-margin-block-start, "scroll-margin-block-start") \
X(scroll-margin-bottom, "scroll-margin-bottom") \
X(scroll-margin-inline, "scroll-margin-inline") \
X(scroll-margin-inline-end, "scroll-margin-inline-end") \
X(scroll-margin-inline-start, "scroll-margin-inline-start") \
X(scroll-margin-left, "scroll-margin-left") \
X(scroll-margin-right, "scroll-margin-right") \
X(scroll-margin-top, "scroll-margin-top") \
X(scroll-padding, "scroll-padding") \
X(scroll-padding-block, "scroll-padding-block") \
X(scroll-padding-block-end, "scroll-padding-block-end") \
X(scroll-padding-block-start, "scroll-padding-block-start") \
X(scroll-padding-bottom, "scroll-padding-bottom") \
X(scroll-padding-inline, "scroll-padding-inline") \
X(scroll-padding-inline-end, "scroll-padding-inline-end") \
X(scroll-padding-inline-start, "scroll-padding-inline-start") \
X(scroll-padding-left, "scroll-padding-left") \
X(scroll-padding-right, "scroll-padding-right") \
X(scroll-padding-top, "scroll-padding-top") \
X(scroll-snap-align, "scroll-snap-align") \
X(scroll-snap-stop, "scroll-snap-stop") \
X(scroll-snap-type, "scroll-snap-type") \
X(shape-image-threshold, "shape-image-threshold") \
X(shape-margin, "shape-margin") \
X(@supports, "@supports") \
X(tab-size, "tab-size") \
X(table-layout, "table-layout") \
X(text-align, "text-align") \
X(text-align-last, "text-align-last") \
X(text-combine-upright, "text-combine-upright") \
X(text-decoration, "text-decoration") \
X(text-decoration-color, "text-decoration-color") \
X(text-decoration-line, "text-decoration-line") \
X(text-decoration-style, "text-decoration-style") \
X(text-decoration-thickness, "text-decoration-thickness") \
X(text-emphasis, "text-emphasis") \
X(text-emphasis-color, "text-emphasis-color") \
X(text-emphasis-position, "text-emphasis-position") \
X(text-emphasis-style, "text-emphasis-style") \
X(text-indent, "text-indent") \
X(text-justify, "text-justify") \
X(text-orientation, "text-orientation") \
X(text-overflow, "text-overflow") \
X(text-shadow, "text-shadow") \
X(text-transform, "text-transform") \
X(text-underline-offset, "text-underline-offset") \
X(text-underline-position, "text-underline-position") \
X(touch-action, "touch-action") \
X(transform, "transform") \
X(transform-origin, "transform-origin") \
X(transform-style, "transform-style") \
X(transition, "transition") \
X(transition-delay, "transition-delay") \
X(transition-duration, "transition-duration") \
X(transition-property, "transition-property") \
X(transition-timing-function, "transition-timing-function") \
X(translate, "translate") \
X(unicode-bidi, "unicode-bidi") \
X(user-select, "user-select") \
X(vertical-align, "vertical-align") \
X(@viewport, "@viewport") \
X(visibility, "visibility") \
X(white-space, "white-space") \
X(widows, "widows") \
X(width, "width") \
X(will-change, "will-change") \
X(word-break, "word-break") \
X(word-spacing, "word-spacing") \
X(word-wrap, "word-wrap") \
X(writing-mode, "writing-mode") \
X(z-index, "z-index") 

#define X(num, name) num,
enum property : size_t
{
    PROPERTY
};
#undef X

#define X(num, name) name,
const char *name_property[] =
{
    PROPERTY
};
#undef X

inline std::string toStringP(enum property value) {return name_property[value];}

enum property toAsValueP(std::string str) {
    int i = 0;
    int size = sizeof(name_property) / sizeof(name_property[0]);
    while((i < size) && (name_property[i] != str))
       i++;
    if(i == size)
        i = -1;
    return (enum property)i;
}

void printEnumP() {
    int nb_property = sizeof(name_property) / sizeof(name_property[0]); 
    for(int i = 0 ; i < nb_property ; i++) 
        std::cout << name_property[i] << std::endl;
}

inline int sizeNameProperty() {return sizeof(name_property) / sizeof(name_property[0]);}

std::vector<std::string> storeStrEnumP() {
    std::vector<std::string> store;
    int nb_property = sizeof(name_property) / sizeof(name_property[0]); 
    for(int i = 0 ; i < nb_property ; i++) 
        store.push_back(name_property[i]);
    return store;
}

#endif // UTIL3_H // 