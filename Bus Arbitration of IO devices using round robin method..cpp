#include <stdio.h>

#define NUM_DEVICES 4  // Number of I/O devices
#define BUS_CYCLES 10  // Number of bus cycles

// Function to perform bus arbitration using round-robin method
void busArbitrationRoundRobin() {
    int currentDevice = 0;  // Index of the current device accessing the bus

    printf("Bus Arbitration using Round-Robin Method:\n");

    for (int cycle = 1; cycle <= BUS_CYCLES; cycle++) {
        printf("Bus Cycle %d: Device %d accesses the bus.\n", cycle, currentDevice);

        // Move to the next device for the next bus cycle (round-robin)
        currentDevice = (currentDevice + 1) % NUM_DEVICES;
    }
}

int main() {
    // Perform bus arbitration using round-robin method
    busArbitrationRoundRobin();

    return 0;
}

