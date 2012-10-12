#include <stdio.h>
#include "input-functions.h"

int main()
{
	int hours = -1;
	double rate = 0, wages;

	do {
		printf("How many (whole) hours has the employee worked? ");
	} while ((hours = get_int()) < 0);
	do {
		printf("What is the hourly rate? ");
	} while ((rate = get_double()) < 0);

	wages = rate * hours;
	printf("Total earnings £%.2f\n", wages);

	return 0;
}
