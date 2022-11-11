#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    pid_t pid;
    int fd;
    pid = fork();
    if (pid > 0)
    {
        exit(0);
    }

    pid = setsid();
    chdir("/home/xxx/");
    umask(0022);
    close(STDIN_FILENO);

    fd = open("dev/null", O_RDWR);

    dup2(fd, STDERR_FILENO);
    dup2(fd, STDOUT_FILENO);

    while (1)
    {
    }
}