#include <stdio.h>
#include <string.h>

// Exercise 12 - input string word count *COMPLETED*
// this one was also a bit tricky (mostly the 'count_words' function part)

#define MAX_LENGTH 100

int count_words(const char *str, const char *word) {
  int count = 0;
  // points to the start of str vvv
  const char *pointer = str;
  size_t word_length = strlen(word);

  while ((pointer = strstr(pointer, word)) != NULL) {
    count++;
    // moves on to the next occurence vvv
    pointer += word_length;
  }

  return count;
}

int main(void)
{
  char str[MAX_LENGTH];
  char word[MAX_LENGTH];

  while (1) {
    printf("Please enter a string of choice! (or 'stop' to exit!):\n");
    fgets(str, sizeof(str), stdin);
    // newline check and replace vvv
    str[strcspn(str, "\n")] = '\0';

    if (strcmp(str, "stop") == 0) {
      break;
    }

    printf("Thanks! Now enter a word to count (or 'stop' to exit!):\n");
    fgets(word, sizeof(word), stdin);
    // newline check and replace vvv
    word[strcspn(word, "\n")] = '\0';

    if (strcmp(word, "stop") == 0) {
      break;
    }

    printf("The word '%s' appears %d times in the string.\n", word, count_words(str, word));
  }

  printf("Exiting the program. Goodbye! :)\n");
  return 0;
}
