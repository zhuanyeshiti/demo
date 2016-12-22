#include <stdio.h>
#include <stdlib.h>
#include "hello.h"

struct s1{
	int a;
	char *b;
	void (*c)(int);
};

struct s2{
	struct s1 *s;
	int c;
};

void func(int);

int main()
{
	//extern int b;
	int a;
	a=b;
	struct s2 ss;
	//ss=(struct s2*)malloc(sizeof(ss));
	ss.s->b="hello world!";
	printf("%s\n",ss->s->b);
	printf("%d\n",b);
	hello();
	ss.s->c=func;
	(*ss.s->c)(1);
	//fn(1);
loop:	if(getchar())
	{
		getchar();
		printf("1\t");
		printf("2\n");
	}
	goto loop;
	return 0;
}

void func(int i)
{
	printf("fn %d\n",i);
}

















