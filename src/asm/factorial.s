# PURPOSE: This program shows how to call a function recursively.
#          It calculates the factorial of 4, which is 24.

.section .data   # This program has no global data.

.section .text

.globl _start
.globl factorial    # This is unneeded unless we want to share
                    # this function among other programs.

_start:

pushl $4          # The factorial takes one argument.
call factorial    # Run the factorial function.
addl $4, %esp     # Scrub the parameter that was pushed on the stack.
movl %eax, %ebx   # Factorial returns the answer in %eax, but we want
                  # it in %ebx to send it as our exit status.
movl $1, %eax     # Call the kernel's exit function.
int $0x80

.type factorial, @function

factorial:
pushl %ebp
movl %esp, %ebp
movl 8(%ebp), %eax   # Load the argument to %eax.
cmpl $1, %eax        # If the number is 1, return.
je end_factorial
decl %eax            # Decrease the value.
pushl %eax           # Push it for our call to factorial.
call factorial
movl 8(%ebp), %ebx   # %eax has the return value, so reload the parameter to %ebx.
imull %ebx, %eax     # Multiply that by the result of the last call to
                     # factorial (in %eax), store the answer in %eax.
end_factorial:
movl %ebp, %esp
popl %ebp
ret
