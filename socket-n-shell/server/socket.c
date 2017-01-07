#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//extern int command(char *cmd);

void *thread_func(void *arg);
char *message;

int main()
{
	int result;
	pthread_t a_thread;
	void *thread_result;
	message="hello!";
	result=pthread_create(&a_thread,NULL,thread_func,(void *)message);
	if(result!=0)
	{
		printf("something wrong!\n");
		exit(0);
	}

	result=pthread_join(a_thread,&thread_result);
	if(result!=0)
	{
		printf("something wrong with join!\n");
		exit(0);
	}

	printf("thread join and return %s\n",(char *)thread_result);

	//command("ls");
	return 0;
}


void *thread_func(void *arg)
{
//	command("ls");

//	pthread_exit("thread done!\n");
}




