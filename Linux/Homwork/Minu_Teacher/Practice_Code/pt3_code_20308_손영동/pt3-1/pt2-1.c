#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) 
{
	int filedes, fdnew1, fdnew2;
	ssize_t nread;
	off_t newpos;

	char buffer[1024];
	char content[] = "Helloworld\n";

	filedes = open("data.txt", O_RDWR);

	if(filedes == -1) 
	{
		printf("파일 open오류!\n");
		exit(1);
	}

	nread = read(filedes, buffer, 1024);

	if(nread == -1) 
	{
		printf("파일 read 오류\n");
		exit(1);
	}

	printf("%s", buffer);
	
	write(filedes, content, strlen(content));

	newpos = lseek(filedes, (off_t)0, SEEK_SET);
	nread = read(filedes, buffer, 1024);
	printf("%s", buffer);

	close(filedes);

	fdnew1 = open("newdata1.txt", O_RDWR | O_CREAT, 0644);
	fdnew2 = creat("newdata2.txt", 0644);

	close(fdnew1);
	close(fdnew2);

	return 0;
}
