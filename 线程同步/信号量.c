#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM 5

int queue[NUM];
sem_t blank_number, product_number;

void *producer(void *arg)
{
    int i = 0;
    while (1)
    {
        sem_wait(&blank_number);
        queue[i] = rand() % 1000 + 1;
        printf("producer %d\n",queue[i]);
        sem_post(&product_number);

        i=(i+1)%NUM;
        sleep(rand()%10);
    }
    return NULL;
}

void *consumer(void *arg)
{
    int i = 0;
    while (1)
    {
        sem_wait(&product_number);
        printf("consumer %d\n", queue[i]);
        queue[i] = 0;
        sem_post(&blank_number);
        i = (i + 1) % NUM;

        sleep(rand() % 10);
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    pthread_t pid,cid;
    sem_init(&blank_number, 0, NUM);
    sem_init(&product_number, 0, 0);

    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    sem_destroy(&blank_number);
    sem_destroy(&product_number);

    return 0;
}