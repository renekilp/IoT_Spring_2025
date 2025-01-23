#include <stdio.h>

// Exercise 3 - Student number + grade *COMPLETED*

int main(void)
{
    int student_count;
    int student_number;
    int grade;

    printf("How many students are there?:\n");
    scanf("%d", &student_count);

    int grades[student_count];

    // gives a default value of -1 for all the grades -> turns into "N/A" later with the output
    for (int i = 0; i < student_count; i++) {
        grades[i] = -1;
    }

    while (1) {

        printf("Please choose a student. (1 - %d, enter 0 to STOP):\n", student_count);
        scanf("%d", &student_number);

        if (student_number < 0 || student_number > student_count) {
            printf("That's not a valid student... Please try again!\n");
            continue;
        }

        if (student_number == 0) {
            break;
        }
        /*
           had to implement an inner while loop to prevent the code from jumping back to student number check
           if the grade input goes out of bound vvv
        */
        while (1) {
            printf("Please enter a grade for the student %d. (0 - 5, enter -1 to CANCEL):\n", student_number);
            scanf("%d", &grade);

            if (grade < -1 || grade > 5) {
                printf("That's not a valid grade... Please try again!\n");

            } else {
                // saves the grade for the student vvv
                grades[student_number - 1] = grade;

                // handles the cancellation (and doesn't save the code since the default value is -1)
                if (grade != -1) {
                }
                break;
            }
        }
    }

    printf("%-10s%8s\n", "Student", "Grade");
    for (int i = 0; i < student_count; i++) {
        // prints the student number vvv
        printf("%-8d", i + 1);
        // this one handles printing "N/A" if value == -1
        if (grades[i] == -1) {
            printf("%8s\n", "N/A");
        } else {
            // and lastly the grade...
            printf("%6d\n", grades[i]);

            /* OUTPUT looks like this:

               Student   Grade
               x         x
               x         N/A

            */
        }
    }
    return 0;
}
