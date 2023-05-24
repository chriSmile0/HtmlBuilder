#include "inc/html.h"

Balise createDefaultHead() {
	Balise head("head",{},{},0);
	return head;
}

Balise createDefaultBody() {
	Balise body{"body",{},{},0};
	return body;
}


int main() {
    return 0;
}