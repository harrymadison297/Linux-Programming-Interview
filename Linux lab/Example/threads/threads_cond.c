#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done = 1;

void* foo()
{
	pthread_mutex_lock(&lock);
	if (done == 1) {
		done = 2;
		printf("Waiting on condition variable cond1\n");
		pthread_cond_wait(&cond1, &lock);
	}
	else {
		printf("Signaling condition variable cond1\n");
		pthread_cond_signal(&cond1);
	}
	pthread_mutex_unlock(&lock);
	printf("Returning thread\n");
	return NULL;
}

int main()
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, foo, NULL);
	sleep(1);
	pthread_create(&tid2, NULL, foo, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return 0;
}
