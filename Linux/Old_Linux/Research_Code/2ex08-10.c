#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *envlist[] = {"APPLE=0", "BANANA=1", (char*)0 };

	execle("2ex08-11", "2ex08-11", (char *)0, envlist);

	return 0;
}
