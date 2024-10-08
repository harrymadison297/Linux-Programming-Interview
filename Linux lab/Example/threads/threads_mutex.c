#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

int counter; 
pthread_mutex_t counter_l; 
pthread_t tid[2]; 

void * updateCounter_1(void * arg)
{
    pthread_mutex_lock(&counter_l);
    printf("Update 1 start\n");
    int i;
    counter = 0;
    for (i = 0; i < 3; i++)
    {
        printf("Counter: %d\n", counter);    
        counter += 2;
    }
    printf("Update 1 end\n");
    pthread_mutex_unlock(&counter_l);
}

void * updateCounter_2(void * arg)
{
    pthread_mutex_lock(&counter_l);
    printf("Update 2 start\n");
    int i;
    counter = 100;
    for (i = 0; i < 3; i++)
    {
        printf("Counter: %d\n", counter);    
        counter += 1;
    }
    printf("Update 2 end\n");
    pthread_mutex_unlock(&counter_l);
}

int main(void) 
{ 
    /* Init mutex */
    if (pthread_mutex_init(&counter_l, NULL) != 0) { 
        printf("Mutex init has failed\n"); 
        return 1; 
    } 
    else
        printf("Mutex initialized\n");

    /* Create 2 thread */
    pthread_create(&tid[0], NULL, &updateCounter_1, NULL);
    pthread_create(&tid[1], NULL, &updateCounter_2, NULL);

    /* Destroy mutex */
    pthread_mutex_destroy(&counter_l);
	return 0; 
} 
