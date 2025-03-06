#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Exercise 14 - read file text (write content -> uppercase) *COMPLETED*

#define FILE_NAME_SIZE 20
#define MAX_LINES 100
#define MAX_LENGTH 80

/* I created a file (test) with the following text inside:
       "this is a test file.
	    what a lovely day!"    */

int main(void)
{
    char filename[FILE_NAME_SIZE];
    FILE *file;
    //+ 1 extra space for the null terminator ('\0') vvv
    char lines[MAX_LINES][MAX_LENGTH + 1];
    int count = 0;

    printf("Enter the name of your file:\n");
    // if there is an error with the file name input vvv

    /* at most 19 characters are read, leaving space for the null terminator ('\0') vvv
       (I had to "hardcode" the 19 character value since couldn't find a way to use the
       FILE_NAME_SIZE with the 'scanf' function) */
    if (scanf("%19s", filename) != 1) {
        fprintf(stderr, "There seems to be an issue with the filename.\n");
        return 1;
    }

    file = fopen(filename, "r");
    // if can't find the file vvv
    if (file == NULL) {
        fprintf(stderr, "Cannot open the file: %s! Maybe it's missing. :(\n", filename);
        return 1;
    }

    /* makes sure that at most MAX_LINES are read and
       reads a line from file into lines[count],
       with a maximum of MAX_LENGTH + 1 characters vvv */
    while (count < MAX_LINES && fgets(lines[count], MAX_LENGTH + 1, file) != NULL) {
        count++;
    }

    fclose(file);

    for (int i = 0; i < count; i++) {
        for (int j = 0; lines[i][j] != '\0'; j++) {
            // converts lowercase letters to uppercase vvv
            lines[i][j] = toupper((unsigned char)lines[i][j]);
        }
    }

    file = fopen(filename, "w");
    // if there is an error with 'writing' the file vvv
    if (file == NULL) {
        fprintf(stderr, "Cannot edit the file: %s ! Please try again.\n", filename);
        return 1;
    }

    // 'writes' each stored line from the lines array back into the file vvv
    for (int i = 0; i < count; i++) {
        fputs(lines[i], file);
    }

    printf("Done! All of the letters should be now in uppercase! Go take a look. :)");
    fclose(file);
    return 0;
}
