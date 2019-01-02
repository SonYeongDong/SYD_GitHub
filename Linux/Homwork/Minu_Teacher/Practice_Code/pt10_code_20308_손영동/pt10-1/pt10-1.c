#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int flag = 1;

int main(void)
{
	static struct sigaction act;
	
	void int_handler(int);
	
	act.sa_handler = int_handler;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);
	
	while(flag)
	{
		printf("실행중...\n");
		sleep(1);
	}

	return 0;
}

void int_handler(int signum)
{
	int fd;
	char *msg = "사용자 키 인터럽트키 발생...\n";
	
	fd = open("사용자_인터럽트.txt", O_CREAT | O_RDWR, 0644);
	write(fd, msg, strlen(msg));
	close(fd);
	
	flag = 0;

	return;
}
