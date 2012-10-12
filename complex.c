#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "complex.h"

#define DOUBLE(x) (x*x)

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