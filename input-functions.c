#include <stdlib.h>
#include <stdio.h>
#include "input-functions.h"

int get_int()
{
	char s[INPUT_LIMIT_INT];

	while(!fgets(s, INPUT_LIMIT_INT, stdin));

	return atoi(s);
}

float get_float()
{
	char s[INPUT_LIMIT_INT];

	while(!fgets(s, INPUT_LIMIT_INT, stdin));

	return atof(s);
}

double get_double()
{
	char s[INPUT_LIMIT_INT];

	while(!fgets(s, INPUT_LIMIT_INT, stdin));

	return strtod(s, NULL);
}