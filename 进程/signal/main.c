#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

void printf_set(sigset_t *set)
{
    int i;
    for (i = 1; i < 32; i++)
    {
        if (sigismember(set, i))
        {
            putchar('y');
        }
        else
        {
            putchar('x');
        }
    }
    putchar('\n');
}

int main()
{
    sigset_t set, oldset, pedset;
    int ret = 0;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    sigaddset(&set, SIGBUS);
    sigaddset(&set, SIGKILL);
    ret = sigprocmask(SIG_BLOCK, &set, &oldset);
    if (ret==-1)
    {
        perror("sigprocmask error");
    }
    while (1)
    {
        ret = sigpending(&pedset);
        printf_set(&pedset);
        sleep(1);
    }
    
    
    return 0;
}