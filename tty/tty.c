#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL,
};

int getchoice(char *greet, char *choices[], FILE *in, FILE *out);

int main()
{
	int choice = 0;
	FILE *input;
	FILE *output;
	FILE *fp;
	char buffer[200]={0};

	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");
	if(!input || !output)
	{
		fprintf(stderr, "unable to open /dev/tty\n");
		exit(1);
	}
	/*
	do
	{
		choice = getchoice("please select an action", menu, input, output);
		printf("you have chosen: %c\n", choice);
	}while(choice != 'q');
	*/
	while(fgets(buffer, 200, input) != NULL)
	{
		fp = popen(buffer, "r");
		while(fgets(buffer, 200, fp) != NULL)
		{
			fprintf(output, "%s\n", buffer);
			//printf("%s\n", buffer);
		}
		pclose(fp);
	}
	exit(0);
}

int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
	int chosen = 0;
	int selected;
	char **option;
	do
	{
		fprintf(out, "choice: %s\n", greet);
		option = choices;
		while(*option)
		{
			fprintf(out, "%s\n", *option);
			option++;
		}
		do
		{
			selected = fgetc(in);
		}while(selected == '\n');
		option = choices;
		while(*option)
		{
			if(selected == *option[0])
			{
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen)
		{
			fprintf(out, "incorrect choice\n");
		}
	}while(!chosen);
	return selected;
}



