#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define maximum 5 //연결 요청 최대 횟수
#define BYTES 1024

char ROOT[500] = {'0'};

void respond(int);

int main(void)
{

    int serversock; //서버 소켓
    int clientsock; //클라이언트 소켓
    struct sockaddr_in echoserveraddr; //서버 주소
    struct sockaddr_in echoclientaddr; //클라이언트 주소
    unsigned short echoserverport; //서버 포트 번호
    unsigned int clntlen; //클라이언트 주소 데이터 구조 길이
    int iRet;
    int pid;
    unsigned char ucbuffer[500];
     

    sprintf(ROOT,"%s","/home/ubuntu");
    echoserverport = 9999; //서버 포트 넘버

// 소켓 생성
    serversock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    if(serversock < 0) //에러
	{
	printf("socket() is falied\n");
	return 0;
	}  
//구조체 생성
    memset( &echoserveraddr, 0, sizeof(echoserveraddr));
//메모리 세팅(주소,채움 숫자,개수)
    echoserveraddr.sin_family = AF_INET;
    echoserveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    echoserveraddr.sin_port = htons(echoserverport);

// BIND 소켓에 구조체를 적용
    iRet = bind(serversock, (struct sockaddr*) &echoserveraddr, sizeof (echoserveraddr));

    if(iRet < 0) //error
	{
	printf("bind() failed\n");
	close(serversock);
	return 0;
	}
     iRet = listen(serversock, maximum); //MAXPENDING 최대 동시  접속자 수
    if(iRet < 0)
	{
	printf("listen() failed\n");
	close(serversock);
	return 0;
	}
   //클라이언트 연결되기를 기다린다
    while(1){
        clntlen = sizeof(echoclientaddr); //나가고 들어오는 매개 변수 크기 설정
        clientsock = accept(serversock, (struct sockaddr *) &echoclientaddr, &clntlen);
        if(clientsock < 0)
        {
	    printf("accept() failed\n");
            continue;
	}

//클라이언트 소켓이 알맞은 클라이언트를 만나면
        printf("handling client ip %s\n",inet_ntoa(echoclientaddr.sin_addr));
        printf("handling client prot %d\n",ntohs(echoclientaddr.sin_port));
    
        if((pid = fork()) == 0){
    	    respond(clientsock);
        }else{
            printf("create process pid : %d\n",pid);
        }
    }
    close(serversock);
    return 0;
}

void respond(int client)
{
    char mesg[99999], *reqline[3], data_to_send[BYTES], path[99999];
    int rcvd, fd, bytes_read;

    memset( (void*)mesg, (int)'\0', 99999 );
    printf("client id : %d\n",client);
    rcvd = recv(client, mesg, 99999, 0); 
	
    if (rcvd < 0)    // receive error
        fprintf(stderr,("recv() error\n"));
    else if (rcvd == 0)    // receive socket closed
        fprintf(stderr,"Client disconnected upexpectedly.\n");
    else    // message received
    {   
        printf("%s", mesg);
        reqline[0] = strtok (mesg, " \t\n");
        if ( strncmp(reqline[0], "GET\0", 4) == 0 ) 
        {   
            reqline[1] = strtok (NULL, " \t");
            reqline[2] = strtok (NULL, " \t\n");
            if ( strncmp( reqline[2], "HTTP/1.0", 8) != 0 && strncmp( reqline[2], "HTTP/1.1", 8)!=0 )
            {   
                write(client, "HTTP/1.0 400 Bad Request\n", 25);
            }   
            else
            {   
                if ( strncmp(reqline[1], "/\0", 2) == 0 ) 
                    reqline[1] = "/index.html";

                strcpy(path, ROOT);
                strcpy(&path[strlen(ROOT)], reqline[1]);
                printf("file: %s\n", path);

                if ( (fd = open(path, O_RDONLY)) != -1 )    //FILE FOUND
                {   
                    send(client, "HTTP/1.0 200 OK\n\n", 17, 0); 
                    while ( (bytes_read = read(fd, data_to_send, BYTES)) > 0 ) 
                        write (client, data_to_send, bytes_read);
                }   
                else    write(client, "HTTP/1.0 404 Not Found\n", 23); //FILE NOT FOUND
            }   
        }   
    }
    shutdown(client,SHUT_RDWR);
    close(client);
    exit(1);
}
