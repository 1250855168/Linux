#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void catch_child(int signo)
{
    pid_t pid;
    int status;
    while ((pid = waitpid(-1, &status, 0)) != -1)
    {
        if (WIFEXITED(status))
        {
            printf("----catch child id %d,ret = %d\n", pid, WEXITSTATUS(status));
        }
    }
    return;
}

int main()
{

    pid_t pid;
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);
    sigprocmask(SIG_BLOCK, &set, NULL);

    int i;
    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            break;
        }
    }

    if (i == 5)
    {
        sleep(1);
        struct sigaction act;
        act.sa_handler = catch_child;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
        sigaction(SIGCHLD, &act, NULL);

        sigprocmask(SIG_UNBLOCK, &set, NULL);
        printf("I'm parent pid %d\n", getpid());
        while (1)
        {
        }
    }
    else
    {
        printf("I'm child pid=%d\n", getpid());
    }
    return i;

    return i;
}