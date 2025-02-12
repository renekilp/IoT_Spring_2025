#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exercise 8 - print numbers + pointers *COMPLETED*

#define COUNT_SIZE 15

void print_numbers(const int *array, int count) {

    for (int i = 0; i < count; i++) {
        // "eight characters wide field" vvv
        printf("%8d\n", array[i]);

        /* output example:
               99
                1
              100        */
    }
}

int main(void) {
    int numbers[COUNT_SIZE];

    srand(time(NULL));

    /* this fills the array with randomized numbers
       the min and max numbers weren't specified in the instructions,
       so I chose numbers between 1 - 100  vvv  */
    for (int i = 0; i < COUNT_SIZE; i++) {
        numbers[i] = rand() % 100 + 1;
    }

    print_numbers(numbers, COUNT_SIZE);
    return 0;
}