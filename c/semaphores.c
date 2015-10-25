#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void *funcA();
void *funcB();

sem_t sem1;

int main() {
	pthread_t thread1, thread2;

	sem_init(&sem1, 0, 0);

	pthread_create(&thread1, NULL, funcA, NULL);
	pthread_create(&thread2, NULL, funcB, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	sem_destroy(&sem1);
}

void *funcA() {
	printf("TEST\n");
	sem_post(&sem1);
}

void *funcB() {
	sem_wait(&sem1);
	printf("TEST 2\n");
	sem_post(&sem1);
}