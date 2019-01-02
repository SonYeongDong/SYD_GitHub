#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	
	pid = fork();

	if(pid > 0)
	{	
		sleep(1);
		printf("done parent jop!\n");
	}

	else if(pid == 0)
	{
		while(1)
		{
			printf("doing child job\n");
			sleep(10);	
		}
	}

	else
	{
		printf("fail to fork\n");
		printf("bye!\n");
	}
}
