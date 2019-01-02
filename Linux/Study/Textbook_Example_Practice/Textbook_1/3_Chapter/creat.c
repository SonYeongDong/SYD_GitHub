#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int file;
	file =  open("syd.txt", O_WRONLY |O_CREAT | O_TRUNC | O_EXCL);

	printf("%d", file);
return 0;
}

