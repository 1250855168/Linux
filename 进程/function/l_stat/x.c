#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc ,char *argv[])
{
    struct stat sbuf;
    int ret = lstat(argv[1],&sbuf);
    if (ret==-1)
    {
        perror("lstat error");
        exit(1);
    }

    if (S_ISREG(sbuf.st_mode))
    {
        printf("It is a regular\n");
    }
    else
    {
        printf("It is a uknown file\n");
    }

    return 0;
}