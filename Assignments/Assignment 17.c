#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Exercise 17 - randomized password with an inputted word *COMPLETED*

#define MAX_INPUT_SIZE 32
#define PRINT_START 33
#define PRINT_END 126

// this function generates the password vvv
bool generate_password(char *password, int size, const char *word) {
    int word_length = strlen(word);
    int pass_length = word_length * 2 + 1;

    // this part checks if password fits vvv
    if (size < pass_length + 1) {
        return false;
    }

    for (int i = 0; i < pass_length; i++) {
        if (i % 2 == 0) {
            // randomization vvv
            password[i] = (char)(rand() % (PRINT_END - PRINT_START + 1) + PRINT_START);
        } else {
            password[i] = word[i / 2];
        }
    }
    password[pass_length] = '\0';
    return true;
}

int main(void)
{
    char input[MAX_INPUT_SIZE];
    char password[MAX_INPUT_SIZE * 2 + 1];
    srand(time(NULL));

    while (1) {
        printf("Please enter a word to generate a password (or 'stop' to exit):\n");
        scanf("%31s", input);

        if (strcmp(input, "stop") == 0) {
            break;
        }

        if (generate_password(password, sizeof(password), input)) {
            printf("Here's your generated password! :)\n%s\n", password);
        } else {
            printf("Your choice of word was too long. :(\n");
        }
    }

    return 0;
}

