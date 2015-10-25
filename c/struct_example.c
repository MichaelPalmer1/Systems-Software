#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Vehicle {
    char *make;
    char *model;
    int year;
    int vinNum;
};

struct Vehicle *Vehicle_create(char *make, char *model, int year, int vinNum)
{
    struct Vehicle *myRide = malloc(sizeof(struct Vehicle));
	printf("myRide: %p\n", myRide);
    assert(myRide != NULL);

    myRide->make = strdup(make);
    myRide->model = strdup(model);
    myRide->year = year;
    myRide->vinNum = vinNum;

    return myRide;
}

void Vehicle_destroy(struct Vehicle *myRide)
{
    assert(myRide != NULL);

    free(myRide->make);
    free(myRide->model);
    free(myRide);
}

void Vehicle_print(struct Vehicle *myRide)
{
    printf("Make: %s\n", myRide->make);
    printf("Model: %s\n", myRide->model);
    printf("\tYear: %d\n", myRide->year);
    printf("\tVIN: %d\n", myRide->vinNum);
}

int main(int argc, char *argv[])
{
    // make two vehicle structures
    struct Vehicle *classic = Vehicle_create(
            "Mercedes-Benz", "300 SEL", 1972, 1234567890);

    struct Vehicle *betsy = Vehicle_create(
            "Hyundai", "Accent", 1999, 2147483647);

printf("classic %p\n", classic);
printf("classic make %p\n", classic->make);
printf("classic model %p\n", classic->model);

    // print them out and where they are in memory
    printf("Classic is at memory location %p:\n", classic);
    Vehicle_print(classic);

    printf("Betsy is at memory location %p:\n", betsy);
    Vehicle_print(betsy);

    printf("Size of Vehicle Structure is %ld:\n", sizeof(struct Vehicle));
    struct Vehicle *myRide;
    printf("Size of Make is %ld, size of model is %ld, size of year is %ld, size of vin is %ld:\n", sizeof(myRide->make),sizeof(myRide->model),sizeof(myRide->year),sizeof(myRide->vinNum));
    Vehicle_print(betsy);

    // destroy them both so we clean up
    Vehicle_destroy(classic);
    Vehicle_destroy(betsy);

    return 0;
}
