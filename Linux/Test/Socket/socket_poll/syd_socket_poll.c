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
#include <sys/poll.h>

#define SIZE sizeof(struct sockaddr_in)
#define BUF 1024
#define CLIENT_MAX 50

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

	int i = 0;
	int count = 0;	
	int nread = 0;

	socklen_t clilen;
	struct pollfd client_p[CLIENT_MAX + 1];

	struct stat finfo;

	//--------------------------------------------------------------------------	

	struct sockaddr_in server, client;

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
		perror("오류 원인");
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
		perror("오류 원인");
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
		perror("오류 원인");
		printf("\n프로그램을 종료합니다\n");
		exit(1);
	}	
	printf("listen 요청에 성공했습니다\n");	
	printf("----------------------------------\n");

	//--------------------------------------------------------------------------	

	client_p[0].fd = sockfd_listen;
	client_p[0].events = POLLIN;

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

		if(poll(client_p, count + 1, -1) < 0)
		{
			perror("poll() 오류 원인");
			continue;
		}

		for(i = 0; i <= count; i++)
		{
			if(client_p[i].revents & POLLIN)
			{
				if(i == 0)
				{
					clilen = sizeof(client);
					if((sockfd_connect = accept(sockfd_listen, (struct sockaddr *)&client,&clilen)) == -1)
					{		
						printf("client 연결에 실패했습니다\n");
						perror("오류 원인");
						printf("\n프로그램을 종료합니다\n");
						exit(1);
					}
					++count;

					if((count) > CLIENT_MAX)
					{
						printf("Sever 할당 최대치입니다!! (50/50)\n");
					}

					else
					{
						client_p[count].fd = sockfd_connect;
						client_p[count].events = POLLIN;
						printf("server 할당 공간이 남아있습니다[%d/50]\n", count);
						printf("연결된 client ip %s\n",inet_ntoa(client.sin_addr));
						printf("연결된 client port %d\n\n",ntohs(client.sin_port));
					}
				}
				else
				{	

					printf("client와 연결되었습니다\n");
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

					//--------------------------------------------------------------------------	

					if((nread = recv(client_p[i].fd, buf,sizeof(buf),0)) < 0)
					{	
						perror("Recieve 오류 원인");
					}

					else if(nread == 0)
					{
						close(client_p[i].fd);
						printf("Client %d를 close합니다\n", i);

						client_p[i] = client_p[count--];
						printf("server 할당 공간이 남아있습니다[%d/50]\n", count);
					}

					else
					{
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
								if((filehtml = open("syd_socket_poll.html", O_RDWR)) == -1)
								{
									printf("html파일을 여는데 문제가 생겼습니다\n");
									perror("오류 원인");	
									readhtml_flag = 1;
								}

								fstat(filehtml, &finfo);
								if(readhtml_flag == 0)
								{
									printf("다음 html소스를 보내겠습니다\n");

									lenhtml = finfo.st_size;
									sprintf(code_go, "HTTP/1.1 200 ok\r\nContent-Length: %d\r\nContent-Type:text/html\r\n\n", lenhtml);	
									send(client_p[i].fd, code_go, strlen(code_go), 0);

									while((readhtml = read(filehtml, bufhtml, BUF)) > 0)
									{
										printf("%s\n", bufhtml);		
										send(client_p[i].fd, bufhtml, BUF, 0);
									}

									printf("----------------------------------\n");
									printf("html소스 길이는 : %d\n", lenhtml);			
									printf("----------------------------------\n");
									printf("server 파일 전송이 완료되었습니다\n");	
								}

								else if(readhtml_flag == 1)
								{
									sprintf(code_go, "HTTP/1.1 200 OK\nContent-Length: 13\nContent-Type: text/plain\n\r\n404 Not Found");
									send(client_p[i].fd, code_go, strlen(code_go)+1, 0);
								}
							}

							else
							{	
								sprintf(localpath, ".%s",html_2 );

								readhtml_flag = 0;
								if((filehtml = open(localpath, O_RDWR)) == -1)
								{
									printf("파일을 여는데 문제가 생겼습니다\n");
									perror("오류 원인");	
									readhtml_flag = 1;
								}

								fstat(filehtml, &finfo);
								if(readhtml_flag == 0)
								{

									printf("client가 원하는 소스를 보내겠습니다\n");	

									lenhtml = finfo.st_size;
									sprintf(code_go, "HTTP/1.1 200 ok\r\nContent-Length: %d\r\nContent-Type:image/jpeg\r\n\n", lenhtml);	
									send(client_p[i].fd, code_go, strlen(code_go), 0);

									while((readhtml = read(filehtml, bufhtml, BUF)) > 0)
									{
										//printf("%s\n", bufhtml);
										send(client_p[i].fd, bufhtml, BUF, 0);
									}

									printf("----------------------------------\n");
									printf("소스 길이는 : %d\n", lenhtml);	
									printf("----------------------------------\n");
									printf("server 파일 전송이 완료되었습니다\n");	
								}

								else if(readhtml_flag == 1)
								{
									sprintf(code_go, "HTTP/1.1 200 OK\nContent-Length: 13\nContent-Type: text/plain\n\r\n404 Not Found");
									send(client_p[i].fd, code_go, strlen(code_go)+1, 0);
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
				}
			}
		}
	}	

	//--------------------------------------------------------------------------	

	printf("\nsocket 연결을 종료합니다\n");
	close(sockfd_listen);
	close(sockfd_connect);

	return 0;
}
