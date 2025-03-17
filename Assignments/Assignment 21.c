#include <stdio.h>
#include <string.h>

//Exercise 21 - read file, GPS coords, check if bad or good [OK]/[FAIL] *COMPLETED*

#define FILE_NAME_SIZE 20
#define LINE_SIZE 100

// this function was tricky vvv
// computes checksum from the sentence vvv
int calculate_checksum(const char *line, int length) {
    int checksum = 0;

    // all characters between '$' and '*'
    for (int i = 1; i < length; i++) {
        if (line[i] == '*') {
            break;
        }
        checksum ^= line[i];
    }
    // and returns the checksum for comparison vvv
    return checksum;
}

int main(void)
{
    char filename[FILE_NAME_SIZE];
    char line[LINE_SIZE];
    FILE *file;

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

    // processes each line in the file vvv
    while (fgets(line, sizeof(line), file)) {
        // this checks if the line starts with the character '$' vvv
        if (line[0] != '$') {
            continue;
        }

        // this finds the character '*' in the line vvv
        char *asterisk_pos = strchr(line, '*');
        if (asterisk_pos == NULL) {
            // and skips if not found vvv
            continue;
        }

        // calculates the checksum from the line vvv
        int calculated_checksum = calculate_checksum(line, asterisk_pos - line);

        // extracts the expected checksum from the file (2 hex characters after '*') vvv
        int expected_checksum;
        if (sscanf(asterisk_pos + 1, "%2x", &expected_checksum) != 1) {
            // and skips if checksum is not properly formatted vvv
            continue;
        }

        // compares the calculated checksum with the expected checksum and prints to output vvv
        if (calculated_checksum == expected_checksum) {
            printf("[OK] %s", line);
        } else {
            printf("[FAIL] %s", line);
        }
    }

    fclose(file);
    return 0;
}
