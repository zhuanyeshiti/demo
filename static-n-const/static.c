#include <stdio.h>
#include <stdlib.h>

extern int hello();
int a;
//static int a;
static const int c=1;

int main()
{
	//static int a;
	int *d;
	d=(int *)malloc(sizeof(int));
	*d=c;
	a=1;
	printf("static a: %d\n",a);
	hello();
	*d=2;
	printf("%d\n",*d);
	return 0;
}
