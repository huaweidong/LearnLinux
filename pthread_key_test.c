#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_key_t key;
pthread_key_t key2;

void destroy(void *t)
{
    printf("thread finish destroy tsd, current thread id=%lu, data=%s\n", pthread_self(), (const char*)t);
}

void* work1(void *args)
{
    const char* word = "this is thread 1";
    const char* word2 = "this is thread 1-2";
    int tid = pthread_self();
    pthread_setspecific(key, word);
    pthread_setspecific(key2, word2);
    printf("thread id=%lu, data addr=%u, data=%s\n", pthread_self(), *(int*)pthread_getspecific(key), (const char*)pthread_getspecific(key));
}

void* work2(void *args)
{
    const char* word = "this is thread 2";
    int tid = pthread_self();
    pthread_setspecific(key, word);
    printf("thread id=%lu, data addr=%u, data=%s\n", pthread_self(), *(int*)pthread_getspecific(key), (const char*)pthread_getspecific(key));
}

int main()
{
    pthread_t id1, id2;
    pthread_key_create(&key, destroy);
    pthread_key_create(&key2, destroy);
    pthread_create(&id1, NULL, work1, NULL);
    pthread_create(&id2, NULL, work2, NULL);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_key_delete(key);
    exit(EXIT_SUCCESS);
}
