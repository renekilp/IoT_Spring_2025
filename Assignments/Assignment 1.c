#include <stdio.h>

// Exercise 1 - Bus & Taxi price check *COMPLETED*

int main(void)
{
  float bus_ticket;
  float taxi_price;
  float balance;
  int selection;

  printf("Enter price of the bus ticket:\n");
  scanf("%f", &bus_ticket);
  printf("Enter price of the taxi:\n");
  scanf("%f", &taxi_price);
  printf("How much money do you have?:\n");
  scanf("%f", &balance);
  printf("Your current balance is: %.2f\n", balance);

  while (balance >= bus_ticket || balance >= taxi_price) {

    printf("Choose your preferred choice of transport (1-2):\n");
    printf("1. Bus (%.2f)\n", bus_ticket);
    printf("2. Taxi (%.2f)\n", taxi_price);
    scanf("%d", &selection);

    if (selection == 1 && balance >= bus_ticket) {
      balance -= bus_ticket;
      printf("You chose the bus! Vroom vroom!\n");
      printf("Your current balance is: %.2f\n", balance);

    } else if (selection == 1 && balance <= bus_ticket) {
      printf("You don't have enough money for a bus ticket...\n");
      printf("Your current balance is: %.2f\n", balance);

    } else if (selection == 2 && balance >= taxi_price) {
      balance -= taxi_price;
      printf("You chose the taxi! How fancy!\n");
      printf("Your current balance is: %.2f\n", balance);

    } else if (selection == 2 && balance <= taxi_price) {
      printf("You don't have enough money for a taxi...\n");
      printf("Your current balance is: %.2f\n", balance);
    }
  }
  printf("Looks like you don't have enough money left! Well, walking is healthier anyways. :)");
  return 0;
}