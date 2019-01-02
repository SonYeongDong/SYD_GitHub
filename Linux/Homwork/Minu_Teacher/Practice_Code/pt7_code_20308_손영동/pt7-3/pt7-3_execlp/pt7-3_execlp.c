#include <stdio.h>
int main(void)
{
	char *arg[] = {"head", "a.txt", "b.txt", "c.txt", (char *)0};
	
	printf(".txt file is\n");
	execlp("head","head", "a.txt", "b.txt", "c.txt", (char *)0);
	
	return 0;
}
