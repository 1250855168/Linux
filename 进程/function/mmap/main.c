#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include<string.h>

int main()
{
    char *p = NULL;
    int fd;
    
    fd = open("./test.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
    if (-1==fd)
    {
        perror("open error");
    }

    ftruncate(fd,20);
    int len = lseek(fd,0,SEEK_END);
    p = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if (p==MAP_FAILED)
    {
        perror("mmap error");
    }
    strcpy(p,"helld mmap");
    printf("%s\n",p);
    int ret = munmap(p,len);
    if (ret==-1)
    {
        perror("munmap error");
    }
    
    return 0;
}