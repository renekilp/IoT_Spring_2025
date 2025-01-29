#include <stdio.h>

// Saana's lecture about pointers - Material from OMA (6.Pointers.pdf)

//swap1: swaps copies of values (so it won't work)
void swap1(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// swap2: swaps values at the addresses given
void swap2(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    int m = 0, n = 1;
    printf("Starting values: m, n = %d, %d\n", m, n);
    swap1(m, n); /* call by value */
    printf("After swap1(): m, n = %d, %d\n", m, n);
    swap2(&m, &n); /* call by reference */
    printf("After swap2(): m, n = %d, %d\n\n", m, n);
    return 0;
}

