#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int file;

	ssize_t nread;

	char buffer[1];

	int i=0;

	file = open("data.txt", O_RDONLY);

	while((nread = read(file, buffer, 1)) > 0)

	while(buffer[i])
	{
		if(buffer[i] >= 97 && buffer[i] <= 122)
		{
			buffer[i] = toupper(buffer[i]);
		}
		i++;
	}

	printf("%s\n", buffer);
	
	close(file);

	return 0;
}
