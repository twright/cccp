#include <stdio.h>

int main(void)
{
	int i, *p;

	i = 42;
	p = &i;
	printf("i = %d p = 0x%p and p points to the value %d\n", i, (void*)p, *p);
	i = 0;
	printf("i = %d p = 0x%p and p points to the value %d\n", i, (void*)p, *p);
	*p = -1;
	printf("i = %d p = 0x%p and p points to the value %d\n", i, (void*)p, *p);

	return 0;
}