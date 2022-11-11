#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    char *argument_list[3] = {0};
    argument_list[0] = "ls";
    argument_list[1] = "-l";
    argument_list[2] = NULL;

    execvp(argument_list[0], argument_list);

    return 0;
}