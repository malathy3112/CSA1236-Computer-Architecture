#include <stdio.h>

// Function to simulate structural hazard
void structuralHazard() {
    printf("Structural Hazard Detected: Two instructions require the same hardware resource simultaneously.\n");
}

// Function to simulate data hazard (dependency)
void dataHazard() {
    printf("Data Hazard Detected: Instruction depends on a previous instruction's result.\n");
}

// Function to simulate control hazard (branch)
void controlHazard() {
    printf("Control Hazard Detected: Branch instruction changes the program flow.\n");
}

int main() {
    int option;

    printf("Identify Different Hazards:\n");
    printf("1. Structural Hazard\n");
    printf("2. Data Hazard\n");
    printf("3. Control Hazard\n");
    printf("Choose an option (1-3): ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            structuralHazard();
            break;
        case 2:
            dataHazard();
            break;
        case 3:
            controlHazard();
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}

