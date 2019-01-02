#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int files;
void exit(void);

void exit(void)
{
	printf("Close files\n");
	close(files);
}


int main(void)
{
	ssize_t nread;
	char buffer[1024];

	atexit(exit);

	files = open("syd.txt", O_RDONLY);
	while((nread = read(files, buffer, 1024)) > 0)
	{
		printf("%s", buffer);
	}	

	return 0;
}
