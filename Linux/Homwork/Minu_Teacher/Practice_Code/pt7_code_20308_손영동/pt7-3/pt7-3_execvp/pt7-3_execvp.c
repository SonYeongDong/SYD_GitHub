#include <stdio.h>
int main(void)
{
	char *arg[] = {"head", "a.txt", "b.txt", "c.txt", (char *)0};
	
	printf(".txt file is\n");
	execvp("head", arg);
	
	return 0;
}
