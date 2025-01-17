#include <stdio.h>


// 2 # lecture materials vvv

int main(){

    /* variable =   Allocted space in memory to store a value
                    We refer to variable's name to access the stored value
                    That variable now behaves as if it was the value it contains
                    BUT we need to declare what type of data we are storing
    */


    int x; // declaration
    x = 123; // initialization

    int y = 321; // declaration + initialization

    int age = 29; // integer

    float gpa = 2.05; // floating point number

    char grade = 'C'; // single character

    char name[] = "Rene"; // array of characters

    printf("Hello %s\n", name);
    printf("You are %d years old\n", age);
    printf("Your average grade is %c\n", grade);
    printf("Your gpa is %f\n", gpa);

    return 0;
}