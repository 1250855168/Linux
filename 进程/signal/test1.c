#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
    }

    if (pid > 0)
    {
        printf("parent pid=%d\n", getpid());
        while (1)
        {
            
        }
        
    }
    else if (pid == 0)
    {
        printf("child pid=%d parent pid=%d\n", getpid(), getppid());
        sleep(2);
        kill(getppid(), SIGKILL);
    }
    return 0;
}