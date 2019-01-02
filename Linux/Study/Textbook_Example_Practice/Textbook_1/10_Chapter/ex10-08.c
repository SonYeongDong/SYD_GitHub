#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
	printf("pause return %d\n", pause());
	return 0;
}
