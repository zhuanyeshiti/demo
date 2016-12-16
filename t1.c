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
	return 0;
}
