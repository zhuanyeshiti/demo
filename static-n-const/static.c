#include <stdio.h>
#include <stdlib.h>

extern int const_test(char *s);
extern int hello();
int a;
//static int a;
static const int c=1;

int main()
{
	//static int a;
	int *d;
	int *e=NULL;
	int f=10;
	char *s;
	s = "test begin!";
	d=(int *)malloc(sizeof(int));
	*d=c;
	a=1;
	printf("static a: %d\n",a);
	hello();
	*d=2;
	printf("%d\n",*d);
	e=&f;
	*(e+16)=11;
	printf("%p,%p\n",&f,e);
	printf("%d\n",*(e+16));
	const_test(s);
	printf("return to main, the const str is %s.\n", s);
	return 0;
}
