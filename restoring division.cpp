#include <stdio.h>

// Function to perform restoring division
void restoringDivision(int dividend, int divisor) {
    int quotient = 0, remainder = 0;

    printf("Performing Restoring Division for %d / %d:\n\n", dividend, divisor);
    printf("Step\t Dividend\t Quotient\t Remainder\n");

    // Initializing the dividend with the first bits of the number
    for (int i = 31; i >= 0; i--) {
        remainder = (remainder << 1) | ((dividend >> i) & 1);
        printf("%d\t %d\t\t %d\t\t %d\n", 32 - i, remainder, quotient, divisor);

        // Subtract divisor from remainder
        remainder -= divisor;

        // If the result is negative, restore the previous value and set quotient bit to 0
        if (remainder < 0) {
            remainder += divisor;
            quotient = (quotient << 1) | 0;
        } else {
            quotient = (quotient << 1) | 1;
        }
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

    // Perform restoring division
    restoringDivision(dividend, divisor);

    return 0;
}

