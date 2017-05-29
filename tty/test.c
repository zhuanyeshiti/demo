#include <stdio.h>
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
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
		 * test write to mpty and read from spty.
		 */
		char temp[50] = {"hello\n world!"};
		char temp2[100] = {'\0'};
		c = write(mpty, temp, 6);
		if(c <= 0)
		{
			printf("error.\n");
		}
		c = read(mpty, temp2, 5);
		if(c <= 0)
		{
			printf("error.\n");
		}
		printf("read fro spty %d charactors success.\n", c);
		printf("/n %s /n\n", temp2);
		/*
		 * end
		 */
	}
	return 0;
}
