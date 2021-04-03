#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "6502.h"

using byte = unsigned char; // 8 bit type
using word = unsigned short; // 16 bit type

struct CPU {
	word PC; // Program counter
	word SP; // Stack pointer

	// CPU registers
	byte A;
	byte X;
	byte Y;

	// Status flags
	byte C : 1;
	byte Z : 1;
	byte I : 1;
	byte D : 1;
	byte B : 1;
	byte V : 1;
	byte N : 1;
};

int main()
{
	return 0;
}