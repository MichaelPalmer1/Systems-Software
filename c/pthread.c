#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *function(void *ptr);

int main() {
	char *msg1 = "Thread 1";
	char *msg2 = "Thread 2";
	int rc1, rc2;

	pthread_t thread1, thread2;

	rc1 = pthread_create(&thread1, NULL, function, (void *) msg1);
	rc2 = pthread_create(&thread2, NULL, function, (void *) msg2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Thread 1 returns %d\n", rc1);
	printf("Thread 2 returns %d\n", rc2);
}

void *function(void *ptr) {
	printf("%s\n", (char *) ptr);
}