#include <stdio.h>

int main() {
    float num1, num2, product, quotient;

    // Input the numbers
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    // Perform multiplication
    product = num1 * num2;

    // Check if the divisor is not zero
    if (num2 != 0) {
        // Perform division
        quotient = num1 / num2;
        printf("Quotient: %.2f\n", quotient);
    } else {
        printf("Cannot divide by zero.\n");
    }

    // Display results
    printf("Product: %.2f\n", product);

    return 0;
}

