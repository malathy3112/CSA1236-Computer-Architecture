#include <stdio.h>
#include <string.h>

// Function to convert ASCII to binary
void asciiToBinary(char asciiString[]) {
    printf("ASCII to Binary Conversion:\n");
    printf("ASCII: %s\n", asciiString);
    printf("Binary: ");

    // Iterate through each character of the ASCII string
    for (int i = 0; i < strlen(asciiString); i++) {
        // Convert each character to binary
        for (int j = 7; j >= 0; j--) {
            printf("%d", (asciiString[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

// Function to convert binary to ASCII
void binaryToAscii(char binaryString[]) {
    printf("Binary to ASCII Conversion:\n");
    printf("Binary: %s\n", binaryString);
    printf("ASCII: ");

    // Iterate through each 8-bit segment of the binary string
    for (int i = 0; i < strlen(binaryString); i += 8) {
        char asciiChar = 0;

        // Convert each 8-bit segment to ASCII
        for (int j = 0; j < 8; j++) {
            asciiChar = (asciiChar << 1) | (binaryString[i + j] - '0');
        }

        printf("%c", asciiChar);
    }
    printf("\n");
}

int main() {
    char asciiString[100];
    char binaryString[100];

    // Input ASCII string
    printf("Enter an ASCII string: ");
    scanf("%s", asciiString);

    // Input binary string
    printf("Enter a binary string: ");
    scanf("%s", binaryString);

    // Perform ASCII to binary conversion
    asciiToBinary(asciiString);

    // Perform binary to ASCII conversion
    binaryToAscii(binaryString);

    return 0;
}

