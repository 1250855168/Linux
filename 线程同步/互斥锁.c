#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *xxx(void *arg)
{
    srand(time(NULL));
    while (1)
    {
        pthread_mutex_lock(&mutex);
        printf("hello ");
        sleep(rand() % 3);
        printf("world \n");
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    srand(time(NULL));
    int ret = pthread_mutex_init(&mutex, NULL);
    if (ret != 0)
    {
        fprintf(stderr, "pthread_mutex_init error %s", strerror(ret));
    }
    pthread_create(&tid, NULL, xxx, NULL);
    while (1)
    {
        pthread_mutex_lock(&mutex);
        printf("HELLO ");
        sleep(rand() % 3);
        printf("WORLD \n");
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3);
    }
    pthread_join(tid, NULL);
    return 0;
}