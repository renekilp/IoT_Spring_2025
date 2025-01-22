#include <stdio.h>

// Exercise 2 - Yearly income + tax *COMPLETED*

#define MONTHS 12

int main(void)
{
    float income[MONTHS];
    float tax[MONTHS];
    float tax_rate;
    float additional_tax_rate;
    float income_limit;
    float total_income = 0;

    printf("Enter your tax rate:\n");
    scanf("%f", &tax_rate);
    printf("Enter your yearly income limit:\n");
    scanf("%f", &income_limit);
    printf("Enter your additional tax rate:\n");
    scanf("%f", &additional_tax_rate);

    for (int i = 0; i < MONTHS; i++) {
        printf("What's your income for the month %d:\n",i + 1);
        scanf("%f", &income[i]);
        total_income += income[i];
        if (total_income > income_limit) {
            tax[i] = income[i] * (additional_tax_rate / 100);
        } else {
            tax[i] = income[i] * (tax_rate / 100);
        }
    }
    printf("%-5s%12s%12s\n", "Month", "Income", "Tax");
    for (int i = 0; i < 12; i++) {
        printf("%5d%12.2f%12.2f\n", i + 1, income[i], tax[i]);
    }

    return 0;
}