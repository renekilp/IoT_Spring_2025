#include <stdio.h>
#include <stdbool.h>

#define MAX_TRIES 3

bool read_positive(int *value) {
    printf("Enter a positive number: ");
    
    if (scanf("%d", value) != 1) {
        while (getchar() != '\n'); 
        printf("Incorrect input\n");
        return false;
    }

    if (*value <= 0) {
        printf("Incorrect input\n");
        return false;
    }

    return true;
}

int main(void) {
    int value;
    int attempts = 0;

    while (attempts < MAX_TRIES) {
        printf("Guess how much money I have!\n");

        if (read_positive(&value)) {
            int actual_money = (value * 2) + 20;
            printf("You didn’t get it right. I have %d euros.\n", actual_money);
        } else {
            attempts++; 
        }
    }

    printf("I give up! See you later!\n");
    return 0;
}
