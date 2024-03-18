#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096 // Size of each page in bytes
#define NUM_PAGES 256   // Number of pages in the virtual memory
#define FRAME_SIZE 4096 // Size of each frame in bytes
#define NUM_FRAMES 256  // Number of frames in the physical memory

// Page table entry structure
struct PageTableEntry {
    int valid; // Valid bit to indicate whether the page is in memory
    int frame; // Physical frame number
};

// Virtual memory structure
struct VirtualMemory {
    struct PageTableEntry pageTable[NUM_PAGES]; // Page table
    char *data[NUM_PAGES];                      // Data for each page
};

// Physical memory structure
struct PhysicalMemory {
    char *frames[NUM_FRAMES]; // Frames in physical memory
};

// Function to initialize virtual memory
void initializeVirtualMemory(struct VirtualMemory *virtualMemory) {
    // Initialize page table entries
    for (int i = 0; i < NUM_PAGES; i++) {
        virtualMemory->pageTable[i].valid = 0; // Mark all pages as invalid initially
        virtualMemory->pageTable[i].frame = -1;
    }
    // Allocate memory for data of each page
    for (int i = 0; i < NUM_PAGES; i++) {
        virtualMemory->data[i] = (char *)malloc(PAGE_SIZE * sizeof(char));
    }
}

// Function to initialize physical memory
void initializePhysicalMemory(struct PhysicalMemory *physicalMemory) {
    // Allocate memory for each frame
    for (int i = 0; i < NUM_FRAMES; i++) {
        physicalMemory->frames[i] = (char *)malloc(FRAME_SIZE * sizeof(char));
    }
}

// Function to read from virtual memory
char readFromVirtualMemory(struct VirtualMemory *virtualMemory, int virtualAddress) {
    int page = virtualAddress / PAGE_SIZE;
    int offset = virtualAddress % PAGE_SIZE;

    // Check if page is valid and in memory
    if (virtualMemory->pageTable[page].valid) {
        printf("Read from Virtual Memory: Page %d is in Physical Frame %d\n", page, virtualMemory->pageTable[page].frame);
        return virtualMemory->data[page][offset];
    } else {
        printf("Error: Page %d is not in memory.\n", page);
        return '\0';
    }
}

int main() {
    // Initialize virtual memory
    struct VirtualMemory virtualMemory;
    initializeVirtualMemory(&virtualMemory);

    // Initialize physical memory
    struct PhysicalMemory physicalMemory;
    initializePhysicalMemory(&physicalMemory);

    // Simulate reading from virtual memory
    char data = readFromVirtualMemory(&virtualMemory, 8192); // Reading from virtual address 8192

    return 0;
}

