#include <stdio.h>
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
//#include <Linux/limits.h>
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
		char temp[50] = {"hello world!"};
		char temp2[100] = {'\0'};
		c = write(mpty, temp, 5);
		if(c <= 0)
		{
			printf("error.\n");
		}
		sleep(1);
		printf("write %d charactor to mpty.\n", c);
		sleep(1);
		printf("try to read from mpty.\n");
		sleep(1);
		c = read(mpty, temp2, 5);
		if(c <= 0)
		{
			printf("error.\n");
		}
		printf("read fro mpty %d charactors success.\n", c);
		printf("/n %s /n\n", temp2);
		
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

		fpid = fork();
		if(fpid<0)
		{
			printf("fail!\n");
		}
		else if(fpid == 0)
		{
			dup2(mpty, STDIN_FILENO);
			dup2(mpty, STDOUT_FILENO);
			//dup2(mpty, STDERR_FILENO);
			//close(mpty);
			printf("child\n");
			execl("/bin/sh", "sh", "-c", "vim file", (char *)0);
		}
		else
		{
			printf("parent.\n");
			//execl("/bin/sh", "sh", "-c", "ls -l", (char *)0);
		}
	}
	return 0;
}
