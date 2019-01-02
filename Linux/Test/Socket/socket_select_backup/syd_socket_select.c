#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define SIZE sizeof(struct sockaddr_in)
#define BUF 1024

int main(void)
{
	int sockfd_listen;
	int sockfd_connect;
	char buf[BUF] = {0};

	int filehtml;
	ssize_t readhtml;
	char bufhtml[BUF] = {0};
	int lenhtml = 0;
	int readhtml_flag = 0;
	int conect_flag = 0;
	char code_go[BUF] = {0};
	
	char *pas_html;
	char html_1[BUF] = {0};
	char html_2[BUF] = {0};
	char html_3[BUF] = {0};
	char localpath[BUF] = {0};
	char header_html[BUF] = {0};

	struct stat finfo;
	//--------------------------------------------------------------------------	

	struct sockaddr_in server;

	server.sin_family = AF_INET; 
	server.sin_port = htons(5000);
	server.sin_addr.s_addr = htonl(INADDR_ANY);;

	//--------------------------------------------------------------------------	

	printf("손영동의 홈페이지 서버를 실행합니다\n");
	printf("로컬호스트 : 127.0.0.1\n");
	printf("포트번호 : 5000\n\n");

	printf("socket 요청중입니다\n");
	if((sockfd_listen = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("socket 요청에 실패했습니다\n");
		perror("오류 원인 : ");
		printf("\n프로그램을 종료합니다\n");
		exit(1);
	}
	printf("socket 요청에 성공했습니다\n");
	printf("----------------------------------\n");

	//--------------------------------------------------------------------------	

	printf("bind 요청중입니다\n");
	if((bind(sockfd_listen, (struct sockaddr *)&server, SIZE)) == -1)
	{
		printf("bind 요청에 실패했습니다\n");
		perror("오류 원인 : ");
		printf("\n프로그램을 종료합니다\n");
		exit(1);
	}	
	printf("bind 요청에 성공했습니다\n");
	printf("----------------------------------\n");

	//--------------------------------------------------------------------------	

	printf("listen 요청중입니다\n");
	if((listen(sockfd_listen, 5)) == -1)
	{
		printf("listen 요청에 실패했습니다\n");
		perror("오류 원인 : ");
		printf("\n프로그램을 종료합니다\n");
		exit(1);
	}	
	printf("listen 요청에 성공했습니다\n");	
	printf("----------------------------------\n");

	//--------------------------------------------------------------------------	
	while(1)
	{
		if(conect_flag == 0)
		{
			printf("client를 기다리는 중입니다\n");
			conect_flag = 1;
		}
		else
		{
			printf("client 재요청을 기다리는 중입니다\n");
		}
		
		if((sockfd_connect = accept(sockfd_listen, NULL, NULL)) == -1)
		{
			printf("client 연결에 실패했습니다\n");
			perror("오류 원인 : ");
			printf("\n프로그램을 종료합니다\n");
			exit(1);
		}
		printf("client와 연결되었습니다\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

		//--------------------------------------------------------------------------	
		
		recv(sockfd_connect, buf,sizeof(buf),0);
		//perror("Recieve");

		printf("응답한 값\n\n");
		printf("%s\n", buf);

		pas_html = strtok(buf, " ");
		
		sprintf(html_1, "%s", pas_html);
		pas_html = strtok(NULL, " ");
		sprintf(html_2, "%s", pas_html);
		pas_html = strtok(NULL, " ");
		pas_html[8] = '\0';
		sprintf(html_3, "%s", pas_html);
		
		sprintf(header_html, "%s %s %s", html_1, html_2, html_3); 

		printf("----------------------------------\n");
		printf("html header 출력\n");
		printf("%s\n", header_html);
		printf("----------------------------------\n");
		
		//--------------------------------------------------------------------------	
		
		if(!strcmp(html_1, "GET"))
		{	
			if(!strcmp(html_2, "/"))
			{
				readhtml_flag = 0;
				if((filehtml = open("syd_socket_select.html", O_RDWR)) == -1)
				{
					printf("html파일을 여는데 문제가 생겼습니다\n");
					perror("오류 원인 : ");	
					readhtml_flag = 1;
				}

				fstat(filehtml, &finfo);
				if(readhtml_flag == 0)
				{
					printf("다음 html소스를 보내겠습니다\n");
					
					lenhtml = finfo.st_size;
					sprintf(code_go, "HTTP/1.1 200 ok\r\nContent-Length: %d\r\nContent-Type:text/html\r\n\n", lenhtml);	
					send(sockfd_connect, code_go, strlen(code_go), 0);
					
					while((readhtml = read(filehtml, bufhtml, BUF)) > 0)
					{
						printf("%s\n", bufhtml);		
						send(sockfd_connect, bufhtml, BUF, 0);
					}
					
					printf("----------------------------------\n");
					printf("html소스 길이는 : %d\n", lenhtml);			
					printf("----------------------------------\n");
					printf("server 파일 전송이 완료되었습니다\n");	
				}
					
				else if(readhtml_flag == 1)
				{
					sprintf(code_go, "HTTP/1.1 200 OK\nContent-Length: 13\nContent-Type: text/plain\n\r\n404 Not Found");
					send(sockfd_connect, code_go, strlen(code_go)+1, 0);
				}
			}

			else
			{	
				sprintf(localpath, ".%s",html_2 );
				
				readhtml_flag = 0;
				if((filehtml = open(localpath, O_RDWR)) == -1)
				{
					printf("파일을 여는데 문제가 생겼습니다\n");
					perror("오류 원인 : ");	
					readhtml_flag = 1;
				}

				fstat(filehtml, &finfo);
				if(readhtml_flag == 0)
				{
					
					printf("client가 원하는 소스를 보내겠습니다\n");	
			
					lenhtml = finfo.st_size;
					sprintf(code_go, "HTTP/1.1 200 ok\r\nContent-Length: %d\r\nContent-Type:text/html\r\n\n", lenhtml);	
					send(sockfd_connect, code_go, strlen(code_go), 0);

					while((readhtml = read(filehtml, bufhtml, BUF)) > 0)
					{
						//printf("%s\n", bufhtml);
						send(sockfd_connect, bufhtml, BUF, 0);
					}
					
					printf("----------------------------------\n");
					printf("소스 길이는 : %d\n", lenhtml);	
					printf("----------------------------------\n");
					printf("server 파일 전송이 완료되었습니다\n");	
				}

				else if(readhtml_flag == 1)
				{
					sprintf(code_go, "HTTP/1.1 200 OK\nContent-Length: 13\nContent-Type: text/plain\n\r\n404 Not Found");
					send(sockfd_connect, code_go, strlen(code_go)+1, 0);
				}
			}
		}

		else
		{
			printf("POST 입니다\n");
		}	

		//--------------------------------------------------------------------------	

		close(filehtml);
		printf("----------------------------------\n\n\n");
	}	

	//--------------------------------------------------------------------------	

	printf("\nsocket 연결을 종료합니다\n");
	close(sockfd_listen);
	close(sockfd_connect);

	return 0;
}
