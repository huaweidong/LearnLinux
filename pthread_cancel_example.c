#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void* work(void *args)
{
    int i, res, j;
    res = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    if ( res != 0 )
    {
        perror("pthread_setcancelstate failed 1.");
        exit(EXIT_FAILURE);
    }
    printf("this thread cannot be canceled.\n");
    sleep(3);    
    for ( i = 0; i < 3; i++ )
    {
        printf("thread running ...\n");
        sleep(1);
    }
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if ( res != 0 )
    {
        perror("pthread_setcancelstate failed 2.");
        exit(EXIT_FAILURE);
    }
    printf("this thread can be canceled.\n");
    sleep(200);
    pthread_exit(0);    
}

int main()
{
    int res;
    pthread_t id;
    void* result;
    res = pthread_create(&id, NULL, work, NULL);
    if ( res != 0 )
    {
        perror("create failed.");
        exit(EXIT_FAILURE);
    }
    sleep(4);
    printf("cancel thread...\n");
    res = pthread_cancel(id);
    if ( res != 0 )
    {
        perror("cancel failed.");
        exit(EXIT_FAILURE);
    }
    printf("wait for thread finish.\n");
    res = pthread_join(id, &result);
    if ( res != 0 )
    {
        perror("join failed.");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}