#include<stdio.h>
#include<unistd.h>
#include<time.h>

/*
 * This time, your assembly code must be faster than fast!
 * But there are always other ways to win.  Remember, your assembly
 * code can change any variable in the program.
 */

int main(){
	time_t start_time = time(0);

	int flag = 0; // Flag to check if the assembly code finishes early

	asm(
		"movl $1, %0\n\t" // Set flag to 1 to indicate early completion
		: "=r" (flag) // Output operand constraint
		: 
		: "memory" 
	);

	time_t end_time = time(0);
	if(flag == 1){
		printf("You finished problem four!\n");
	} else {
		printf("Keep Trying!\n");
	}

	return 0;
}
