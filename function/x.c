#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("please input a string :");
    char ch[100];
    fgets(ch, 100, stdin);
    ch[strcspn(ch, "\n")] = 0;
    char *get_ch[10] = {0};
    int i = 0;
    get_ch[i] = strtok(ch, " ");
    while (get_ch[i] != NULL)
    {
        i++;

        get_ch[i] = strtok(NULL, " ");
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("This is child!\n");
        if (execvp(get_ch[0], get_ch) < 0)
        {
            perror("error on exec");
            exit(0);
        }
    }

    if (pid > 0)
    {
        wait(NULL);
        printf("This is father!\n");
    }

    return 0;
}