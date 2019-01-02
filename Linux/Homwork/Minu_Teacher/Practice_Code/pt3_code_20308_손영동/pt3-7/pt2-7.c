#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) 
{
	int filedes;
	ssize_t nread;

	char buffer[1024];

	int i=0;
	int count=0; 

	filedes = open("data.txt", O_RDONLY);

	while((nread = read(filedes, buffer, 1024)) > 0)

	while(buffer[i])
	{
		if((buffer[i] >= 65 && buffer[i] <= 90) || (buffer[i] >= 97 && buffer[i] <= 122))
		{
			count++;
		}
		i++;
	}

	printf("%d\n", count);
	
	close(filedes);

	return 0;
}
