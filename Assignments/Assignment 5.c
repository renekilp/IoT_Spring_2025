#include <stdio.h>

// Exercise 5 - Cheating "dice" *COMPLETED*

int read_integer(int low, int high)
{
  int number;

  while (1) {
    printf("Enter your number (between %d and %d):\n", low, high);

    // error handling for invalid inputs vvv
    if (scanf_s("%d", &number) != 1) {
      while (getchar() != '\n');
      printf("Invalid input! Please enter a valid number.\n");
      continue;
    }

    // (also invalid inputs don't progress the rounds)
    if (number < low || number > high) {
      printf("The number %d is out of range. :( Please enter a new number!\n", number);
      continue;
    }

    return number;
  }
}

int main() {
  int typed_number;
  int roll_dice;

  printf("Let's play! :)\n");

  // loops for 3 rounds vvv
  for (int i = 1; i <= 3; i++) {
    printf("Roll a dice and enter your result:\n");
    typed_number = read_integer(1, 6);

    // check for tie if 6 is selected vvv
    if (typed_number == 6) {
      roll_dice = 6;
      printf("We both rolled 6. It's a tie! :)\n");
    } else {

      // this is where the cheatinng happens vvv
      roll_dice = typed_number + 1;
      printf("I rolled a %d. Looks like I win!\n", roll_dice);
    }
  }

  printf("Better luck next time. Goodbye! :) \n");
  return 0;
}
