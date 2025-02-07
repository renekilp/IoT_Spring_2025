#include <stdio.h>
#include <ctype.h>

int main(){

    char unit;
    float temp;

    printf("Is the temperature in (F) or (C)?\n");
    scanf("%c", &unit);

    unit = toupper(unit);   // changes the userinput to uppercase

    if(unit == 'C'){
        printf("Enter the temp in Celsius:\n");
        scanf("%f", &temp);
        temp = (temp * 9 / 5 + 32);
        printf("The temp in Farenheit is %.1f", temp);
    }
    else if(unit == 'F'){
        printf("Enter the temp in Farenheit:\n");
        scanf("%f", &temp);
        temp = ((temp - 32) * 5) / 9;
        printf("The temp in Celcius is %.1f", temp);
    }
    else{
        printf("%c is not a valid unit of measurement!", unit);
    }

    return 0;
}