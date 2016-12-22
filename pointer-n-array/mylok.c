#include <stdio.h>
#include <stdlib.h>

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
	int a;
	a=1;
	struct s1 *ss1;
	ss1=(struct s1 *)malloc(sizeof(struct s1));
	struct s2 ss;
	ss.s=ss1;
	ss.s->a=2;
	ss.s->b="hello world!";
	//printf("%s\n",ss.s->b);
	//ss.s->c=func;
	//(*ss.s->c)(1);
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

















