#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


extern int command(char *cmd);

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

	//command("sudo -i");
	return 0;
}


void *thread_func(void *arg)
{
	int server_fd,client_fd;
	int server_len,client_len;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	server_fd=socket(AF_INET,SOCK_STREAM,0);
	server_addr.sin_family=AF_INET;
//	server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	server_addr.sin_port=htons(8080);
	server_len=sizeof(server_addr);
	bind(server_fd,(struct sockaddr *)&server_addr,server_len);
	listen(server_fd,5);
	while(1)
	{
		char ch;
		int res;
		client_len=sizeof(client_addr);
		client_fd=accept(server_fd,(struct sockaddr *)&client_addr,(socklen_t *)&client_len);
		while(1)
		{
			res=read(client_fd,&ch,100);
			printf("the first: %c\n",ch);
//			sleep(3);
			command(&ch);
			if(res==0)
				break;
		}
		read(client_fd,&ch,100);
		printf("the second: %c\n",ch);
		close(client_fd);
	}

	command("sudo -i");
	//command("vim test");

	pthread_exit("thread done!\n");
}




