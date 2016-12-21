#include <stdio.h>

int func(void);

int main()
{
	func();
	return 0;
}


int func(void)
{
	char a;
	a=getchar();
	getchar();
	if(a=='h')
		return 0;
	else
		func();
}
