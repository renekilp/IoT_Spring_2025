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
    float excess_income = 0;
    float taxable_lower = 0;

    printf("Enter your tax rate:\n");
    scanf("%f", &tax_rate);
    printf("Enter your yearly income limit:\n");
    scanf("%f", &income_limit);
    printf("Enter your additional tax rate:\n");
    scanf("%f", &additional_tax_rate);

    for (int i = 0; i < MONTHS; i++) {
                                        // (starts the num. from 1 v)
        printf("What's your income for the month %d:\n", i + 1);
        scanf("%f", &income[i]);

        // this checks how much the income goes over the yearly income limit vvv
        if (total_income + income[i] > income_limit) {
            excess_income = total_income + income[i] - income_limit;

            // this one handles the tax for the excess income and for the income before going over the limit vvv
            if (total_income < income_limit) {
                taxable_lower = income[i] - excess_income;
                tax[i] = (taxable_lower * (tax_rate / 100)) + (excess_income * (additional_tax_rate / 100));

                // if the income goes over the limit vvv
            } else {
                tax[i] = income[i] * (additional_tax_rate / 100);
            }

            // normal tax rate vvv
        } else {
            tax[i] = income[i] * (tax_rate / 100);
        }

        // keeps track if the mont's income should be taxed with lower or higher rate vvv
        total_income += income[i];
    }

    printf("%-5s%12s%12s\n", "Month", "Income", "Tax");
    for (int i = 0; i < 12; i++) {
        printf("%5d%12.2f%12.2f\n", i + 1, income[i], tax[i]);

    /*  OUTPUT looks like this:

     Month      Income         Tax
         x           x           x
         x           x           x

    */
    }
    return 0;
}