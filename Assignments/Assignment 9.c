#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exercise 9 - array of random numbers + input search index *COMPLETED*

#define ARRAY_SIZE 20
#define RANGE 20

int find_first(const unsigned int *array, unsigned int what)
{
    // searches for the given number or 0 vvv
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == what) {
            // returns if found vvv
            return i;
        }
    }
    // or if not found vvv
    return -1;
}

int main(void)
{
    unsigned int numbers[ARRAY_SIZE];

    /* Had to use 'int' input to fix an issue with error handling.
       Apparently you can't check negative integers with
       'unsigned int'. vvv                                       */

    int input;
    srand(time(NULL));

    // fills the array with random numbers from 1 - 20 vvv
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        numbers[i] = (rand() % RANGE) + 1;
    }

    // sets the last value to 0 as the "end marker" vvv
    numbers[ARRAY_SIZE - 1] = 0;

    printf("Here's the array:\n");
    // prints the array one number per line vvv
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%u\n", numbers[i]);
    }

    while (1) {
        printf("\nPlease enter a number (or 0 to QUIT):\n");

        // error handlings vvv
        if (scanf("%d", &input) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please try again!\n");
            continue;
        }

        if (input < 0) {
            printf("Invalid input. Please try again!\n");
            continue;
        }

        // converting the datatype after the error handling
        unsigned int value = input;

        if (value == 0) {
            break;
        }

        int index = find_first(numbers, value);

        // searching print vvv
        if (index != -1) {
            printf("Number %u found at index %d!\n", value, index);
        } else {
            printf("Number %u not found!\n", value);
        }
    }

    printf("Exiting the program. Goodbye! :)\n");
    return 0;
}
