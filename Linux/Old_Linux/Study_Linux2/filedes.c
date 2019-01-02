#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int filedes;
	char pathname[] = "temp.txt";

	if((filedes  = open(pathname, O_CREAT | O_RDWR, 0644))
	==-1)
	{
		printf("file open error!\n");
		exit(1); 
	}
	close(filedes);

/*int fd;
	fd = open("temp.txt", O_RDWR | O_CREAT | O_EXCL, 0664);
if (fd  < 0)
	perror("My Mesg");
*/
}
