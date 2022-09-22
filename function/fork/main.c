#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, int *argv[])
{
    printf("before fork -1\n");
    printf("before fork -2\n");
    printf("before fork -3\n");
    printf("before fork -4\n");

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid > 0)
    {
        printf("This is parent process!my child is %d\n", pid);
        printf("Current process is %d\n", getpid());
        printf("It's father is %d\n", getppid());
    }
    else if (pid == 0)
    {
        printf("child is created!\n");
        printf("Current process is %d\n", getpid());
        printf("It's father is %d\n", getppid());
    }

    printf("===============\n");

    return 0;
}