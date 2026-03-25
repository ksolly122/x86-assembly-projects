.section .text
#.lcomm bug_stack, 8  # Allocate space for the bug stack

.globl print_bugs
print_bugs:
    pushq %rbp         # Save the base pointer
    movq %rsp, %rbp    # Set up the new base pointer

    movq bug_stack(%rip), %rdi  # Load the address of bug_stack into RDI *****

loop_print_bugs:
    testq %rdi, %rdi   # Check if bug_stack is NULL
    je end_print_bugs  # If bug_stack is NULL, jump to end_print_bugs

    movq (%rdi), %rsi  # Load the name pointer from the current bug_stack node into RSI
    call puts           # Call the puts function to print the name

    movq 8(%rdi), %rdi # Move to the next bug_stack node
    jmp loop_print_bugs  # Jump back to the start of the loop

end_print_bugs:
    popq %rbp          # Restore the base pointer
    ret                # Return from the function

.globl halves_to_100
halves_to_100:
    pushq %rbp
    movq %rsp, %rbp
    movq %rdi, %rax
    xorq %rcx, %rcx
    cmp $100, %rax
    jl divide_loop
    movq $100, %rcx
divide_loop:
    shrq $1, %rax
    cmp $100, %rax
    jl divide_loop
    incq %rcx
    popq %rbp
    ret

.globl return_five_returner
return_five_returner:
    leaq return_five(%rip), %rax
    ret

.globl return_five
return_five:
    movl $5, %eax
    ret

.globl space_to_underscore
space_to_underscore:
    pushq %rbp
    movq %rsp, %rbp
    movq %rdi, %rax
    jmp start_space_to_underscore
loop_space_to_underscore:
    cmpb $32, (%rax)
    jne no_replace_space
    movb $95, (%rax)
no_replace_space:
    incq %rax
start_space_to_underscore:
    cmpb $0, (%rax)
    jne loop_space_to_underscore
    popq %rbp
    ret
