/* This program reads in a date (which must be in the 20th century - this software is NOT millenium-compliant!) and prints out the day of the week corresponding to that date */

#include <stdio.h>
#define	DAYS_PER_YEAR	365

struct date
{
	int day, month, year;
};

struct date read_date(void)
{
	char eoln;
	struct date dateIn;

	scanf("%d %d %d", &dateIn.day, 
		&dateIn.month, 
		&dateIn.year);
	eoln = getchar();

	return dateIn;
}

int days_in(int the_month, int the_year)
{
	switch (the_month)
	{
		case 9:
		case 4:
		case 6:
		case 11:
			return 30;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			return (the_year % 4 == 0  && 
					the_year != 0 ? 29 : 28);
	}
}

long get_day_number(struct date toDate)
{
	long month_no, no_of_days = 0;

	if (toDate.year > 0) 
		no_of_days =
		  (long)(toDate.year) * DAYS_PER_YEAR + 
			(toDate.year - 1) / 4;

	for (month_no = 1 ; month_no < toDate.month ; 
		month_no++)
		no_of_days += 
			days_in(month_no, toDate.year);
	
	return no_of_days + toDate.day;
}

void write_day(int dow)
{
	switch (dow)
	{
		case 0 : 
			puts("Sunday");
			break;
		case 1 : 
			puts("Monday");
			break;
		case 2 : 
			puts("Tuesday");
			break;
		case 3 : 
			puts("Wednesday");
			break;
		case 4 : 
			puts("Thursday");
			break;
		case 5 : 
			puts("Friday");
			break;
		case 6 : 
			puts("Saturday");
			break;
	}
}

int main(void)
{
	char reply;
	struct date birthday;
	long no_of_days;

	do
	{

		printf("Please enter the date of your ");
		printf("birth, in the form: dd mm yy\n");

		birthday = read_date();
		no_of_days = get_day_number(birthday);
		printf("Number of days = %ld\n", no_of_days);
		printf("You were born on a ");
		write_day(no_of_days % 7);
		printf("Do you want to do that again? ");
		reply = getchar();
	} while (reply == 'y' || reply == 'Y');

	return 0;
}

