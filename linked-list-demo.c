#include <stdlib.h>
#include <stdio.h>
#include "linked-list.h"

#define MAX_PRINT_LENGTH 1000

int main(int argc, char const *argv[])
{
	unsigned int i;
	Link* head = NULL;
	Link* end = head;
	char s[MAX_PRINT_LENGTH];

	for (i = 1; i < argc; ++i) {
		end = add_link_num(end, strtod(argv[i], NULL));
		if (!head) head = end;
	}

	printf("xs = {%s}\n", list_to_str(head, s, MAX_PRINT_LENGTH));
	printf("sum = %4.3f\n", list_sum(head));
	printf("product = %4.3f\n", list_product(head));

	return 0;
}

