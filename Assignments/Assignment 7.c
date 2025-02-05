#include <stdio.h>
#include <stdbool.h>

// Exercise 7 - "Guessing" game

#define ROUNDS 3

bool read_positive (int *value)
{
  printf("Please enter a postive number:\n");

  if (scanf("%d", value) != 1) {
    while (getchar() != '\n');
    printf("Invalid input. Please try again!\n");
    return false;
  }
  if (*value <= 0) {
    printf("Please enter only positive numbers.\n");
    return false;
  }
  return true;
}

int main(void)
{
  int value;
  int round_count = 0;

  while (round_count < ROUNDS) {
    printf("Guess how much money I have! :)\n");
    if (read_positive(&value)) {
      int cheat_value = (value * 2) + 20;
      printf("That's too bad! I have: %d euros. xD\n", cheat_value);
      round_count++;
    }
  }
  printf("I give up. See you next time!\n");
}

