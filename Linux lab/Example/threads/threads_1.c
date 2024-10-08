#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int global_test = 0;

void * thread_1(void *arg)
{
    int i = 0;
    while (1)
    {
        printf("Thread 1 :: i-%d, global_test-%d\n", i, global_test);
        i++;
        global_test++;
        sleep(2);
    }
    return NULL;
}

int main()
{
    pthread_t thread_new;
    pthread_create(&thread_new, NULL, thread_1, NULL);
    int i = 100;
    while (1)
    {
        printf("Thread main :: i-%d, global_test-%d\n", i, global_test);
        i++;
        global_test+=10;
        sleep(3);
    }
    return 0;
}