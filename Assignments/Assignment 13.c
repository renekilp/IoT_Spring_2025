#include <stdio.h>
#include <stdlib.h>

// Exercise 13 - read file number (min, max, count) *COMPLETED*

// added this for the "spice" (usually file names a short) vvv
#define FILE_NAME_SIZE 20

/* I created 3 different test files for the exercise ("test", "pos_numbers", "neg_numbers")
   but didn't bother pushing them to GitHub...*/

int main(void)
{
    char filename[FILE_NAME_SIZE];
    FILE *file;

    int num;
    int min;
    int max;
    int count = 0;

    printf("Enter the name of your file:\n");
    // if there is an error with the file name input vvv
    // at most 99 characters are read, leaving space for the null terminator ('\0') vvv
    if (scanf("%99s", filename) != 1) {
        fprintf(stderr, "There seems to be an issue with the filename.\n");
        return 1;
    }

    file = fopen(filename, "r");
    // if can't find the file vvv
    if (file == NULL) {
        fprintf(stderr, "Cannot open the file: %s! Maybe it's missing. :(\n", filename);
        return 1;
    }

    // if the file is found vvv
    if (fscanf(file, "%d", &num) == 1) {
        count = 1;
        min = num;
        max = num;

        // keeps track of the highest and lowest found number and increases the number count vvv
        while (fscanf(file, "%d", &num) == 1) {
            count++;
            if (num < min) min = num;
            if (num > max) max = num;
        }
    }

    // and lastly prints the results vvv
    printf("Numbers read: %d\n", count);
    if (count > 0) {
        printf("Lowest number: %d\n", min);
        printf("Highest number: %d\n", max);
    }

    fclose(file);
    printf("Done! Exiting program. :)");
    return 0;
}