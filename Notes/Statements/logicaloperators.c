#include <stdio.h>
#include <stdbool.h>

int main(){
    

    // logical operators = && (AND) checks if two conditions are true

    float temp = 25;
    bool sunny = true;

    if(temp >= 0 && temp <= 30 && sunny){
        printf("The weather is good\n");
    }
    else{
        printf("The weather is bad!\n");
    }


    // logical operators = || (OR) checks if at least one condition is true

    float temp2 = 25;

    if (temp2 <= 0 || temp >= 30){
        printf("The weather is BAD!\n");
    }
    else{
        printf("The weather is GOOD!\n");
    }


    // logical operators =! (NOT) reverses the state of a condition

    if(!sunny){
        printf("It's cloudy outside!\n");
    }
    else{
        printf("It's sunny outside!\n");
    }

    return 0;
}