#include <stdio.h>
#define true 1
#define false 0

int main(int argc, char const *argv[])
{
	int hours = -1;
	double rate = 0, wages;

	do {
		printf("How many (whole) hours has the employee worked? ");
		scanf("%d", &hours);
		getchar();
	} while (hours < 0);
	do {
		printf("What is the hourly rate? ");
		scanf("%lf", &rate);
		getchar();
	} while (rate < 0);

	wages = rate * hours;
	printf("Total earnings £%.2f\n", wages);

	return 0;
}
