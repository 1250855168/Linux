#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int count;
pthread_rwlock_t rwlock;

void *th_write(void *arg)
{
    int t = (long)arg;
    while (1)
    {
        int temp = count;
        usleep(1000);
        pthread_rwlock_wrlock(&rwlock);
        int placeholder = ++count;
        printf("write %d pro_count=%d cur_count=%d\n", t, count, placeholder);
        pthread_rwlock_unlock(&rwlock);
        usleep(9000);
    }
    return NULL;
    
}


void *th_read(void *arg)
{
    int t = (long)arg;
    while (1)
    {
        pthread_rwlock_wrlock(&rwlock);
        int placeholder = ++count;
        printf("read %d pro_count=%d cur_count=%d\n", t, count, placeholder);
        pthread_rwlock_unlock(&rwlock);
        usleep(9000);
    }
    return NULL;
}

int main()
{
    long i;
    pthread_t tid[8];
    for (i = 0; i < 3; i++)
    {
        pthread_create(&tid[i],NULL,th_write,(void *)i);
    }
    for ( i = 0; i < 5; i++)
    {
        pthread_create(&tid[i+3],NULL,th_read,(void *)i);
    }
    for ( i = 0; i < 8; i++)
    {
        pthread_join(tid[i],NULL);
    }
    
    pthread_rwlock_destroy(&rwlock);
    
    return 0;
}