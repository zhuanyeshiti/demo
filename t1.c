#include <stdio.h>

int main()
{
	int i;
	i=0;
	if(getchar()=='a'&&++i)
	{
		getchar();
		printf("good: %d\n",i);
	}
	else
	{
		getchar();
		printf("good: %d\n",i);
	}
	return 0;
}
