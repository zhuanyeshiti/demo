#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int sockfd;
	int len;
	int i;
	struct sockaddr_in addr;
	int result;
	char ch[100];
	char *c;
	c=ch;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	addr.sin_port=htons(8080);
	len=sizeof(addr);
	result=connect(sockfd,(struct sockaddr *)&addr,len);

	i=0;
	while((ch[i]=getchar())!='b')
	{
		getchar();
		if(*ch == 'b')
		{
			i=0;
			write(sockfd,c,100);
		}
		i++;
	}

	return 0;
}
