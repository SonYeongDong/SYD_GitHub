#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h> 

int num = 0;
int i = 1;

int main(void)
{
	static struct sigaction act;


	void int_handle(int);


	act.sa_handler = int_handle;

	sigfillset(&(act.sa_mask));


	for(i = 1; i <= 64; i++)
	{ 
		if(sigaction((i), &act, NULL) < 0)
		{
			printf("SIGNAL : %d\n",i);
		}	
	}

	return 0;

}

void int_handle(int signum)
{
	printf("SIGINT:%d\n", signum);
	printf("int_handle called %d times\n", ++num);
}
