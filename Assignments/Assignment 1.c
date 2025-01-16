#include <stdio.h>

/*
    Write a program that:

        1. Asks user to enter the price of a bus ticket
        2. Asks user to enter the price of a taxi trip
        3. Asks user to enter how much money he/she has
        4. If user has not enough money for either type tells user to walk and then the program stops
        5. Asks user to choose taxi or bus (use numbers for selection)
        6. Checks if user has enough money for the selected trip type

                * If User has enough money reduce the money by the selected trip’s price and print
                  how much money is left, and go back to step 4
                * If user has not enough money for the selected trip type then tell that to user and go
                  back to step 4
 */

int main(void)
{
  float bus_price;
  float taxi_price;
  float user_money;
  int selection;

  printf("What's the price of the bus ticket?\n");
  scanf("%f", &bus_price);

  printf("What's the price of the taxi?\n");
  scanf("%f", &taxi_price);

  printf("How much money do you have?\n");
  scanf("%f", &user_money);

  /* ADD WHILE LOOP

  printf("Which transport option would you like?\n");
  printf("1. Price of a bus ticket: (%f)\n",bus_price);
  printf("2. Price of the taxi: (%f)\n", taxi_price);
  scanf("%d", &selection);

  */






}