#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define MSG_TRY "try again\n"
#define MSG_TIMEOUT "time out\n"

int main()
{
    char buf[10] = {0};
    int fd, n, i;

    fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if (fd == -1)
    {
        perror("open /dev/tty erron");
        exit(1);
    }

    printf("open /dev/tty ok ...%d", fd);

    for (i = 0; i < 5; i++)
    {
        n = read(fd, buf, 10);

        if (n > 0)
        {
            break;
        }
        if (errno != EAGAIN)
        {
            perror("read /dev/tty erron");
        }
        else
        {
            write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
            sleep(2);
        }
    }

    if (i == 5)
    {
        write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT));
        printf("\n");
    }
    else
    {
        write(STDOUT_FILENO,buf,n);
    }

    close(fd);


    return 0;
}
