#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int filedes ;

	ssize_t nread;

	off_t newpos;
    
	char buffer[1024];
	char content[] = "Hello_My_name_is_Son_Yeong_Dong";
    
	filedes = open("data.txt", O_RDWR | O_CREAT, 0644);

	nread = read(filedes, buffer, 1024);
	printf("읽기 수행후 포인터 위치 : %ld\n", newpos = lseek(filedes, (off_t)0,     SEEK_CUR));
    
	write(filedes, content, strlen(content));    
	printf("쓰기 수행후 포인터 위치 : %ld\n", newpos = lseek(filedes, (off_t)0,     SEEK_CUR));

	close(filedes);
	
	return 0;
}
