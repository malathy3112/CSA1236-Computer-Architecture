#include <stdio.h>

// Union to access the same memory location as a double or an unsigned long long
union DoubleConverter {
    double doubleValue;
    unsigned long long intValue;
};

// Function to print the binary representation of a double
void printDoubleBinary(double d) {
    union DoubleConverter converter;
    converter.doubleValue = d;

    printf("Binary representation of %.2lf:\n", d);

    // Extracting the bits of the double and printing them
    for (int i = 63; i >= 0; i--) {
        printf("%d", (converter.intValue >> i) & 1);
        if (i == 63 || i == 52) printf(" ");
    }
    printf("\n");
}

int main() {
    double number;

    // Input the double-precision number
    printf("Enter a double-precision number: ");
    scanf("%lf", &number);

    // Print the binary representation of the input number
    printDoubleBinary(number);

    return 0;
}

