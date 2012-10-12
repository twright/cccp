#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "linked-list.h"

Link* def_link()
{
	Link* link = (Link*)malloc(sizeof(Link));
	link->next = NULL;

	return link;
}

Link* def_link_num(double number)
{
	Link* link = def_link();
	link->number = number;

	return link;
}

Link* add_link(Link* end, Link* link)
{
	assert(link != NULL);

	if (end) end->next = link;

	return link;
}

Link* add_link_num(Link* end, double number) {
	return add_link(end, def_link_num(number));
}

const char* list_to_str(Link* head, char* s, unsigned int len_s)
{
	char ds[MAX_DIGIT_LIMIT];

	if (head && len_s >= MAX_DIGIT_LIMIT) {
		snprintf(ds, MAX_DIGIT_LIMIT, "%.2f%s", head->number,
			head->next ? ", " : "");
		strncat(s, ds, len_s);
		list_to_str(head->next, s, len_s - MAX_DIGIT_LIMIT);
	}

	return s;
}

double list_sum(Link* head)
{
	return head ? head->number + list_sum(head->next) : 0;
}

double list_product(Link* head)
{
	return head ? head->number * list_product(head->next) : 1;
}