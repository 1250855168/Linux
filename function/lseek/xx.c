#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        exit(1);
    }

    int lenth = lseek(fd, 100, SEEK_END);
    int num = write(fd,"0", 1);
    printf("%d\n", lenth+num);

    close(fd);

    return 0;
}