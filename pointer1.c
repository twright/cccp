#include <stdio.h>

int main(void)
{
	int i, *p;

	i = 42;
	p = &i;
	printf("i = %d p = 0x%x and p points to the value %d\n", i, p, *p);
	i = 0;
	printf("i = %d p = 0x%x and p points to the value %d\n", i, p, *p);
	*p = -1;
	printf("i = %d p = 0x%x and p points to the value %d\n", i, p, *p);

	return 0;
}