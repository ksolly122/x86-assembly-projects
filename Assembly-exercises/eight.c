#include<stdio.h>

/* 
 * This won't print anything at all when you start.
 * Call foo with a parameter of 172 to win!
 */

void foo(unsigned long int x){
    if(x == 172)
        printf("You finished problem eight!\n");
    else
        printf("Keep trying!\n");    
}

int main(){
    unsigned long int param = 172;

    asm volatile(
        "pushq $172\n"   // Push the value 172 onto the stack
        "call foo\n"     // Call the foo function
        "addq $8, %%rsp\n" // Clean up the stack after the function call
        :
        :
        : "memory", "cc"
    );

    return 0;
}
