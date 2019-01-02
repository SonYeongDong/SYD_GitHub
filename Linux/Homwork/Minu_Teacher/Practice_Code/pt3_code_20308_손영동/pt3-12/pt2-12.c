#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	FILE *fp1;

	long size;

	char buffer[60];

	fp1 = fopen("data.txt", "rb");

	fseek(fp1, (off_t)0, SEEK_END);

	size = ftell(fp1);

	while(feof(fp1) == 0)
	{
        	fgets(buffer, sizeof(buffer), fp1);

	}

	printf("size변수의 값 : %ld\n", size);
	printf("feof의 값 : %d\n", feof(fp1));

	fclose(fp1);

	return 0;
}
