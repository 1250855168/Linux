#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <pthread.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    int age;
};

void *xxx(void *arg)
{
    struct Student *student;
    student = (struct Student *)malloc(sizeof(struct Student));
    student->age = 18;
    strcpy(student->name, "xxx");
    return (void *)student;
}

int main()
{
    struct Student *xxxx;
    pthread_t tid;
    int ret;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&tid, &attr, xxx, NULL);
    pthread_attr_destroy(&attr);
    
    ret = pthread_join(tid, (void **)&xxxx);
    if (ret != 0)
    {
        fprintf(stderr, "pthread_join error %s\n", strerror(ret));
        exit(1);
    }

    pthread_exit((void *)0);
}