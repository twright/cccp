#ifndef COMPLEX_H
#define COMPLEX_H

#define IMAGINARY_SYMBOL 'i'
#define COMPLEX_STRING_LIMIT 255

typedef struct {
	double real, imag;
	int valid;
} Complex;

Complex def_complex(double, double);

Complex invalid_complex();

char* complex_to_str(Complex, char*, unsigned int);

Complex complex_add(Complex, Complex);

Complex complex_sub(Complex, Complex);

Complex complex_mul_scalar(Complex, double);

Complex complex_mul(Complex, Complex);

Complex complex_div_scalar(Complex, double);

Complex complex_div(Complex, Complex);

#endif /* COMPLEX_H */
