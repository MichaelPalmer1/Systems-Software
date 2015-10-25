#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

char current = 'A';
void *state_a( void *ptr );
void *state_b( void *ptr );
void *state_c( void *ptr );
void *state_d( void *ptr );
void *state_e( void *ptr );
void *state_f( void *ptr );
void *state_g( void *ptr );
void *state_h( void *ptr );
sem_t sem;
pthread_t thread_1, thread_2, thread_3, thread_4, thread_5, thread_6, thread_7, thread_8;

int main() {
	// Initialize semaphores
	sem_init(&sem, 0, 0);
	
	// Create threads
	pthread_create(&thread_1, NULL, state_a, "AA");
	pthread_create(&thread_2, NULL, state_b, "BA");
	pthread_create(&thread_3, NULL, state_c, "CB");
	pthread_create(&thread_4, NULL, state_d, "DB");
	pthread_create(&thread_5, NULL, state_e, "ECD");
	pthread_create(&thread_6, NULL, state_f, "FB");
	pthread_create(&thread_7, NULL, state_g, "GE");
	pthread_create(&thread_8, NULL, state_h, "HGF");
	
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
	sem_destroy(&sem);
	
	return 0;
}
/*
void *state_a( void *ptr ) {
	int i;
	char *name = (char *) ptr;
	printf("Start Thread %c\n", name[0]);
	current++;
	for(i = 0; i < 7; i++) {
		sem_post(&sem);
	}
	printf("End Thread %c\n", name[0]);
}
*/

void *state_a( void *ptr ) {
	int i;
	printf("Entering Thread A\n");
	current++;
	for(i = 0; i < 7; i++) {
		sem_post(&sem);
	}
}

void *state_b( void *ptr ) {
	char *name = (char *) ptr;
	while( current < name[0] ) {
		if(!name[2]) {
			printf("Thread %c waiting on Thread %c\n", name[0], name[1]);	
		} else {
			printf("Thread %c waiting on Threads %c and %c\n", name[0], name[1], name[2]);
		}
		sem_wait(&sem);
		sleep(1);
		sem_post(&sem);
	}
	sem_wait(&sem);
	sleep(1);
	printf("Entering Thread %c\n", name[0]);
	current++;
	sem_post(&sem);
}

void *state_c( void *ptr ) {
	char *name = (char *) ptr;
	while( current < name[0] ) {
		if(!name[2]) {
			printf("Thread %c waiting on Thread %c\n", name[0], name[1]);	
		} else {
			printf("Thread %c waiting on Threads %c and %c\n", name[0], name[1], name[2]);
		}
		sem_wait(&sem);
		sleep(1);
		sem_post(&sem);
	}
	sem_wait(&sem);
	sleep(1);
	printf("Entering Thread %c\n", name[0]);
	current++;
	sem_post(&sem);
}

void *state_d( void *ptr ) {
	char *name = (char *) ptr;
	while( current < name[0] ) {
		if(!name[2]) {
			printf("Thread %c waiting on Thread %c\n", name[0], name[1]);	
		} else {
			printf("Thread %c waiting on Threads %c and %c\n", name[0], name[1], name[2]);
		}
		sem_wait(&sem);
		sleep(1);
		sem_post(&sem);
	}
	sem_wait(&sem);
	sleep(1);
	printf("Entering Thread %c\n", name[0]);
	current++;
	sem_post(&sem);
}

void *state_e( void *ptr ) {
	char *name = (char *) ptr;
	while( current < name[0] ) {
		if(!name[2]) {
			printf("Thread %c waiting on Thread %c\n", name[0], name[1]);	
		} else {
			printf("Thread %c waiting on Threads %c and %c\n", name[0], name[1], name[2]);
		}
		sem_wait(&sem);
		sleep(1);
		sem_post(&sem);
	}
	sem_wait(&sem);
	sleep(1);
	printf("Entering Thread %c\n", name[0]);
	current++;
	sem_post(&sem);
}

void *state_f( void *ptr ) {
	char *name = (char *) ptr;
	while( current < name[0] ) {
		if(!name[2]) {
			printf("Thread %c waiting on Thread %c\n", name[0], name[1]);	
		} else {
			printf("Thread %c waiting on Threads %c and %c\n", name[0], name[1], name[2]);
		}
		sem_wait(&sem);
		sleep(1);
		sem_post(&sem);
	}
	sem_wait(&sem);
	sleep(1);
	printf("Entering Thread %c\n", name[0]);
	current++;
	sem_post(&sem);
}

void *state_g( void *ptr ) {
	char *name = (char *) ptr;
	while( current < name[0] ) {
		if(!name[2]) {
			printf("Thread %c waiting on Thread %c\n", name[0], name[1]);	
		} else {
			printf("Thread %c waiting on Threads %c and %c\n", name[0], name[1], name[2]);
		}
		sem_wait(&sem);
		sleep(1);
		sem_post(&sem);
	}
	sem_wait(&sem);
	sleep(1);
	printf("Entering Thread %c\n", name[0]);
	current++;
	sem_post(&sem);
}

void *state_h( void *ptr ) {
	char *name = (char *) ptr;
	while( current < name[0] ) {
		if(!name[2]) {
			printf("Thread %c waiting on Thread %c\n", name[0], name[1]);	
		} else {
			printf("Thread %c waiting on Threads %c and %c\n", name[0], name[1], name[2]);
		}
		sem_wait(&sem);
		sleep(1);
		sem_post(&sem);
	}
	sem_wait(&sem);
	sleep(1);
	printf("Entering Thread %c\n", name[0]);
	current++;
	sem_post(&sem);
}