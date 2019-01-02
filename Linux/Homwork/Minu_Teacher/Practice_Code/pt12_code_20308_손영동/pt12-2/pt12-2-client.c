#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SIZE sizeof(struct sockaddr_in)
#define NUM	64

int main(int argc, char *argv[])
{
	int sockfd, ret_val;
	struct sockaddr_in server = {AF_INET, 5000};
	pid_t pid[NUM];
	int np, limit;
	
	if(argc != 2)
	{
		printf("usage error\n");
		exit(1);
	}

	limit = atoi(argv[1]);
	for(np = 0; np < limit; np++)
	{
		pid[np] = fork();
		if(pid[np] == 0)
			break;
	}

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("[client(%d,%d)] socket\n", np, getpid());
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(sockfd == -1)
		printf("[client(%d,%d)] fail to call socket()\n", np, getpid());
	
	printf("[client(%d,%d)] connect\n", np, getpid());
	ret_val = connect(sockfd, (struct sockaddr *)&server, SIZE);
	printf("[client(%d,%d)] ret_val is %d\n", np, getpid(), ret_val);
	if(ret_val == 0)
		close(sockfd);	
}
