#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SIZE sizeof(struct sockaddr_in)

int main(int argc, char *argv[])
{
	int sockfd_listen, sockfd_connect;
	int ret, backlog;
	struct sockaddr_in server = {AF_INET, 5000, INADDR_ANY};
	
	if(argc != 2)
	{
		printf("usage error!!\n");
		exit(1);
	}

	backlog = atoi(argv[1]);
	sockfd_listen = socket(AF_INET, SOCK_STREAM, 0);
	ret = bind(sockfd_listen, (struct sockaddr *)&server, SIZE);

	if(ret == -1)
	{
		printf("[server] error on bind!!\n");
	}

	printf("[server] listen\n");
	listen(sockfd_listen, backlog);
	sleep(10);

	while(1)
	{
		printf("[server] accept!\n");
		sockfd_connect = accept(sockfd_listen, NULL, NULL);
		printf("[server] accepted (%d)\n", sockfd_connect);
		//sleep(1);
		close(sockfd_connect);
		printf("[server] connection lost\n");
	}
}
