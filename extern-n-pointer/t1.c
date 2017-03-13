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

#define DEBUG(x) x

void func(int);
//extern int * hello();

int main()
{
	//extern int b;
	int a;
	int *c;
	a=b;
	struct s2 ss;
	//ss=(struct s2*)malloc(sizeof(s2));
	ss.s=(struct s1*)malloc(sizeof(struct s1));
	ss.s->b=(char *)malloc(20);
	ss.s->c=(void *)malloc(50);
	ss.s->b="hello world!";
	printf("%s\n",ss.s->b);
	printf("%d\n",b);
	c=DEBUG(hello());
	if(c==NULL)
		printf("NULL\n");
	ss.s->c=func;
	(*ss.s->c)(1);
	//fn(1);
loop:	if(getchar())
	{
		getchar();
		printf("1\t");
		printf("2\n");
		//ss.s->b=(char *)malloc(1024*1024*1024);	
	}
	goto loop;
	return 0;
}

void func(int i)
{
	printf("fn %d\n",i);
}

















