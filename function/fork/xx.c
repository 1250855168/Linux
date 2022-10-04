#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t ret;
    int i;

    for (i = 0; i < 5; i++)
    {
        ret = fork();
        if (ret == 0)
        {
            break;
        }
    }
    if (i != 5)
    {
        printf("This is %d child!\n", i + 1);
    }
    else
    {
        sleep(1);
        printf("This is father!\n");
    }

    return 0;
}