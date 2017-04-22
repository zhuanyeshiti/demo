#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL,
};

struct argument
{
	FILE *input;
	FILE *output;
	FILE *fp;
	char *buf;
};

int getchoice(char *greet, char *choices[], FILE *in, FILE *out);
void *thread_func(void *arg);

int main()
{
	int choice = 0;
	FILE *input;
	FILE *output;
	FILE *fp;

	struct argument *arg = NULL;
	int result;
	pthread_t a_thread;

	char buffer[200]={0};
	int fpi;
	int fpi2;
	int outi;
	char ch;
	char fpbuf[4000];
	char outbuf[4000];

	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");
	if(!input || !output)
	{
		fprintf(stderr, "unable to open /dev/tty\n");
		exit(1);
	}

	arg = (struct argument *)malloc(sizeof(struct argument));
	arg->input = input;
	arg->output = output;
	arg->fp = fp;
	arg->buf = fpbuf;
	result = pthread_create(&a_thread, NULL, thread_func, (void *)arg);

	/*
	do
	{
		choice = getchoice("please select an action", menu, input, output);
		printf("you have chosen: %c\n", choice);
	}while(choice != 'q');
	*/
	while(fgets(buffer, 200, input) != NULL)
	{
		fpi=0;
		fp = popen(buffer, "r");
		//fprintf(output, "allllll");
		while(fgets(buffer, 200, fp) != NULL)
		//while(ch=fgetc(fp) != EOF)
		{
			fpi2=0;
			while(strlen(buffer)!=fpi2)
			{
				fpbuf[fpi]=buffer[fpi2];
				fpi++;
				fpi2++;
			}
			//fpbuf[fpi]=ch;
			//fpi++;
			//fprintf(output, "%s\n", buffer);
			//printf("%s\n", buffer);
			//printf("%c", fpbuf[fpi]);
		}
		fpi2=0;
		while(fpi2!=fpi)
		{
			fprintf(output, "%c", fpbuf[fpi2]);
			fpi2++;
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

void *thread_func(void *arg)
{
	int a;
	char buffer[200] = {0};
	char buf[4000] = {0};
label:	if((((struct argument *)arg)->fp)==NULL)
		goto label;
	while(fgets(buffer, 200, ((struct argument *)arg)->fp) != NULL)
	//while(1)
	{
		fprintf(((struct argument *)arg)->output, "%s\n", buffer); //((struct argument *)arg)->buf);
		if((((struct argument *)arg)->fp)==NULL)
		goto label;
		//printf("%s\n", buffer);
	}

}

