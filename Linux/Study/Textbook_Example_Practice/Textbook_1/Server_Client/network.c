#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void)
{
	int sockfd;
	char send_c, recv_c;
	struct sockaddr_in server = {AF_INET, htons(5000)};
	server.sin_addr.s_addr = inet_addr("192.168.137.106");

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("fall to call socket()\n");
		exit(1);
	}

	if(connect(sockfd, (struct sockaddr *)&server, SIZE) == -1)
	{
		perror("fall to call connect()\n");
		exit(1);
	}

	recv_c = '\n';
	
	while(1)
	{
		if(recv_c == '\n')
		{
			printf("Input a message\n");
		}
		send_c =  getchar();
		
		send(sockfd, &send_c, 1, 0);

		if(recv(sockfd, &recv_c, 1, 0) > 0)
		{
			printf("%c", recv_c);
		}	

		else
		{
			printf("server has no reply\n");
			close(sockfd);
			exit(1);
		}
	}
}			
