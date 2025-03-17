#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Exercise 19 - sorting options for ex. 15 *COMPLETED*
// (reuses a lot of code from the exercise 15)

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

// sorts by price vvv
int compare_by_price(const void *a, const void *b) {
    double price1 = ((menu_item *)a)->price;
    double price2 = ((menu_item *)b)->price;
    return (price1 > price2) - (price1 < price2); // Returns -1, 0, or 1
}

// sorts by name vvv
int compare_by_name(const void *a, const void *b) {
    return strcmp(((menu_item *)a)->name, ((menu_item *)b)->name);
}

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
    while (count < MAX_ITEMS && fgets(line, sizeof(line), file)) {
        char *semicolon_pos = strchr(line, ';');
        if (semicolon_pos != NULL) {
            *semicolon_pos = '\0';
            sscanf(semicolon_pos + 1, " %lf", &menu[count].price);
            strncpy(menu[count].name, line, sizeof(menu[count].name) - 1);
            menu[count].name[sizeof(menu[count].name) - 1] = '\0'; // Ensure null-termination
            count++;
        }
    }
    fclose(file);

    // asks for the sorting option vvv
    int choice;
    printf("Choose your sorting order!\nSort by price - 1\nSort by name - 2\n");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice! :( Please enter either 1 for price or 2 for name:\n");
        while (getchar() != '\n');
    }

    // and then sorts depending on the option selected vvv
    if (choice == 1) {
        qsort(menu, count, sizeof(menu_item), compare_by_price);
    } else {
        qsort(menu, count, sizeof(menu_item), compare_by_name);
    }

    // and finally...
    printf("Here's your sorted menu! :)\n");
    for (int i = 0; i < count; i++) {
        printf("%8.2f %s\n", menu[i].price, menu[i].name);
    }

    return 0;
}
