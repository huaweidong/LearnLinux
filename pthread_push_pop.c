#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void cleanup1(void *args)
{
    char* sz = (char*)args;
    printf("cleanup1 : %s\n", sz);
}

void* work(void *args)
{
    pthread_cleanup_push(cleanup1, (void*)"hello"); // 存进栈里，函数链，是如何实现的呢？
    pthread_cleanup_push(cleanup1, (void*)"work");
    printf("work...\n");
    int i = 0;
    while(i++ < 10)
    {
        printf("...\n");
        sleep(1);
    }
    return NULL;    // 正常退出（非cancel）下返回，不会调用到cleanup_pop，cancel非正常退出时才会
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
}

int main()
{
    pthread_t id;
    pthread_create(&id, NULL, work, NULL);
    sleep(2);
    pthread_cancel(id);
    pthread_join(id, NULL);
    exit(EXIT_SUCCESS);
}
