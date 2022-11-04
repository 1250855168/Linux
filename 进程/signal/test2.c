#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

void sig_cath(int signo)
{
    printf("catch you!!");
    return;
}

int main()
{
    signal(SIGINT,sig_cath);
    while (1)
    {
        
    }
    
    return 0;
}