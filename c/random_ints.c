/*
 * Name: Michael Palmer
 * Professor: Dr. Andrew Allen
 * Course: CSCI 3232 A
 * Assignment: A2
 * Date: January 21, 2015
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Number of integers to generate
#define NUM_INTS 100

// Minimum value of integers
#define RANGE_MIN 1

// Maximum value of integers
#define RANGE_MAX 10

/* Generate an integer in the range [min, max] */
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/* Sort the array in ascending order */
void sortAsc(int array[NUM_INTS]) {
    int a, b, c;
	for (a = 0; a < NUM_INTS; a++) {
		for (b = 0; b < NUM_INTS; b++) {
			if (array[a] > array[b]) {
				c = array[a];
				array[a] = array[b];
				array[b] = c;
			}
		}
	}
}

/* Verify the array is in ascending order */
int verifyOrder(int x[NUM_INTS]) {
	int i, prev = x[0];
	for (i = 1; i < NUM_INTS; i++) {
		if (x[i] > prev) {
			return 0;
		}
		prev = x[i];
	}
	return 1;
}

int main() {
	int i, ints[NUM_INTS];

	// Generate random seed
	srand( (unsigned) time( NULL ) );

	// Generate NUM_INTS random integers
	printf("Unsorted:\n");
	for (i = 0; i < NUM_INTS; i++) {
		ints[i] = randInt(RANGE_MIN, RANGE_MAX);
		printf("%d ", ints[i]);
	}
    printf("\n\n");

	// Sort array in ascending order
	printf("Sorted:\n");
	sortAsc(ints);
	for (i = 0; i < NUM_INTS; i++) {
		printf("%d ", ints[i]);
	}
	printf("\n\n");

	// Verify array is in ascending order
	printf("Array is sorted: %s\n", verifyOrder(ints) ? "TRUE" : "FALSE");

	return 0;
}
