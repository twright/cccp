#include <stdio.h>
#include <stdlib.h>
#include "input-functions.h"

#define INT_LIMIT 255

unsigned int abs_val(int x)
{
	return x >= 0 ? x : -x;
}

int main()
{
	int n = 0;

	n = get_int();

	printf("n = %3.d, |n| = %3.u\n", n, abs_val(n));

	return 0;
}