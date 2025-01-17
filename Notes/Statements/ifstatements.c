#include <stdio.h>

int main(){

    int age;

    printf("Enter your age:\n");
    scanf("%d", &age);    

    if(age >= 18){
        printf("You are now signed up!");
    }
    else if(age == 0){
        printf("You can't sign up! You were just born!");
    }
    else if(age < 0){
        printf("That's not a valid age.");
    }
    else{
        printf("You are too young to sign up.");
    }

    return 0;
}