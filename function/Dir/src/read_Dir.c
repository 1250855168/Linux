

#include "head.h"
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

void read_Dir(char *Dir)
{
    struct stat ss;
    int ret = stat(Dir, &ss);
    if (ret == -1)
    {
        perror("stat error");
        return;
    }

    if (S_ISDIR(ss.st_mode))
    {
        is_file(Dir, read_Dir);  
    }

    printf("%s  %ld\n", Dir,ss.st_size);

    return;
}