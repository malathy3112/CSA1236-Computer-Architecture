#include <stdio.h>

int main() {
    int a, b, choice, res;
    int fetchCycles = 1;
    int executeCycles = 1;
    
    // Fetch Stage
    printf("Enter number 1:");
    scanf("%d", &a);
    printf("Enter number 2:");
    scanf("%d", &b);

    // Execution Stage
    printf("1-Addition:\n2-Subtraction:\n3-Multiplication:\n4-Division:");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Performing addition\n");
            res = a + b;
            break;
        case 2:
            printf("Performing subtraction\n");
            res = a - b;
            break;
        case 3:
            printf("Performing Multiplication\n");
            res = a * b;
            break;
        case 4:
            printf("Performing Division\n");
            res = a / b;
            break;
        default:
            printf("Wrong input");
            return 1;
    }

    printf("Result: %d\n", res);
    printf("Total Cycles: %d\n", fetchCycles + executeCycles);
    return 0;
}
