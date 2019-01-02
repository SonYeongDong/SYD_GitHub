#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SIZE sizeof(struct sockaddr_in)
#define MSGLEN 1024

int main(void)
{
	int sockfd, nread;
	char send_c[1024], recv_c[1024];
	struct sockaddr_in server = {AF_INET, 5000};
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("fail to call socket()\n");
		exit(1);
	}
	
	if(connect(sockfd, (struct sockaddr *)&server, SIZE) == -1)
	{
		printf("fail to call connect()\n");
		exit(1);
	}
	recv_c[0] = '\0';

	while(1)
	{
		if(strlen(recv_c) == 0)
			printf("Input a message\n");
		fgets(send_c, MSGLEN, stdin);
		send(sockfd, send_c, strlen(send_c), 0);
		if((nread = recv(sockfd, recv_c, MSGLEN, 0)) > 0)
		{
			printf("%s\n", recv_c);
		}
		else
		{
			printf("server has no reply\n");
			close(sockfd);
			exit(1);
		}
	}
	return 0;
}
