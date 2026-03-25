#include<stdio.h>

/*
 * x must equal main.  But how does main look in assembly?
 */

int main(){
	void* x;

	asm(
		"movq %[main], %[x]\n"  
		: [x] "=r" (x)         
		: [main] "r" (main)    
		:                      
		);

	if(main == x)
		printf("You solved problem 10!\n");
	else
		printf("Keep trying!\n");
}
