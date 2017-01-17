#include <stdio.h>

extern int a;

int hello()
{
	int b;
	b=5u;
	printf("extern b: %d\n",b);
	return 0;
}
