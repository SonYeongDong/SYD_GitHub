#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	off_t newpos;
	
	fd = open("test.txt", O_RDONLY);
	
	newpos = lseek(fd, (off_t)8, SEEK_END);
	
	printf("fill size : %d\n", newpos);

	return 0;
}
