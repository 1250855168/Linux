#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include <errno.h>

int main()
{
    char buf[10];
    int n;

    n = read(STDIN_FILENO,buf,10);
    if (n<0)
    {
        perror("read STDIN_FILENO erron");
        exit(1);
    }

    write(STDOUT_FILENO,buf,n);
    

    return 0;
}