#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exercise 6 - Roll D6 or D10

void print_menu(void)
{
  printf("------- | Let's roll a dice! | --------\n");
  printf("|      Pick your poison! (1-3)        |\n");
  printf("|  1. Roll a D6                       |\n");
  printf("|  2. Roll a D10                      |\n");
  printf("|  3. Quit                            |\n");
  printf("---------------------------------------\n");
}

int read_integer(void)
{
  int number;
  while (1) {
    if (scanf("%d", &number) != 1) {
      while (getchar() != '\n');
      printf("Invalid input! Please enter a valid selection number.\n");
      continue;
    }
    if (number < 1 || number > 3) {
      printf("The selection %d is out of range! Please try again.\n", number);
      continue;
    }
    return number;
  }
}

int dice_roll(user_selection)
{

  if (user_selection == 1) {
    printf("Rolling a D6...\n");
  } else if (user_selection == 2) {
    printf("Rolling a D10...\n");
  }

  return 0;
}

int main(void)
{
  int user_selection;

  while (1) {
    print_menu();
    user_selection = read_integer();
    if (user_selection == 3 ) {
      break;
    }
  }
  return 0;
}