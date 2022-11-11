#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main()
{
    int fd ;
    fd = open("./ps.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if (fd<0)
    {
        perror("open ps.txt error");
        exit(1);
    }

    dup2(fd,STDOUT_FILENO);

    execlp("ps","ps","aux",NULL);
    close(fd);
    
    return 0;
}
