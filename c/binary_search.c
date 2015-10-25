#include <stdio.h>

int binarySearch(int array[], int left, int right, int element) {
	while (left <= right) {
		int midpoint = left + (right - 1) / 2;

		if (array[midpoint] == element)
			return midpoint;
		else if (array[midpoint] < element)
			left = midpoint + 1;
		else
			right = midpoint - 1;
	}

	return -1;
}

int main() {
	int array[] = {4, 6, 1, 7, 2};
	int n = sizeof(array) / sizeof(array[0]);
	int x = 2;
	int result = binarySearch(array, 0, n - 1, x);
	(result == -1) ?  printf("No element found\n")
		: printf("Element exists here: %d\n", result);

	return 0;
}
