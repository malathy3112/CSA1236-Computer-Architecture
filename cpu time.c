#include <stdio.h>
#include <time.h>

int main() {
    int iterations = 1000000; // Number of iterations for the loop
    clock_t start, end;
    double cpu_time_used;

    // Start the timer
    start = clock();

    // Perform some CPU-intensive operation (in this case, just a loop)
    for (int i = 0; i < iterations; i++) {
        // Do some computation here
    }

    // Stop the timer
    end = clock();

    // Calculate the CPU time used
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the CPU performance
    printf("CPU Performance: %.6f seconds\n", cpu_time_used);

    return 0;
}

