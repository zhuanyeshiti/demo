#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

struct a {
	int a;
	int b[0];
};

int main(int a)
{
	int n;
	printf("%d\n",a);
	struct a aa;
	//aa.b[0]=1;
	n=sizeof(aa);
	//n=strlen(aa);
	printf("%d\n",n);
	printf("%d\n",aa.b[0]);
	return 0;
}
