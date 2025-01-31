#include <stdio.h>

// Exercise 5 - Cheating "dice" *COMPLETED*

#define HIGH 6
#define LOW 1
#define ROUNDS 3

int read_integer(int low, int high)
{
  int number;

  while (1) {
    printf("Enter your number (between %d and %d):\n", low, high);

    // error handling for invalid inputs vvv
    if (scanf("%d", &number) != 1) {
      while (getchar() != '\n');
      printf("Invalid input! Please enter a valid number.\n");
      continue;
    }

    // (also invalid inputs don't progress the rounds)
    if (number < LOW || number > HIGH) {
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

  // loops for x rounds (3, since it's defined) vvv
  for (int i = 1; i <= ROUNDS; i++) {
    printf("Roll a dice and enter your result:\n");
    typed_number = read_integer(LOW, HIGH);

    // check for tie if HIGH (6) is selected vvv
    if (typed_number == HIGH) {
      roll_dice = HIGH;
      printf("We both rolled 6. It's a tie! :)\n");
    } else {

      // this is where the cheating happens vvv
      roll_dice = typed_number + 1;
      printf("I rolled a %d. Looks like I win!\n", roll_dice);
    }
  }

  printf("Better luck next time. Goodbye! :) \n");
  return 0;
}