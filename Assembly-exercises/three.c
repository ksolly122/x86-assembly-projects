#include <stdio.h>
#include <unistd.h> // contains sleep
#include <time.h>

/* 
 * This time, your assembly code is timed! It must take longer than 10 seconds.
 */

int main() {
    time_t start_time = time(0);

    asm(
        "movl $0, %eax\n\t"    // Move 0 into the EAX register
        "movl $0, %ebx\n\t"    
        "movl $1000000000, %ecx\n" // Move a large value into ECX for loop iteration
        "loop_start:\n\t"
        "addl $1, %eax\n\t"    // Increment EAX by 1
        "addl $1, %ebx\n\t"    
        "loop loop_start\n"    // Loop back to loop_start label
    );

    time_t end_time = time(0);
    if (end_time - start_time > 10)
        printf("You finished problem three!\n");
    else
        printf("Keep trying!\n");

    return 0;
}
