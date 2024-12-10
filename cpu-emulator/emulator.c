#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// Memory
// Storage: stores uint16 values in addresses 0-65535 or 0x0000-0xFFFF (65 kilobytes)
// Operations: write a value to a memory address, read a value from a memory address
// Asserts: memory addresses are bound to 0-65535 or 0x0000-0xFFFF, memory values have to be defined
// Fuctions: allocation

#define MEMORY_MAX UINT16_MAX

typedef uint16_t memory_addr;
typedef uint16_t memory_data;

memory_data memory[MEMORY_MAX];

void memory_init() {
	memory_data init_val = 0;

	for (uint16_t i = 0; i < MEMORY_MAX; i++) {
		memory_addr cur_addr = i;
		memory[cur_addr] = init_val;
	}

	printf("Memory Initialized.\n");
}

void memory_write(memory_addr addr, memory_data data) {
	assert(addr < MEMORY_MAX);
	memory[addr] = data;
}

memory_data memory_read(memory_addr addr) {
	assert(addr < MEMORY_MAX);
	return memory[addr];
}

// Instructions
// Function: each instruction is a task that the cpu knows how to execute
// Definition: an instruction contains a 4 bit number as the opcode and 12 bits for parameters
// Opcodes: values 0-15 (4 bits wide)

typedef struct {
	uint16_t opcode : 4;
	uint16_t parameters : 12;
} instruction;


// TODO: 


enum {
						// Memory I/O - <opcode> <reg> <value/address>
	OPCODE_LOAD,		// Operation to load data into a register from memory
	OPCODE_SAVE,		// Operation to save data into memory from register

						// Arithmetic - <opcode> <reg> <reg> <reg/store>
	OPCODE_ADD,			// Operation to add two values together
	OPCODE_SUB,			// Operation to subtract two values together
	OPCODE_MUL,			// Operation to multiply two values together
	OPCODE_DIV,			// Operation to divide two values together
	 
						// End - opcode
	OPCODE_HALT			// Operation to stop execution
};

// Takes in opcode
instruction instruction_init() {

}

// Takes instruction, returns binary
uint16_t instruction_encode(instruction instr) {

}

// Takes binary, returns instruction
instruction instruction_decode(uint16_t binary) {

}

// Registers
// Function: stores temporary and neccisary data to use in computation
// Organization: three general purpose registers (A, B, C) with values 0-3

typedef uint16_t register_val;

enum registers {
	REGISTER_A,
	REGISTER_B,
	REGISTER_C,
	REGISTER_COUNT
};


// CPU
// Organization: contains registers, flags
// Operations: fetch an intstruction from memory, execute that 

struct {
	// General purpose registers A, B, and C
	register_val registers[REGISTER_COUNT];

	// Flags
	// Function: provides information about the most recent calculation
	// Organization: a flag should be a 4 bit number
	bool flag_positive, flag_zero, flag_negative;

	// Program counter
	// Function: points to the next instruction to execute
	memory_addr program_counter;

	// Stack pointer??
} cpu;

void cpu_init() {
	cpu.registers[REGISTER_A] = cpu.registers[REGISTER_B] = cpu.registers[REGISTER_C] = 0;

	cpu.program_counter = 0;

	cpu.flag_positive = cpu.flag_negative = false;
	cpu.flag_zero = true;

	printf("CPU Initialized.\n");
}

void cpu_fetch() {
	// Get instruction or data from memory, decode the instruction
}

void cpu_execute() {
	// Execute instruction
}

int main() {

	// Initialize the cpu and memory
	cpu_init();
	memory_init();

	// Load program into memory
	register_val reg_a = cpu.registers[REGISTER_A];

	// Create and run program
	instruction program[5];

	program[0] = { OPCODE_LOAD, REGISTER_A, 6 };
	program[1] = { OPCODE_LOAD, REGISTER_B, 4 };
	program[2] = { OPCODE_ADD, REGISTER_A, REGISTER_B, REGISTER_C };
	program[3] = { OPCODE_SAVE, REGISTER_C, 0xF}
	program[4] = { OPCODE_HALT };

	{ // Psuedo code for an example program
		// load 6 into reg a
		// LOAD RA 6
		// load 4 into reg b
		// LOAD RB 4
		// add reg a and reg b, storing in reg c
		// ADD RA RB RC
		// save reg c to memory address 15
		// SAVE RC 0xF
		// end
		// HALT
	}

	/*	
	memory_addr addr = 1;
	memory_data data = 3;

	memory_init();
	memory_write(addr, data);
	memory_data read_data = memory_read(addr);
	*/




	return 0;
}