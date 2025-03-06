#include <stdio.h>
#include <string.h>

#define FILE_NAME_SIZE 20
#define MAX_ITEMS 40

/* I created a file (test) with the following items inside (including the items from the exercise description):
        Mega double burger with bacon and cheese; 23.50
        Belgian style fries with vegan mayo; 5.60
        Chicken nuggets with vegan mayo; 5.30
        Chocolate ice cream with vanilla swirl; 4.40
        Megaforce energy drink; 0.99   */

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int main(void)
{
    menu_item menu[MAX_ITEMS];
    char filename[FILE_NAME_SIZE];
    FILE *file;
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

    // acts as a "buffer" for reading the entire line (name and price) vvv
    char line[100];

    // (had to do some research for the following) vvv
    while (count < MAX_ITEMS && fgets(line, sizeof(line), file)) {
        // finds the semicolon and separate the name and price vvv
        char *semicolon_pos = strchr(line, ';');
        if (semicolon_pos != NULL) {
            // replaces the semicolon with the null terminator to end the name vvv
            *semicolon_pos = '\0';
            // then reads the price from the remaining part of the line after the semicolon vvv
            // this one reads the price vvv
            sscanf(semicolon_pos + 1, " %lf", &menu[count].price);
            // this copies the name vvv
            strncpy(menu[count].name, line, sizeof(menu[count].name));
            count++;
        }
    }
    fclose(file);

    // and finally prints the items from the file vvv
    for (int i = 0; i < count; i++) {
        printf("%8.2f %s\n", menu[i].price, menu[i].name);
    }
    /*  OUTPUT looks like this:

       23.50 Mega double burger with bacon and cheese
        5.60 Belgian style fries with vegan mayo
        5.30 Chicken nuggets with vegan mayo
        4.40 Chocolate ice cream with vanilla swirl
        0.99 Megaforce energy drink

    */

    return 0;
}
