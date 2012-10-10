#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "complex.h"

#define DOUBLE(x) (x*x)
#define COMPLEX_STRING_LIMIT 255

void tests();

int main(int argc, char const *argv[])
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

Complex def_complex(double real, double imag)
{
	Complex z;

	z.real = real;
	z.imag = imag;
	z.valid = 1;

	return z;
}

Complex invalid_complex()
{
	Complex z;

	z.valid = 0;

	return z;
}

char* complex_to_str(Complex z, char* s, unsigned int len_s)
{
	if (!z.valid)
		strncpy(s, "invalid", len_s);
	else if (z.real == 0.0 && z.imag == 0.0)
		snprintf(s, len_s, "0 + 0%c", IMAGINARY_SYMBOL);
	else if (z.real != 0.0 && z.imag == 0.0 )
		snprintf(s, len_s, "%.3f", z.real);
	else if (z.real == 0.0 && z.imag != 0.0)
		snprintf(s, len_s, "%.3f%c", z.imag, IMAGINARY_SYMBOL);
	else if (z.imag < 0.0)
		snprintf(s, len_s, "%.3f - %.3f%c", z.real, -z.imag,
			IMAGINARY_SYMBOL);
	else
		snprintf(s, len_s, "%.3f + %.3f%c", z.real, z.imag,
			IMAGINARY_SYMBOL);

	return s;
}

Complex complex_add(Complex z, Complex w)
{
	return def_complex(z.real + w.real, z.imag + w.imag);
}

Complex complex_sub(Complex z, Complex w)
{
	return def_complex(z.real - w.real, z.imag - w.imag);
}

Complex complex_mul_scalar(Complex z, double x)
{
	return def_complex(z.real * x, z.imag * x);
}

Complex complex_mul(Complex z, Complex w)
{
	return def_complex(z.real * w.real - z.imag * w.real,
		z.real * w.imag + z.imag * z.real);
}

Complex complex_div_scalar(Complex z, double x)
{
	return x != 0.0 ? def_complex(z.real / x, z.imag / x) : invalid_complex();
}

Complex complex_div(Complex z, Complex w)
{
	double mod2;

	mod2 = DOUBLE(w.real) + DOUBLE(w.imag);

	return complex_div_scalar(def_complex(z.real * w.real + z.imag * w.imag,
		z.imag * w.real - z.real * w.imag), mod2);
}