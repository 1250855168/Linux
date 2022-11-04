#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<error.h>
#include <pthread.h>

void *xxx(void *arg)
{
    int i = (int)arg;
    printf("I'm %dth thread pid = %d,tid = %lu\n",i+1,getpid(),pthread_self());
    return NULL;
}

int main()
{
    int i;
    int ret;
    pthread_t tid;

    for ( i = 0; i < 5; i++)
    {
        ret = pthread_create(&)
    }
    
}