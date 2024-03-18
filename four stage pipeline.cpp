#include <stdio.h>

// Define instruction types
#define R_TYPE 0
#define I_TYPE 1
#define J_TYPE 2

// Define instruction structure
struct Instruction {
    int type;
    int opcode;
    int rs, rt, rd;
    int immediate;
};

// Function to simulate instruction fetch stage
void instructionFetch() {
    printf("Instruction Fetch (IF) Stage\n");
    // Fetch instruction from memory and increment PC
}

// Function to simulate instruction decode stage
void instructionDecode(struct Instruction instr) {
    printf("Instruction Decode (ID) Stage\n");
    // Decode instruction and read registers
}

// Function to simulate execute stage
void execute(struct Instruction instr) {
    printf("Execute (EX) Stage\n");
    // Perform ALU operation or calculate memory address
}

// Function to simulate write back stage
void writeBack(struct Instruction instr) {
    printf("Write Back (WB) Stage\n");
    // Write result to register file or memory
}

int main() {
    // Simulated instructions
    struct Instruction instructions[] = {
        {R_TYPE, 0x20, 1, 2, 3, 0},  // Example R-type instruction (add)
        {I_TYPE, 0x23, 1, 2, 0, 100},  // Example I-type instruction (load)
        {J_TYPE, 0x02, 0, 0, 0, 0}  // Example J-type instruction (jump)
    };

    // Simulate pipelined execution for each instruction
    for (int i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++) {
        printf("\nExecuting Instruction %d\n", i + 1);
        instructionFetch();
        instructionDecode(instructions[i]);
        execute(instructions[i]);
        writeBack(instructions[i]);
    }

    return 0;
}

