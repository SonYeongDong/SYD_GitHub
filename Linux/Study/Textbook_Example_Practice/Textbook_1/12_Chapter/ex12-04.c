#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#define SIZE sizeof(struct sockaddr_in)
int main(void)
{
	int sockfd;
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = 1004;
	addr.sin_addr.s_addr = INADDR_ANY;
	/* socket()으로 소켓을 생성하는 코드 */
	if(bind(sockfd, (struct sockaddr *)&addr, SIZE) == -1)
	{
		printf("fail to call bind()\n");
		exit(1);
	}
	/* 통신을 위한 나머지 코드들.. */
	close(sockfd);
return 0;
}
