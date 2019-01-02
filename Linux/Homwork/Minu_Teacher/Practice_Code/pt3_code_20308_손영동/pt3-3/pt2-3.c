#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int filedes;

    ssize_t nread;

    char content[]="Hello_My_name is Son_Yeong_Dong_Nice_to_me_you!!";
    char buffer1[1024];
    char buffer2[1024];

    filedes = open("data.txt", O_RDWR);
    // data.txt에는 문자열 Linux_is_best!! 가 저장되어 있음.

    read(filedes, buffer1, 1024);

    printf("덮어쓰기 전 data.txt 파일의 내용 : %s \n", buffer1);

    write(filedes, content, strlen(content));
    lseek(filedes, (off_t)0, SEEK_SET);
    read(filedes, buffer2, 1024);

    printf("덮어쓰기 후 data.txt 파일의 내용: %s \n", buffer2);

    close(filedes);

    return 0;
}
