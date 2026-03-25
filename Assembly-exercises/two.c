#include<stdio.h>

/*
 * Make calc_value return the square of its parameter.
 * You can figure out how to use "mul", or write a loop and use addition.
 */

volatile int calc_value(int a){
	int c;

	asm(
		"movl %1, %%eax\n\t"    // Move the value of a into EAX
		"mul %%eax\n\t"         // Multiply EAX by itself (square)
		"movl %%eax, %0\n\t"    // Move the result back to c
		: "=r" (c)              // Output operand
		: "r" (a)               // Input operand
		: "%eax"                // Clobbered register
	);

	return c;
}

int main(){
	if(calc_value(5) == 25 && calc_value(12) == 144)
		printf("You finished problem two!\n");
	else
		printf("Keep trying!\n");
	return 0;
}
