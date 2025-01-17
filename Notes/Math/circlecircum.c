#include <stdio.h>

// 9 # lecture materials vvv *ENABLE* terminal output in settings!

int main(){
    
    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("Enter the radius of a circle:\n");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    area = PI * radius * radius;

    printf("Circumference: %lf\n", circumference);
    printf("Area: %lf", area);
    
    return 0;
}