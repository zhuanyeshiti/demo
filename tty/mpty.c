#include <stdio.h>
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
//#include <Linux/limits.h>
#include <pty.h> // for openpty() & forkpty()
#include <utmp.h> // for login_pty

int main(int argc, char *argv[])
{
	int rtnVal = 0;
	int mpty, spty, c=0, dev=0;
	char *pName=NULL;
	char ptyBuff[100]={'\0'};
	char sptyname[20]={'\0'};
	rtnVal = openpty(&mpty, &spty, sptyname, NULL, NULL);
	if(rtnVal != -1)
	{
		pName = ptsname(mpty);
		printf("slave name is %s, fd = %d.", pName, spty);
		strcpy(sptyname, pName);
		printf("my sptyname is %s.", sptyname);
		/*
		 * test write to and read from spty.
		 */
		char temp[50] = {"hello world!"};
		char temp2[100] = {'\0'};
		c = write(mpty, temp, 5);
		if(c <= 0)
		{
			printf("error.");
		}
		sleep(3);
		printf("write %d charactor to mpty.", c);
		sleep(3);
		printf("try to read from mpty.");
		sleep(3);
		c = read(mpty, temp2, 5);
		if(c <= 0)
		{
			printf("error.");
		}
		printf("read fro mpty %d charactors success.", c);
		printf("/n %s /n", temp2);

		/*
		 * end
		 */
	}
	return 0;
}
