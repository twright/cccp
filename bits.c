#include <stdio.h>

int main(void)
{
	int result, num1 = 7, num2 = 2;

	result = -num1;	/* result = -7 */
	printf("%8.x\n", result);
	result = ~num2;	/* result = -3 */
	/*  num2 == 0 000 000 000 000 010
	   ~num2 == 1 111 111 111 111 101 */
	printf("%8.x\n", result);
	result = !num1;	/* result = 0 */
	/* 0 becomes 1, any other number because 0 */
	/* 0 represents FALSE anything else is
	   treated as TRUE more later... */
	printf("%8.x\n", result);

	return 0;
}
