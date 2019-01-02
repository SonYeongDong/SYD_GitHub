#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int nc;
void alarm_action(int);

int main(void)
{
	int filedes[2];
	char msg = 'A';
	
	struct sigaction act;
	
	act.sa_handler = alarm_action;
	sigfillset(&(act.sa_mask));
	
	if(pipe(filedes) == -1) 
	{
		printf("fail to call pipe()\n");
		exit(1);
	}
	
	printf("PIPE size : %d bytes\n", fpathconf(filedes[1], _PC_PIPE_BUF));
	nc = 0;
	
	sigaction(SIGALRM, &act, NULL);
	//alarm(1);

	while(1) 
	{
		write(filedes[1], &msg, 1);
		nc++;
	}

	return 0;
}

void alarm_action(int signo)
{
	printf("\n\nblocked after %d characters\n", nc);
	exit(1);
}
