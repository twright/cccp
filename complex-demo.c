#include <stdio.h>
#include "complex.h"

void tests();

int main()
{
	int i;

	for (i = 0; i <= 100000; ++i)
		tests();

	return 0;
}

void tests()
{
	Complex z = def_complex(2, 4), w = def_complex(-2, 4.7);
	double x = 5, y = 0;
	char s[COMPLEX_STRING_LIMIT];

	printf("%s\n", complex_to_str(z, s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(w, s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(def_complex(0, 0), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(def_complex(2, 0), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(def_complex(0, -3), s,
		COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(complex_add(z, w), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(complex_sub(z, w), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(complex_mul_scalar(z, x), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(complex_mul_scalar(z, y), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(complex_mul(z, w), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(complex_div_scalar(z, x), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(complex_div_scalar(z, y), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(complex_div(z, w), s, COMPLEX_STRING_LIMIT));
	printf("%s\n", complex_to_str(complex_div(w, z), s, COMPLEX_STRING_LIMIT));
}
