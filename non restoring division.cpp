#include <stdio.h>

// Function to perform non-restoring division
void nonRestoringDivision(int dividend, int divisor) {
    int quotient = 0, remainder = 0, negDivisor = -divisor;

    printf("Performing Non-Restoring Division for %d / %d:\n\n", dividend, divisor);
    printf("Step\t Dividend\t Quotient\t Subtraction\n");

    // Initializing the dividend with the first bits of the number
    for (int i = 31; i >= 0; i--) {
        remainder = (remainder << 1) | ((dividend >> i) & 1);
        printf("%d\t %d\t\t %d\t\t ", 32 - i, remainder, quotient);

        // Shift remainder left and add 1 if negative, else add 0
        remainder = (remainder << 1) | (remainder < 0 ? 1 : 0);

        // Perform subtraction
        remainder += remainder < 0 ? divisor : negDivisor;

        printf("%d\n", remainder);

        // Update quotient
        quotient = (quotient << 1) | (remainder < 0 ? 1 : 0);
    }

    // Print final quotient and remainder
    printf("\nQuotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);
}

int main() {
    int dividend, divisor;

    // Input the dividend and divisor
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    // Perform non-restoring division
    nonRestoringDivision(dividend, divisor);

    return 0;
}

