#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void *state_a( void *ptr );
void *state_b( void *ptr );
void *state_c( void *ptr );
void *state_d( void *ptr );
void *state_e( void *ptr );
void *state_f( void *ptr );
void *state_g( void *ptr );
void *state_h( void *ptr );
sem_t a, b, c, d, e, f, g, h;
pthread_t thread_1, thread_2, thread_3, thread_4, thread_5, thread_6, thread_7, thread_8;

int main() {
	// Initialize semaphores
	sem_init(&a, 0, 0);
	sem_init(&b, 0, 0);
	sem_init(&c, 0, 0);	
	sem_init(&d, 0, 0);	
	sem_init(&e, 0, 0);	
	sem_init(&f, 0, 0);	
	sem_init(&g, 0, 0);	
	sem_init(&h, 0, 0);	
	
	// Create threads
	pthread_create(&thread_1, NULL, state_a, NULL);
	pthread_create(&thread_2, NULL, state_b, NULL);
	pthread_create(&thread_3, NULL, state_c, NULL);
	pthread_create(&thread_4, NULL, state_d, NULL);
	pthread_create(&thread_5, NULL, state_e, NULL);
	pthread_create(&thread_6, NULL, state_f, NULL);
	pthread_create(&thread_7, NULL, state_g, NULL);
	pthread_create(&thread_8, NULL, state_h, NULL);
	
	// Join threads
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	pthread_join(thread_3, NULL);
	pthread_join(thread_4, NULL);
	pthread_join(thread_5, NULL);
	pthread_join(thread_6, NULL);
	pthread_join(thread_7, NULL);
	pthread_join(thread_8, NULL);
	
	// Destroy semaphores
	sem_destroy(&a);
	sem_destroy(&b);
	sem_destroy(&c);
	sem_destroy(&d);
	sem_destroy(&e);
	sem_destroy(&f);
	sem_destroy(&g);
	sem_destroy(&h);
	
	return 0;
}

void *state_a( void *ptr ) {
	printf("Entered Thread A\n");
	sem_post(&a);
	sem_post(&a);
}

void *state_b( void *ptr ) {
	printf("Thread B waiting on Thread A\n");
	sem_wait(&a);
	printf("Entered Thread B\n");
	sem_post(&b);
	sem_post(&b);
}

void *state_c( void *ptr ) {
	printf("Thread C waiting on Thread A\n");
	sem_wait(&a);
	printf("Entered Thread C\n");
	sem_post(&c);
}

void *state_d( void *ptr ) {
	printf("Thread D waiting on Thread B\n");
	sem_wait(&b);
	printf("Entered Thread D\n");
	sem_post(&d);
}

void *state_e( void *ptr ) {
	printf("Thread E waiting on Thread C\n");
	sem_wait(&c);
	printf("Thread E waiting on Thread D\n");
	sem_wait(&d);
	printf("Entered Thread E\n");
	sem_post(&e);
}

void *state_f( void *ptr ) {
	printf("Thread F waiting on Thread B\n");
	sem_wait(&b);
	printf("Entered Thread F\n");
	sem_post(&f);
}

void *state_g( void *ptr ) {
	printf("Thread G waiting on Thread E\n");
	sem_wait(&e);
	printf("Entered Thread G\n");
	sem_post(&g);
}

void *state_h( void *ptr ) {
	printf("Thread H waiting on Thread F\n");
	sem_wait(&f);
	printf("Thread H waiting on Thread G\n");
	sem_wait(&g);
	printf("Entered Thread H\n");
	sem_post(&h);
}