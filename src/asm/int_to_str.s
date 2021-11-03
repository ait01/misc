# PURPOSE: Convert an integer to a decimal string.

# INPUT: An integer to convert to string.
#        A buffer large enough to hold the largest possible number.

# OUTPUT: The buffer is overwritten with the decimal string.

# REGISTERS: %eax is the current value;
#            %ecx is the count of the characters processed;
#            %edi is the base (10).

.equ ST_VALUE, 8
.equ ST_BUFFER, 12

.globl int2str
.type int2str, @function

int2str:
pushl %ebp
movl %esp, %ebp
movl $0, %ecx # The current character count.
movl ST_VALUE(%ebp), %eax # Move the value into position.
movl $10, %edi # The divisor must be in a register or memory location.

convert_loop_begin:
movl $0, %edx # Division is actually done on the combined %eax:%edx register,
              # so first clear out %edx.
divl %edi # Divide %eax:%edx by 10. The quotient is in %eax and the remainder is in %edx.
addl $'0', %edx # Get the ASCII code for the remainder.
pushl %edx # Push the whole register on the stack,
           # though we only need the byte in %dl (the last byte of %edx).
incl %ecx # Increment the digit count.
cmpl $0, %eax # Check to see if %eax is zero yet.
je convert_loop_end
jmp convert_loop_begin # %eax already has its new value.

convert_loop_end:
movl ST_BUFFER(%ebp), %edx # Get the pointer to the buffer in %edx.

copy_reverse_loop_begin:
popl %eax # We pushed a whole register, so pop off to the entire %eax register.
movb %al, (%edx) # But then only move the part (%al) in to the character string.
decl %ecx # Decrease the digit count so we know when we are finished.
incl %edx # Increase %edx so that it points to the next byte.
cmpl $0, %ecx # Check to see if we are finished.
je copy_reverse_loop_end
jmp copy_reverse_loop_begin

copy_reverse_loop_end:
movb $0, (%edx) # Write the null byte to the buffer.
movl %ebp, %esp
popl %ebp
ret
