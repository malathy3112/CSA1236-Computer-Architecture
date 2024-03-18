#include <stdio.h>

// Function to perform Booth's algorithm for multiplication
int boothMultiplication(int multiplicand, int multiplier) {
    int product = 0;
    int accumulator = 0;
    int m = multiplicand;
    int q = multiplier;
    int count = sizeof(int) * 8; // Number of bits in an integer

    // Extend the sign bit for negative numbers
    if ((m >> (count - 1)) & 1) {
        m |= (-1 << (count - 1));
    }
    if ((q >> (count - 1)) & 1) {
        q |= (-1 << (count - 1));
    }

    printf("Performing Booth's Multiplication for %d * %d:\n\n", m, q);

    for (int i = 0; i < count; i++) {
        if ((q & 1) == 1 && (accumulator & 1) == 0) {
            accumulator += m;
            printf("Add M: %d\n", m);
        } else if ((q & 1) == 0 && (accumulator & 1) == 1) {
            accumulator -= m;
            printf("Subtract M: %d\n", m);
        }

        if ((accumulator & 1) == 0 && (accumulator & 2) == 2) {
            accumulator >>= 1;
            printf("Shift Right\n");
        } else if ((accumulator & 1) == 1 && (accumulator & 2) == 0) {
            accumulator += q << count;
            printf("Shift Left\n");
        } else {
            printf("No Shift\n");
        }

        q >>= 1;
        printf("Accumulator: %d\n", accumulator);
        printf("Multiplier: %d\n\n", q);
    }

    product = accumulator;

    return product;
}

int main() {
    int multiplicand, multiplier;

    // Input the multiplicand and multiplier
    printf("Enter multiplicand: ");
    scanf("%d", &multiplicand);
    printf("Enter multiplier: ");
    scanf("%d", &multiplier);

    // Perform Booth's multiplication
    int product = boothMultiplication(multiplicand, multiplier);

    printf("Product: %d\n", product);

    return 0;
}

