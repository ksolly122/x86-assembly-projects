#include<stdio.h>
#include<string.h>

/*
 * This integer is a word!
 * char*, the memory address of a character, is used for strings in C
 */

int main(){
    int word = 0;

    asm(
        "movl $0x676f66, %0\n"  // Move the ASCII values of 'f', 'o', and 'g' into the word variable
        : "=r" (word)           // Output constraint for word
        :                        
        :                        
    );

    if(!strcmp((char*)&word, "fog"))
        printf("%s is the magic word, you finished problem seven!\n", (char*)&word);
    else
        printf("%s is not the magic word.  Keep trying!\n", (char*)&word);

    return 0;
}
