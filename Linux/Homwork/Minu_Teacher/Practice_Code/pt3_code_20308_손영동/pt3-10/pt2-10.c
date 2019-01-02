#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int file1, file2;

    ssize_t nread;

    char content1[]= "file1";
    char content2[]= "file2";
    char buffer[1024];

    file1 = open("data.txt", O_RDWR | O_CREAT, 0644);
    write(file1, content1, strlen(content1));

    file2 = open("data.txt", O_RDWR | O_CREAT, 0644);
    write(file2, content2, strlen(content2));
    
    read(file1, buffer, 1024);
    printf("data.txt 내용 : %s\n", buffer);

    close(file1);
    close(file2);

    return 0;
}
