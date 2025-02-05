#include <stdio.h>
#include <stdbool.h>

// Exercise 7 - Money guessing *COMPLETED*

#define INVALID_ATTEMPTS 3

bool read_positive(int *value) {
    printf("Enter a positive number:\n");

    // error handling vvv (same old)
    if (scanf("%d", value) != 1) {
        while (getchar() != '\n'); 
        printf("Invalid input. Try again!\n");
        return false;
    }

    if (*value <= 0) {
        printf("Invalid input. Try again!\n");
        return false;
    }

    return true;
}

int main(void) {
    int value;
    int attempts = 0;

    /* compares the attempts to set invalid amount (3 in this case) vvv
       and only increases the attempts if 'false' is returned */

    while (attempts < INVALID_ATTEMPTS) {
        printf("Guess how much money I have!\n");

        // cheating part if true is returned vvv
        if (read_positive(&value)) {
            int cheat_money = (value * 2) + 20;
            printf("Too bad. I have %d euros.\n", cheat_money);
        } else {
            // increases the attempts by one
            attempts++; 
        }
    }

    printf("I give up! Let's play again some other time! :)\n");
    return 0;
}
