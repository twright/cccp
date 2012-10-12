#include <stdio.h>
#include <stdlib.h>
#include "input-functions.h"

#define INT_LIMIT 255

unsigned int abs_val(int x)
{
	return x >= 0 ? x : -x;
}

int main(int argc, char const *argv[])
{
	int n = 0;
    (void)argc;
    (void)argv;

	n = get_int();

	printf("n = %3.d, |n| = %3.u\n", n, abs_val(n));

	return 0;
}
