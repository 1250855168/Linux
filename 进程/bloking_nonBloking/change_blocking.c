#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

#define MSG_TRY "try again\n"

int main()
{
    char buf[10];
    int flag,n;

    flag = fcntl(STDIN_FILENO,F_GETFL);
    if (flag == -1)
    {
        perror("fcntl erron");
        exit(1);
    }
    flag |= O_NONBLOCK;
    int ret = fcntl(STDIN_FILENO,F_SETFL,flag);
    if (ret == -1)
    {
        perror("fcntl error");
        exit(1);
    }

    tryagain:
        n = read(STDIN_FILENO,buf,10);
        if (n<0)
        {
            if (errno != EAGAIN)
            {
                perror("read /dev/tty");
                exit(1);
            }
            sleep(3);
            write(STDOUT_FILENO,MSG_TRY,strlen(MSG_TRY));
            goto tryagain; 
        }
        write(STDOUT_FILENO,buf,n);
    return 0;
}