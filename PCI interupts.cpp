#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function for handling interrupts
void interruptHandler(int signal) {
    printf("Interrupt received. Handling interrupt...\n");
    // Perform interrupt handling tasks here
    printf("Interrupt handled.\n");
}

int main() {
    // Install signal handler for SIGINT (interrupt signal)
    if (signal(SIGINT, interruptHandler) == SIG_ERR) {
        perror("Unable to install signal handler");
        exit(EXIT_FAILURE);
    }

    // Simulate program execution
    printf("Program running. Press Ctrl+C to generate interrupt.\n");
    while (1) {
        // Simulate program tasks
        sleep(1); // Simulate a task that takes 1 second
    }

    return 0;
}

