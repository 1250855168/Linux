#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>

void sig_catch(int signo)
{
    if (signo==SIGINT)
    {
        printf("catch you!! %d\n",signo);
    }
    else if(signo==SIGQUIT)
    {
        printf("--------catch you!! %d\n",signo);
    }
    
    return ;
}

int main()
{
    struct sigaction act,oldact;
    act.sa_handler = sig_catch;
    sigemptyset(&(act.sa_mask));
    act.sa_flags = 0;
    int ret = sigaction(SIGINT,&act,&oldact);
    ret = sigaction(SIGQUIT,&act,&oldact);
    while (1)
    {
        
    }
    
}