#include <stdio.h>
#include <string.h>

// Exercise 10 - input array string check *COMPLETED*

#define LENGTH 50

int main(void)
{
  char input[LENGTH];

  while (1) {

    printf("Please enter a string (the max is %d characters!):\n", LENGTH);

    if (fgets(input, LENGTH, stdin) == NULL) {
      /* I tried to implement an error handling part, but couldn't make it work properly...
         now if the max length is exceeded, the program will just handle the string multiple times */
      return 1;
    }

    // size_t - found this from 'geeksforgeeks.org' (good for representing the size of objects in bytes)
    // this calculates the length of the string vvv
    size_t len = strlen(input);

    // checks if the last character is a newline and that the string is not empty vvv
    if (len > 0 && input[len - 1] == '\n') {
      input[len - 1] = '\0';
      len--;
    }

    if (strcmp(input, "stop") == 0) {
      break;
    }

    // have to use %zu when "printing" the value of a size_t variable vvv
    printf("The length of your input is %zu!\n", len);
  }

  printf("Goodbye! :)\n");
  return 0;
}