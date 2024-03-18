#include <stdio.h>
#define MEMORY_SIZE 1024 // Size of ROM in bytes

// Define a structure for Read-Only Memory
struct ROM {
    unsigned char memory[MEMORY_SIZE]; // Array to simulate memory cells
};

// Function to initialize ROM
void initializeROM(struct ROM *rom, const unsigned char *data, int dataSize) {
    if (dataSize > MEMORY_SIZE) {
        printf("Error: Data size exceeds ROM size.\n");
        return;
    }
    // Copy data into ROM memory
    for (int i = 0; i < dataSize; i++) {
        rom->memory[i] = data[i];
    }
    printf("ROM Initialized.\n");
}

// Function to read data from ROM
unsigned char readFromROM(struct ROM *rom, int address) {
    if (address >= 0 && address < MEMORY_SIZE) {
        printf("Data at address %d: '%c'\n", address, rom->memory[address]);
        return rom->memory[address];
    } else {
        printf("Error: Invalid memory address.\n");
        return 0;
    }
}

int main() {
    // Define data to be stored in ROM
    const unsigned char data[] = {'R', 'E', 'A', 'D', 'O', 'N', 'L', 'Y'};

    // Create an instance of ROM
    struct ROM rom;

    // Initialize ROM with data
    initializeROM(&rom, data, sizeof(data));

    // Read data from ROM
    readFromROM(&rom, 0); // Read from address 0
    readFromROM(&rom, 4); // Read from address 4

    return 0;
}

