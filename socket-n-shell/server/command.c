#include <stdio.h>

int command()
{
	int a;
	char buffer[200]={0};
	char *command;
	command="lllllll";
	FILE *fp;

	fp=popen(command,"r");

	while(fgets(buffer,200,fp)!=NULL)
		printf("%s\n",buffer);

	pclose(fp);
	return 0;
}
