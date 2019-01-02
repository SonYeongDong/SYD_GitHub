#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("before %d\n", getpid());
	//pid = fork();
	printf("after %d %d\n",getpid(), pid);
	
	//system("ls");

#if 1
	if(pid < 0)
	{
		perror("error");
	}	

	else if(pid == 0)
	{
		execl("ls",....);
		exit(0);
		//printf("child\n");
	}	

	else
	{
		printf("parent\n");
	}
	while(1)
		sleep(1);
	
	return 0;
#endif
}
