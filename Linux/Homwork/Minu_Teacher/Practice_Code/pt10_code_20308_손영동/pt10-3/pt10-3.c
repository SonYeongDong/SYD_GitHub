#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(void)
{
	sigset_t set;
	int count = 1;
	
	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, NULL);
	
	while(count <= 10)
	{
		if(count <= 5)
		{
			printf("don't distrub me (%d)\n", count);
		}
		else
		{
			if(count == 6)
			{
				sigemptyset(&set);
				sigaddset(&set, SIGINT);
				sigprocmask(SIG_UNBLOCK, &set, NULL);
			}
			printf("disturb me ..\n");
		}
		sleep(1);
		count++;
	}
return 0;
}
