#include <stdio.h>

extern int command(char *cmd);

int main()
{
	command("ls");
	return 0;
}
