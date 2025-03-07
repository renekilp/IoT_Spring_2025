#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Exercise 16 - numbers in a linked list where each node is dynamically allocated *COMPLETED*
// this one was a bit tricky

#define MAX_INPUT_LENGTH 20

typedef struct node {
    int number;
    struct node *next;
} nnode;

/* this function releases the allocated memory for all
   nodes in the linked list vvv (needed some external help with this part) */
void free_list(nnode *head) {
    nnode *temp;
    while (head != NULL) {
        temp = head;
        // moves 'head' to the next node vvv
        head = head->next;
        free(temp);
    }
}

// this function prints the values stored in the linked list vvv
void print_list(nnode *head) {
    nnode *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->number);
        // moves 'temp' to the next node vvv
        temp = temp->next;
    }
}

int main(void)
{
    // pointers to the first nodes (initially empty) vvv
    nnode *head = NULL;
    nnode *tail = NULL;
    nnode *new_node;

    char input[MAX_INPUT_LENGTH];
    int num;

    while (1) {
        printf("Please enter a number (or 'end' to stop):\n");
        scanf("%19s", input);

        if (strcmp(input, "end") == 0) {
            break;
        }

        if (sscanf(input, "%d", &num) != 1) {
            printf("Invalid input! :( Please try again!.\n");
            continue;
        }

        /* this allocates the memory for a new node
           and gives an error if something goes with the allocating vvv*/
        new_node = (nnode*)malloc(sizeof(nnode));
        if (new_node == NULL) {
            printf("There was an error with the memory allocation!\n");
            free_list(head);
            return 1;
        }
        new_node->number = num;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // and lastly prints the inputted numbers vvv
    printf("Here are the numbers you entered! :)\n");
    print_list(head);
    free_list(head);

    return 0;
}

