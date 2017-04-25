#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc,char*argv[])
{
	int ret;
	if(argc > 1)
	{
		int pid = atoi(argv[1]);
    	ret = kill(pid,SIGPIPE);
   		 printf("ret : %d",ret);
	}
	return 0;	
}
