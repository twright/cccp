#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define MAX_DIGIT_LIMIT 50

typedef struct Link {
	double number;
	struct Link* next;
} Link;

Link* def_link();

Link* def_link_num(double);

Link* add_link(Link*, Link*);

Link* add_link_num(Link*, double);

const char* list_to_str(Link*, char*, unsigned int len_s);

double list_sum(Link*);

double list_product(Link*);

#endif /* LINKED_LIST_H */
