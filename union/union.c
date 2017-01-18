#include <stdio.h>

union xhci_trb {
	int a;
	char b;
};

int main()
{
	union xhci_trb trb;
	int c;
	trb.a=1;
	trb.b='a';
	printf("%d\n",sizeof(trb));
	printf("%d,%d\n",trb.a,trb.b);
	return 0;
}
