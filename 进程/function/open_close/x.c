#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int fd;
	fd = open("./x1.c",O_RDONLY|O_CREAT,0664);

	printf("fd = %d,errno = %d:%s\n",fd,errno,strerror(errno));

	close(fd);

	return 0;
}
