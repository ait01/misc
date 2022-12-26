# PURPOSE: Program to show how functions work.
#          This program calculates the value of 2^3 + 5^2 - 8^0

# Everything in the main program is stored in
# registers, so the data section has nothing.

.section .data

.section .text

.globl _start

_start:

pushl $3          # Push the second argument.
pushl $2          # Push the first argument.
call power        # Call the function.
addl $8, %esp     # Move the stack pointer back.
pushl %eax        # Save the first answer.

pushl $2          # Push the second argument.
pushl $5          # Push the first argument.
call power        # Call the function.
addl $8, %esp     # Move the stack poointer back
pushl %eax        # Save the second answer.

pushl $0          # Push the second argument.
pushl $8          # Push the first argument.
call power        # Call the function.
addl $8, %esp     # Move the stack poointer back

popl %ebx         # Pop the second answer into %ebx.
popl %ecx         # Pop the first answer into %ecx.
addl %ecx, %ebx   # Add the first and the second
                  # term, the result is in %ebx.
subl %eax, %ebx   # Subtract the third term
                  # the result is in %ebx.
movl $1, %eax     # Exit, %ebx is returned.
int $0x80

# PURPOSE: This function calculates the value of
#          a number raised to a power.

# INPUT: First argument is the base number;
#        Second argument is the exponent.

# OUTPUT: Gives the result as a return value.

# NOTE: The power must be 0 or greater.

# VARIABLES: %ebx holds the base number;
#            %ecx holds the exponent;
#            -4(%ebp) holds the current result;
#            %eax is for temporary storage.

.type power, @function

power:

pushl %ebp            # Save old base pointer.
movl %esp, %ebp       # Make stack pointer the base pointer.
subl $4, %esp         # Get room for the local storage.
movl 8(%ebp), %ebx    # Put the first argument in %ebx.
movl 12(%ebp), %ecx   # Put the second argument in %ecx.
movl %ebx, -4(%ebp)   # Store the current result.

cmpl $0, %ecx         # If the exponent is 0, return 1
je zero_exponent

power_loop_start:
cmpl $1, %ecx         # If the exponent is 1, we are done.
je power_loop_end
movl -4(%ebp), %eax   # Move the current result into %eax.
imull %ebx, %eax      # Multiply the current result by the base number.
movl %eax, -4(%ebp)   # Store the current result.
decl %ecx             # Decrease the exponent.
jmp power_loop_start  # Run for the next power.

zero_exponent:
movl $1, -4(%ebp)

power_loop_end:
movl -4(%ebp), %eax   # Return value goes in %eax.
movl %ebp, %esp       # Restore the stack pointer.
popl %ebp             # Restore the base pointer.
ret
