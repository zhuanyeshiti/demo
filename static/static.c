#include <stdio.h>

extern int hello();
int a;
//static int a;

int main()
{
	//static int a;
	//int a;
	a=1;
	printf("static a: %d\n",a);
	hello();
	return 0;
}
