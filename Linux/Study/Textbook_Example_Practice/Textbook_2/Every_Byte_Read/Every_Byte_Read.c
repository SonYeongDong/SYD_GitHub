#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 1024

int main(void)
{
	int file1, file2;
	int count = 0;

	ssize_t ret;

	char *buf;
	buf = (char*) malloc(SIZE); 

	unsigned long len = SIZE;
	
	file1 = open("readfile.txt", O_RDONLY);
	if(file1 < 0)
	{
		perror("Open file1");
		exit(1);
	}	

	file2 = open("writefile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(file2 < 0)
	{
		perror("Open file2");
		exit(1);
	}

	while(len != 0 &&(ret = read(file1, buf, 1)) != 0)
	{
		count++;
		if(ret == -1)
		{
			if(errno == EINTR)
				 continue;
			perror("read");
			break;
		}

		printf("%s", buf);

		if(write(file2, buf, ret) < ret)
		{
			printf("File Write Fail\n");
			close(file1);
			close(file2);
		}
		len -= ret;
		buf += ret;		
	}
	printf("문자 갯수 %d\n", count);

	close(file1);
	close(file2);
	free(buf);

	return 0;
}
