#include <stdio.h>
#include <stdlib.h>
#include "square.h"

int main(int argc, char *argv[]) {
	int num, sqr;
	printf("Enter an integer value: ");
	scanf("%d", &num);
	sqr = square(num);
	printf("The square of %d is %d\n", num, square(num));
}
