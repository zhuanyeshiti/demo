
#include <stdio.h>

int const_test(const char *s)
{
	printf("the string is %s.\n", s);
	s = "hello, world!\n";
	printf("the change const string is %s.\n", s);
	return 0;
}
