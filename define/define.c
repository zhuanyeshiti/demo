#include <stdio.h>

#define MASK 0xf

int main()
{
	printf("MASK:		%x\n", MASK);
	printf("~MASK:		%x\n", ~MASK);
	printf("~MASK<<12:	%x\n", ~MASK<<12);
	printf("(u64)MASK:	%llx\n", (unsigned long long)(MASK));
	printf("(u64)~MASK:	%llx\n", (unsigned long long)(~MASK));
	return 0;
}
