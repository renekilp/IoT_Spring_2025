#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exercise 18 - input + random hex *COMPLETED*

// this keeps only bits 0-5 vvv
#define BIT_LIMIT 0x3F

int main(void)
{
    int input;
    srand(time(NULL));

    while (1) {
        printf("Please enter a number between 0-15 (or a negative number to stop):\n");
        scanf("%d", &input);

        if (input < 0) {
            break;
        }

        if (input >= 0 && input <= 15) {
            // random number vvv
            int random_number = rand();
            printf("Random number (hex): %X\n", random_number);

            // shifts right the amount of the input vvv
            int shift = random_number >> input;
            int result = shift & BIT_LIMIT;

            // and finally the result vvv
            printf("The number in binary after shifting (%d times): %02X\n",input, result);
        } else {
            printf("Invalid input! :( Please enter a number between 0 and 15.\n");
        }
    }

    return 0;
}
