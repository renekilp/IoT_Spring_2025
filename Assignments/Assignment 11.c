#include <stdio.h>
#include <string.h>

// Exercise 11 - input string modification *COMPLETED*
// this one was actually really tricky...

int replace_char(char *str, const char *modified) {
  int count = 0;

  // checks that modified contains 2 characters vvv
  if (strlen(modified) != 2) {
    return 0;
  }

  char target = modified[0];
  char replacement = modified[1];

  while (*str) {
    if (*str == target) {
      // keeps track on the modification count vvv
      *str = replacement;
      count++;
    }
    str++;
  }
  // and finally returns the count vvv
  return count;
}

int main(void)
{
  char input[50];
  char modified[3];

  printf("Please enter a string (max 50 characters):\n");
  fgets(input, sizeof(input), stdin);

  // just like in exercise 10. this removes the newline at the end vvv
  size_t len = strlen(input);
  if (len > 0 && input[len - 1] == '\n') {
    input[len - 1] = '\0';
  }
  // asks for the letter and what to replace it with vvv
  printf("Enter two characters (e.g., e3): ");
  fgets(modified, sizeof(modified), stdin);

  // makes sure that there are only 2 characters vvv
  if (strlen(modified) != 2 || modified[1] == '\n') {
    printf("Invalid input. Please enter exactly two characters.\n");
    return 1;
  }

  int count = replace_char(input, modified);

  // for the output vvv
  if (count > 0) {
    printf("Here's the modified string: %s\n", input);
    printf("The amount of characters replaced: %d\n", count);

  } else {
    printf("Your string was not modified\n");
  }

  return 0;
}
