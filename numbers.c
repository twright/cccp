#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long x;
	char s[10];

	while ((x = atoi(fgets(s, 10, stdin))) != 0)
	{
		printf("Decimal : %ld\t octal :0%lo\t ", x, x);
		printf("hex: 0x%lx\tunsigned: %lu\t", x, x);
		printf("char: '%c'\n", (char)x);
		printf("Decimal : %ld\t octal :0%lo\t", x, x);
		printf("hex: 0x%lx\tunsigned: %lu\n",  x, x);
	}
	return 0;
}
