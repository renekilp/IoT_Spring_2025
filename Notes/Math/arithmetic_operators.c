#include <stdio.h>

// 6 # lecture materials vvv

int main (){

    /*  arithmetic operators

        + (addition)
        - (substraction)
        * (multipication)
        / (division)
        % (modulus)
        ++ increment
        --decrement

    */

    int x = 5;
    int y = 2;

    int a = x - y;
    float b = x / (float) y;

    int c = x % y;

    x++;
    y--;

    printf("%d\n", a);
    printf("%f\n", b);
    printf("%d\n", c);
    printf("%d\n", x);
    printf("%d\n", y);


    return 0;
}