#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024 // Size of RAM in bytes

// Define a structure for Random Access Memory
struct RAM {
    unsigned char memory[MEMORY_SIZE]; // Array to simulate memory cells
};

// Function to initialize RAM
void initializeRAM(struct RAM *ram) {
    // Initialize all memory cells to 0
    for (int i = 0; i < MEMORY_SIZE; i++) {
        ram->memory[i] = 0;
    }
    printf("RAM Initialized.\n");
}

// Function to write data to RAM
void writeToRAM(struct RAM *ram, int address, unsigned char data) {
    if (address >= 0 && address < MEMORY_SIZE) {
        ram->memory[address] = data;
        printf("Data '%c' written to address %d.\n", data, address);
    } else {
        printf("Error: Invalid memory address.\n");
    }
}

// Function to read data from RAM
unsigned char readFromRAM(struct RAM *ram, int address) {
    if (address >= 0 && address < MEMORY_SIZE) {
        printf("Data at address %d: '%c'\n", address, ram->memory[address]);
        return ram->memory[address];
    } else {
        printf("Error: Invalid memory address.\n");
        return 0;
    }
}

int main() {
    // Create an instance of RAM
    struct RAM ram;

    // Initialize RAM
    initializeRAM(&ram);

    // Write data to RAM
    writeToRAM(&ram, 100, 'A');
    writeToRAM(&ram, 200, 'B');

    // Read data from RAM
    readFromRAM(&ram, 100);
    readFromRAM(&ram, 200);

    return 0;
}

