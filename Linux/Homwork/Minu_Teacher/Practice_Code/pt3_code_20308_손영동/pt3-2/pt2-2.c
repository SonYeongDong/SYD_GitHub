#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int filedes;

	filedes = open("/home/syd/temp0.txt", O_CREAT | O_RDWR, 0644); //절대경로
	//filedes = open("~/temp0.txt", O_CREAT | O_RDWR, 0644); 상대경로
	
	close(filedes);
	
	return 0;
}
