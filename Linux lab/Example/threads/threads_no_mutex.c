#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

int counter; 
pthread_t tid[2]; 

void * updateCounter_1(void * arg)
{
    printf("Update 1 start\n");
    int i;
    counter = 0;
    for (i = 0; i < 3; i++)
    {
        printf("Counter: %d\n", counter);    
        counter += 2;
    }
    printf("Update 1 end\n");
}

void * updateCounter_2(void * arg)
{
    printf("Update 2 start\n");
    int i;
    counter = 100;
    for (i = 0; i < 3; i++)
    {
        printf("Counter: %d\n", counter);    
        counter += 1;
    }
    printf("Update 2 end\n");
}

int main(void) 
{ 
    /* Create 2 thread */
    pthread_create(&tid[0], NULL, &updateCounter_1, NULL);
    pthread_create(&tid[1], NULL, &updateCounter_2, NULL);

    pthread_join(tid[0], NULL); 
    pthread_join(tid[1], NULL);
	return 0; 
} 
