#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
    int i;
    pid_t pid,wpid;
    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            break;
        }
    }
    
if (5 == i)
{
    while ((wpid=waitpid(-1,NULL,WNOHANG))!=-1)
    {
        if (wpid>0)
        {
            printf("wait child %d \n",wpid);
        }
        else if (wpid == 0)
        {
            sleep(1);
            continue;
        }
           
    }  
}
else
{
    sleep(i);
    printf("%dth child pid = %d\n",i+1,getpid());
}
 return 0;
}