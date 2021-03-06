#include <stdio.h>
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
//#include <Linux/limits.h>
#include <time.h>
#include <pty.h> // for openpty() & forkpty()
#include <utmp.h> // for login_pty

int main(int argc, char *argv[])
{
	int rtnVal = 0;
	int mpty, spty, c=0, dev=0;
	int in, out;
	char *pName=NULL;
	char ptyBuff[100]={'\0'};
	char sptyname[20]={'\0'};
	pid_t fpid;
	rtnVal = openpty(&mpty, &spty, sptyname, NULL, NULL);
	if(rtnVal != -1)
	{
	//	pName = ptsname(mpty);
	//	printf("slave name is %s, fd = %d.\n", pName, spty);
	//	strcpy(sptyname, pName);
		printf("my sptyname is %s.\n", sptyname);
		/*
		 * test write to and read from spty.
		 */
		char temp[50] = {"hello world!\n"};
		char temp2[100] = {'\0'};
		c = write(mpty, temp, strlen(temp));
		if(c <= 0)
		{
			printf("error.\n");
		}
		sleep(1);
		printf("write %d charactor to mpty.\n", c);
		sleep(1);
		printf("try to read from mpty.\n");
		sleep(1);
		c = read(spty, temp2, strlen(temp));
		if(c <= 0)
		{
			printf("error.\n");
		}
		printf("read fro mpty %d charactors success.\n", c);
		printf("/n %s", temp2);
		
		/*
		 * end
		 */

		/*
		 * open file.
		 */
		in = open("input", O_RDWR);
		out = open("output", O_RDWR);
		/*
		 * end
		 */

		char * temp3;
		char temp4[200] = {'\0'};
		fpid = fork();
		if(fpid<0)
		{
			printf("fail!\n");
		}
		else if(fpid == 0)
		{
			dup2(spty, STDIN_FILENO);
			dup2(spty, STDOUT_FILENO);
			//dup2(mpty, STDERR_FILENO);
			close(mpty);
			printf("child\n");
			//execl("/bin/sh", "sh", "-c", "vim file", (char *)0);
			execl("/bin/sh", "sh", "-c", "ls", (char *)0);
			//c = read(spty, temp3, strlen(temp3));
		}
		else
		{	
			//temp3 = ":wq\n";
			//c = write(mpty, temp3, strlen(temp));
			sleep(1);
			while(c = read(mpty, temp4, 200))
			{
				//c = read(mpty, temp3, 100);
				//must use char temp4 = {'\0'};
				//instead of char * temp3;
				printf("parent.\n");
				printf("%s", temp4);
			}
			//sleep(1);
			//execl("/bin/sh", "sh", "-c", "ls -l", (char *)0);
		}
	}
	return 0;
}
