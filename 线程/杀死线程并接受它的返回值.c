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
    student = malloc(sizeof(struct Student));
    student->age = 18;
    strcpy(student->name, "xxx");
    return (void *)student;
}

int main()
{
    pthread_t tid;
    struct Student *xxxx;
    int ret = pthread_create(&tid, NULL, xxx, NULL);
    if (ret != 0)
    {
        fprintf(stderr, "pthread_create error %s\n", strerror(ret));
        exit(1);
    }
    ret = pthread_detach(tid);
    if (ret != 0)
    {
        fprintf(stderr,"pthread_detach error %s\n", strerror(ret));
        exit(1);
    }

    ret = pthread_join(tid, (void **)&xxxx);
    if (ret != 0)
    {
        fprintf(stderr, "pthread_join error %s\n", strerror(ret));
        exit(1);
    }
    
    printf("%s %d\n", xxxx->name, xxxx->age);
    pthread_exit(NULL);
}