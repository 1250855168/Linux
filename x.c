#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define STRING "hello world!"

int main()
{
    int pipedes[2];

    pipe(pipedes);
    
}