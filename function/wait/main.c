#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int i;
    pid_t pid, wpid, twipd;

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (0 == pid)
        {
            break;
        }
        if (i == 2)
        {
            twipd = pid;
            printf("------pid=%d\n", twipd);
        }
    }
    if (5 == i)
    {
        sleep(5);
        printf("xxx %d\n", twipd);
        wpid = waitpid(twipd, NULL, WNOHANG);
        printf("wait : %d\n", wpid);
    }
    else
    {
        sleep(i);
        printf("%d child pid=%d\n", i + 1, getpid());
    }

    return 0;
}