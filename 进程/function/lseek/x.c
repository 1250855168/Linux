#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


int main()
{
    int fd ,n;
    char msg[] = "It is a test for lseek\n";
    char ch;

    fd = open("lseek.txt",O_RDWR|O_CREAT,0644);
    if (fd < 0)
    {
        perror("open lseek.txt erron");
        exit(1);
    }

    write(fd,msg,strlen(msg));

    lseek(fd,0,SEEK_SET);//重新指向起始位置

    while ((n=read(fd,&ch,1)))
    {
        if (n<0)
        {
            perror("read error");
            exit(1);
        }
        write(STDOUT_FILENO,&ch,n);
    }
    
    close(fd);
    


    return 0;
}