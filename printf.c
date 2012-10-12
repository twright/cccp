#include <stdio.h>

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
	printf("'It was the %s of times,\n", "best");
	printf("%ct was the %s o%x times'\n",  0111, "worst", 15);
	printf("%d %o %x\n", 20, 20, 20);

	return 0;
}
