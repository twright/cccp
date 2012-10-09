#include <stdio.h>

int main(int argc, char const *argv[])
{
	int hours;
	double rate, wages;

	printf("How many (whole) hours has the employee worked? ");
	scanf("%d", &hours);
	getchar();
	printf("What is the hourly rate? ");
	scanf("%f", &rate);
	getchar();

	wages = rate * hours;
	printf("Total earnings £%.2f\n");

	return 0;
}
