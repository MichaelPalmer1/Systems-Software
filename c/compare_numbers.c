#include <stdio.h>

int main() {
	int a, b;
	printf("First number: ");
	scanf("%d", &a);
	printf("Second number: ");
	scanf("%d", &b);
	printf("%d is the larger number\n", (a > b) ? a : b);
}