#include <stdio.h>

// Exercise 4 - Positive numbers, average using a function *COMPLETED*

int read_integer(void)
{

  int number;

  // trying out the "input validation" provided by the exercise material pdf
  while (1) {
    printf("Enter positive numbers or negative to stop:\n");
    if (scanf("%d", &number) == 1) {
      return number;
    }
    printf("Invalid input. Please enter only positive numbers!\n");
    while (getchar() != '\n');
    // seems to be working fine :)
  }
}

int main(void)
{

  /*
      'count' keeps track of the positive numbers entered
      'total' keeps track of the sum of the entered numbers (unless it's a negative which breaks the loop)
  */

  int count = 0;
  int total = 0;
  int number;
  float average;

  while (1) {
    number = read_integer();

    if (number < 0) {
      break;
    }
    total += number;
    count++;
  }

  // final calculations for the average
  if (count > 0) {
    average = (float)total / count;
    printf("You entered %d positive numbers.\n", count);
    printf("The average is: %.3f\n", average);
  }
  return 0;
}


