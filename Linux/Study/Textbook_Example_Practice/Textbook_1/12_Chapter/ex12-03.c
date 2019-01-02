#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void)
{
	int sockfd;
	if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("fail to call socket()\n");
		exit(1);
	}
	printf("socket descriptor is %d\n", sockfd);
	/* 소켓을 통한 통신 기능을 수행한다. */
	close(sockfd);
}
