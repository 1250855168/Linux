#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t ret;
    for (size_t i = 0; i < 1; i++) //2 4 8 16 32 64 128 256 512 1024 2048 ......
    {
        ret = fork();
        printf("%ld .\n", i);
    }

    return 0;
}