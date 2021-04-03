#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "6502.h"

using byte = unsigned char; // 8bit type
using word = unsigned short; // 16bit type
using uint32 = unsigned int; // 32bit type

struct RAM {
	// Area to store our CPU information
	byte data[MAX_RAM_LEN];

	void mem_init() {
		uint32 i;
		for (i = 0; i < MAX_RAM_LEN; i++) {
			data[i] = 0;
		}
	}
};

struct CPU {
	word PC; // Program counter
	word SP; // Stack pointer

	// CPU registers
	byte A;
	byte X;
	byte Y;

	// Status flags
	byte C : 1; // Carry flag
	byte Z : 1; // Zero flag
	byte I : 1; // Interrupt disable
	byte D : 1; // Decimal mode flag
	byte B : 1; // Break command
	byte V : 1; // Overflow flag
	byte N : 1; // Negitive flag


	// CPU functions
	void reset( RAM& memory ) {
		// Reset program counter and stack pointer
		PC = RESET_VECT;
		SP = SP_RESET;

		// Reset status flags
		C = 0;
		Z = 0;
		I = 0;
		D = 0;
		B = 0;
		V = 0;
		N = 0;

		// Clear registers
		A = 0;
		X = 0;
		Y = 0;

		// Initialize RAM
		memory.mem_init();
	}

	void grab(uint32 cycles, RAM& memory) {

	}

	void exec( uint32 cycles, RAM& memory ) {
		while (cycles > 0) {
			byte ins = grab(cycles, memory);
		}
	}
};

int main()
{
	CPU cpu;
	RAM ram;

	// Simulate a poweron/reset
	cpu.reset( ram );

	// Execute instruction in memory
	cpu.exec(mem);

	return 0;
}