#include <stdio.h>

int main() {
    int low = 0;

    asm(
        "movl $0xFFFFFFFF, %0\n" // Move 0xFFFFFFFF into the low variable
        : "=r" (low)             // Output constraint for low
        :                         
        :                         
    );

    if (low < 0xFFFFFFFF) {
        printf("Keep Trying!\n");
        return 0;
    }

    printf("You finished problem six!\n");
    return 0;
}
