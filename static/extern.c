#include <stdio.h>

extern int a;

int hello()
{
	int b;
	b=a;
	printf("extern b: %d\n",b);
	return 0;
}
