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
	int c[10]={
		1,2,3,4,5,6,7,8,9,10,
	};
	printf("%d\n",a);
	struct a aa;
	//aa.b[0]=1;
	n=sizeof(aa);
	//n=strlen(aa);
	printf("%d\n",n);
	printf("%d\n",aa.b[0]);
	printf("%d\n",c[3-1]);
	return 0;
}
