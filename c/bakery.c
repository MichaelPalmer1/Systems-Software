#include <pthread.h>
#include <assert.h>
#include <stdio.h>
#include <semaphore.h>

#define MAX 10

char flour, water, stove;
pthread_mutex_t f, w, s;

void * baker( void * arg ) {
	int i;
	char *name = (char *) arg;
	int num_to_make = MAX;
	
	printf("Starting %s thread ...\n", name);
	while( i < num_to_make) {
		pthread_mutex_lock(&f);
		pthread_mutex_lock(&s);
		pthread_mutex_lock(&w);
		printf("%s just made another cupcake!\n", name);
		num_to_make++;
		pthread_mutex_unlock(&w);
		pthread_mutex_unlock(&s);
		pthread_mutex_unlock(&f);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main() {
	printf("Starting program...\n");
	pthread_t tA, tB, tC;
	pthread_create(&tA, NULL, baker, "Chef Bob");
	pthread_create(&tB, NULL, baker, "Chef Mary");
	pthread_create(&tC, NULL, baker, "Chef Jane");
	pthread_join(tA, NULL);
	pthread_join(tB, NULL);
	pthread_join(tC, NULL);
	return 0;
}