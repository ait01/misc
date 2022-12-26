# PURPOSE: Count the characters until a null byte is reached.
# INPUT: Character string address.
# OUTPUT: Returns the count in %eax.

# REGISTERS: %ecx is the character count;
#            %edx is the current character address;
#            %al is the current character.

.section .text

.globl count_chars
.type count_chars, @function

.equ ST_STRING_START_ADDRESS, 8 # One parameter is on the stack.

count_chars:
pushl %ebp
movl %esp, %ebp
movl $0, %ecx # Counter starts at zero.
movl ST_STRING_START_ADDRESS(%ebp), %edx

count_loop_begin:
movb (%edx), %al # Grab the current character.
cmpb $0, %al # If it is null, we are done.
je count_loop_end
incl %ecx # Otherwise, increment the counter and the pointer.
incl %edx
jmp count_loop_begin

count_loop_end:
movl %ecx, %eax # Copy the count to %eax
popl %ebp
ret
