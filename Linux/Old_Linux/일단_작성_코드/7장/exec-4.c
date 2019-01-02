#include <stdio.h>
int main(void)
{
	char *arg[] = {"ls", "-l", (char *)0};
	printf("before executing ls -l\n");
	execv("/bin/ls", arg);
	printf("after excuting ls -l\n");
	
	return 0;
}
