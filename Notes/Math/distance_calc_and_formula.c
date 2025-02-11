#include <stdio.h>
#include <string.h>
#include <math.h>


struct point
{
    int x;
    int y;
};


double distance(struct point a, struct point b)
{
    /* the distance formula: 
       d = SQUARE_ROOT(x2 - x1)^2 + (y2 - y1)^2 */
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main(void)
{
    struct point p1 = { 5, 8 };
    struct point p2 = { -3, 3 };
    struct point p3 = { 0, 4 };
    struct point p4 = { 3, 0 };

    printf("%.3f\n", distance(p1, p2));
    printf("%.3f\n", distance(p3, p4));

    return 0;
}