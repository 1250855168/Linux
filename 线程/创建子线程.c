#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<error.h>
#include <pthread.h>

void *xxx(void *arg)
{
    int i = *(int*)arg;
    sleep(i);
    printf("I'm %dth thread pid = %d,tid = %lu\n",i+1,getpid(),pthread_self());
    pthread_exit((void*)0);
}

int main()
{
    long i;
    int ret;
    pthread_t tid;

    for ( i = 0; i < 5; i++)
    {
      ret = pthread_create(&tid, NULL, xxx, (void *)i);
      if (ret != 0) {
        fprintf(stderr, "pthread_create error %s", strerror(ret));
        }
    }

    sleep(i);

    printf("I'm main pid = %d,tid = %lu\n",getpid(),pthread_self());
    
    pthread_exit((void*)0);
}