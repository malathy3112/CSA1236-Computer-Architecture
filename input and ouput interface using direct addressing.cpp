#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MEMORY_SIZE 4096  // Size of memory region to be accessed via DMA

int main() {
    int fd;
    char *dmaBuffer;

    // Open a file descriptor for memory device (e.g., /dev/mem)
    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("Unable to open /dev/mem");
        exit(EXIT_FAILURE);
    }

    // Map the memory region to be accessed via DMA into user space
    dmaBuffer = (char *)mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (dmaBuffer == MAP_FAILED) {
        perror("mmap failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Simulate DMA input: read data from DMA buffer
    printf("DMA Input: Reading data from DMA buffer...\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        printf("%c", dmaBuffer[i]);  // Access data from DMA buffer
    }
    printf("\n");

    // Simulate DMA output: write data to DMA buffer
    printf("DMA Output: Writing data to DMA buffer...\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        dmaBuffer[i] = 'A' + i % 26;  // Write data to DMA buffer
    }
    printf("Data written to DMA buffer.\n");

    // Unmap the memory region and close the file descriptor
    if (munmap(dmaBuffer, MEMORY_SIZE) == -1) {
        perror("munmap failed");
    }
    close(fd);

    return 0;
}

