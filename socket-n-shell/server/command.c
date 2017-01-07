#include <stdio.h>

int command(char *command)
{
	int a;
	char buffer[200]={0};
	//char *command;
	//command="lllllll";
	if(command==NULL)
		return -1;

	FILE *fp;

	fp=popen(command,"r");

	while(fgets(buffer,200,fp)!=NULL)
		printf("%s\n",buffer);

	pclose(fp);
	return 0;
}
