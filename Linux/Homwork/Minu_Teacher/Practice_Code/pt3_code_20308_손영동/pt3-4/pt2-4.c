#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{

	int filedes;
	off_t newpos;

	filedes = open("data.txt", O_RDONLY); // data.txt 내용 : Hello_My_name_is_Son_Yeong_Dong
	newpos = lseek(filedes, (off_t)10, SEEK_END);
	printf("file size : %d\n", newpos);

}
