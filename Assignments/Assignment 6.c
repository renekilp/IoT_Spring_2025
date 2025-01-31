#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exercise 6 - Roll D6 or D10 *COMPLETED*

// function for the "very cool" menu vvv
void print_menu(void)
{
  printf("------- | Let's roll a dice! | --------\n");
  printf("|      Pick your poison! (1-3)        |\n");
  printf("|  1. Roll a D6                       |\n");
  printf("|  2. Roll a D10                      |\n");
  printf("|  3. Quit                            |\n");
  printf("---------------------------------------\n");
}

// validates the user input vvv
int read_integer(void)
{
  int number;
  while (1) {
    if (scanf("%d", &number) != 1) {
      while (getchar() != '\n');
      printf("Invalid input! Please enter a valid selection number.\n");
      print_menu(); // <-
      continue;
    }
    if (number < 1 || number > 3) {
      printf("The selection %d is out of range! Please try again.\n", number);
      print_menu(); // <-
      continue;
      /* had to include print menu function here for both statements ^^^,
        cuz couldn't make it show up if the output was invalid */
    }
    return number;
  }
}

// handles both D6 and D10 rolls vvv
int dice_roll(int dice_type)
{
  int result;

  if (dice_type == 1) {
    //a D6 roll
    result = rand()/((RAND_MAX + 1u)/6) + 1;
    printf("Rolling a D6... You got %d!\n", result);

  } else if (dice_type == 2) {
    // a D10 roll
    result = rand()/((RAND_MAX + 1u)/10) + 1;
    printf("Rolling a D10... You got %d!\n", result);
  }
  return result;
}

// and finally the main
int main(void)
{
  srand(time(NULL));
  int user_selection;

  while (1) {
    // prints the menu again after every selection (other than quit)
    print_menu();
    user_selection = read_integer();

    if (user_selection == 3 ) {
      printf("Quitting the game... Thanks for playing! :)\n");
      break;
    }
    dice_roll(user_selection);
  }
  return 0;
}