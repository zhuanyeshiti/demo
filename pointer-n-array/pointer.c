#include <stdio.h>
#include <stdlib.h>

#define OK(i)	if(i==5) continue

int main()
{
	char *s;
	char *p;
	s=malloc(1024);
	p=s;
	*p='b';
	*s='a';
	//s="abcdefg";
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d\n",i);
		OK(i);
	//	if(i==5)
	//		continue;
		printf("hello!\n");
	}
	//printf("%c\n",*s);
	printf("%s\n",p);
	printf("%s\n",s);
	printf("%c\n",*p);
	printf("%p\n",p);
	printf("%p\n",s);

	int *aa;
	int *bb;
	int *cc;
	int dd;
	aa=bb=cc=&dd;
	bb=aa+8;
	cc=bb+8;
	*aa=1;
	*bb=2;
	*cc=3;
	printf("%p:",aa);
	printf("%d\n",*aa);
	printf("%p:",bb);
	printf("%d\n",*bb);
	printf("%p:",cc);
	printf("%d\n",*cc);


	return 0;
}
