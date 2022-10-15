#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    pid_t pid;
    char buf[1024];
    pid = fork();

    while (1)
    {
        if (pid == 0)
        {
            fd = open("B", O_RDWR);
            // printf("x:");
            fgets(buf, 1024, stdin);
            write(fd, buf, 1024);
        }

        if (pid > 0)
        {
            fd = open("A", O_RDWR);
            read(fd, buf, 1024);
            printf("xx:%s", buf);
        }
    }

    return 0;
}