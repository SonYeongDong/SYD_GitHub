//#defind _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SIZE (1024*1024*100)

int main(void)
{
	char *buf;
	int file1, file2;
	clock_t f1_time1, f1_time2, f1_time3, f2_time1, f2_time2, f2_time3;

	buf = (char*) malloc(SIZE);


	file1 = open("Normal_File", O_RDWR | O_CREAT | O_TRUNC, 0664);
	file2 = open("O_SYNC_File", O_RDWR | O_CREAT | O_TRUNC | O_SYNC, 0664);
	
	f1_time1 = clock();
	write(file1, buf, SIZE);
	f1_time2 = clock();
	read(file1, buf, SIZE);
	f1_time3 = clock();

	f2_time1 = clock();
	write(file1, buf, SIZE);
	f2_time2 = clock();
	read(file1, buf, SIZE);
	f2_time3 = clock();

	close(file1);
	close(file2);
	
	printf("N_W : %ld | N_R : %ld\n", f1_time2-f1_time1, f1_time3-f1_time2);
	printf("S_W : %ld | S_R : %ld\n", f2_time2-f2_time1, f2_time3-f2_time2);

	free(buf);
	return 0;
}

