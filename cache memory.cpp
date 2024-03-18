#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CACHE_SIZE 16        // Cache size in number of blocks
#define BLOCK_SIZE 4         // Block size in bytes
#define MAIN_MEMORY_SIZE 64  // Main memory size in bytes

// Cache block structure
struct CacheBlock {
    int tag;
    unsigned char data[BLOCK_SIZE];
    bool valid;
};

// Function to initialize cache
void initializeCache(struct CacheBlock cache[]) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].tag = -1;  // Initialize tag to an invalid value
        cache[i].valid = false;  // Initialize valid bit to false
    }
    printf("Cache Initialized.\n");
}

// Function to simulate cache read operation
unsigned char cacheRead(struct CacheBlock cache[], int address) {
    int blockIndex = address / BLOCK_SIZE;
    int tag = address / CACHE_SIZE;

    if (cache[blockIndex].valid && cache[blockIndex].tag == tag) {
        printf("Cache Hit: Block %d\n", blockIndex);
        return cache[blockIndex].data[address % BLOCK_SIZE];
    } else {
        printf("Cache Miss: Block %d\n", blockIndex);
        // Read block from main memory and update cache
        cache[blockIndex].tag = tag;
        cache[blockIndex].valid = true;
        // Simulated read operation from main memory
        printf("Read from main memory.\n");
        return rand() % 256;  // Return random data for simulation
    }
}

int main() {
    struct CacheBlock cache[CACHE_SIZE];

    // Initialize cache
    initializeCache(cache);

    // Simulate cache read operations
    printf("Reading data from cache:\n");
    for (int i = 0; i < MAIN_MEMORY_SIZE; i++) {
        unsigned char data = cacheRead(cache, i);
        printf("Data at address %d: %u\n", i, data);
    }

    return 0;
}

