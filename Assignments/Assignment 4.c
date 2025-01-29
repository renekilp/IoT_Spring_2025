#include <stdio.h>

// Exercise 4 - Interger checker + function


int number;
int numbers[];

int read_integer(void)
{
  if (number > 0) {
    return number;
  if (number != 1) {
    while(getchar() != '\n');
    printf("Invalid Input!\n");
  }
  return number;
}

int main(void)
{
  printf("Enter a positive number (or a negative number to quit:\n");
  scanf("%d",&number);

  return 0;
}