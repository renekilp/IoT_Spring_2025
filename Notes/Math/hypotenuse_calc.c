#include <stdio.h>
#include <math.h>

// 10 # lecture materials vvv *ENABLE* terminal output in settings!

int main(){

    double A;
    double B;
    double C;

    printf("Enter side A:\n");
    scanf("%lf", &A);

    printf("Enter side B:\n");
    scanf("%lf", &B);

    C = sqrt(A*A + B*B);

    printf("Side C: %lf", C);

    return 0;
}