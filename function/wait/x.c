#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        printf("child ,my parent=%d,going to sleep 10s\n", getppid());
        sleep(10);
        printf("child die!!!");
        return 100;
    }
    else if (pid > 0)
    {
        wpid = wait(&status);
        if (wpid == -1)
        {
            perror("wait error");
            exit(1);
        }
        if (WIFEXITED(status))
        {
            printf("child exit with %d\n",WEXITSTATUS(status));
        }
        if (WIFSIGNALED(status))
        {
            printf("child will with signal %d\n",WTERMSIG(status));
        }
        
        printf("parent wait finish\n");
    }
    else
    {
        perror("fork");
        return 1;
    }
    return 0;
}