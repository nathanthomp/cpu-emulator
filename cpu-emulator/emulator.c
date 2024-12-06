#include <stdio.h>
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