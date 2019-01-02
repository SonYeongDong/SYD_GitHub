#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	char filename[64];
	int n;

	for(n = 1; n < argc; n++)
	{
		strcpy(filename, argv[n]);
		printf("Run \"wc %s\"\n", filename);
		pid = fork();
		if(pid == 0)
		{
			execlp("wc", "wc", filename, (char *)0);
			exit(1); 
		}
	}
	return 0;
}
