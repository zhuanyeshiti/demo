#include <stdio.h>

int command(char *command);

int main()
{
	command("vim test");
	return 0;
}

int command(char *command)
{
	int a;
	char buffer[200]={0};
	//char *command;
	//command="lllllll";
	if(command==NULL)
		return -1;

	FILE *fp;

	fp=popen(command,"w");

	while(fgets(buffer,200,fp)!=NULL)
		printf("%s",buffer);
	/*while(getchar()!='b')
	{
		fgets(buffer, 200, fp);
		printf("%s\n", buffer);
	}*/

	pclose(fp);
	return 0;
}
