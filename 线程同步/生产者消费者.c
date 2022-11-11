#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void err_thread(int ret, char *ch)
{
    if (ret != 0)
    {
        fprintf(stderr, "%s :%s\n", ch, strerror(ret));
        pthread_exit(NULL);
    }
}

struct msg
{
    int data;
    struct msg *next;
};

struct msg *Head = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_data = PTHREAD_COND_INITIALIZER;

void *producer(void *arg)
{
    while (1)
    {
        struct msg *xxx=malloc(sizeof(xxx));
        xxx->data = rand()%100+1;
        printf("producer data %d\n",xxx->data);

        pthread_mutex_lock(&mutex);
        xxx->next = Head;
        Head = xxx;
        pthread_mutex_unlock(&mutex);

        pthread_cond_signal(&cond_data);

        sleep(rand()%3);

    }
    
    return NULL;
}

void *consumer(void *arg)
{
    while (1)
    {
        struct msg *xxx;
        
        while (Head==NULL)
        {
            pthread_cond_wait(&cond_data,&mutex);
        }

        xxx = Head;
        Head = xxx->next;
        pthread_mutex_unlock(&mutex);

        printf("--consumer %lu data %d\n",pthread_self(),xxx->data);

        free(xxx);
        xxx=NULL;

        sleep(rand()%3);
        
    }
    
    return NULL;
}

int main()
{
    int ret;
    pthread_t pid, cid_1, cid_2;

    srand(time(NULL));

    ret = pthread_create(&pid, NULL, producer, NULL);
    if (ret != 0)
    {
        err_thread(ret, "pthread_create producer error");
    }
    ret = pthread_create(&cid_1, NULL, consumer, NULL);
    if (ret != 0)
    {
        err_thread(ret, "pthread_create consumer1 error");
    }
    ret = pthread_create(&cid_2, NULL, consumer, NULL);
    if (ret != 0)
    {
        err_thread(ret, "pthread_create consumer2 error");
    }

    pthread_join(pid,NULL);
    pthread_join(cid_1,NULL);
    pthread_join(cid_2,NULL);

    return 0;
}