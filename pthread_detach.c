#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void* work(void *args)
{
    sleep(10);
}

void* work3(void *args)
{
    int i = 0;
    while(i++ < 10)
    {
        printf("work3 ... %d\n", i);
        sleep(1);
    }
}

void* work2(void *args)
{
    pthread_t id3;
    printf("create thread 3 before\n");
    pthread_create(&id3, NULL, work3, NULL);
    printf("create thread 3 after\n");
    pthread_join(id3, NULL);    // 子线程等待子线程没用，主线程退出进程就会退出
    printf("wait thread 3 finish\n");
}

int main()
{
    int res;
    pthread_t id;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);    // Detach后,join也不会再等待了，主线程退出，子线程无论是否可等待，只要不等待，都直接退出
    res = pthread_create(&id, &attr, work, NULL);
    res = pthread_join(id, NULL);
    printf("after wait\n");
    pthread_t id2;
    pthread_create(&id2, NULL, work2, NULL);
    //pthread_join(id2, NULL);  // 主线程等待子线程
    exit(EXIT_SUCCESS);
}