#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include<stdlib.h>

// int main()
// {
//     pid_t pid;

//     pid = fork();
//     if (pid<0)
//     {
//         perror("fork error");
//         exit(1);
//     }

//     if (pid == 0)
//     {
//         execlp("ls","ls","-l",NULL);
//         perror("execlp error");
//         exit(1);
//     }
//     else
//     {
//         sleep(1);
//         printf("I'm my father id %d\n",getpid());
//     }
    
    


//     return 0;
// }

int main()
{

        pid_t pid;

    pid = fork();
    if (pid<0)
    {
        perror("fork error");
        exit(1);
    }

    if (pid == 0)
    {
        execl("./x","./x",NULL);
        perror("execlp error");
        exit(1);
    }
    else
    {
        sleep(1);
        printf("I'm my father id %d\n",getpid());
    }

    return 0;

}