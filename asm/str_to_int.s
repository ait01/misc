# PURPOSE: Convert a decimal string into an integer.

# INPUT: The location of the memory buffer with the string to convert.
#        The length of that buffer.

# OUTPUT: The converted integer is returned in %eax.

# REGISTERS: %eax is the integer being built up.
#            %ebx is the buffer beginning.
#            %ecx is the current digit being converted.
#            %edi is the current buffer offset.
#            %edx is the current power of ten.
#            %cl is the current byte being examined (first part of %ecx).

.globl str2int
.type str2int, @function

str2int:
pushl %ebp
movl %esp, %ebp
movl 8(%ebp), %ebx
movl $0, %edi
movl $0, %eax # Initialize %eax.
cmpl $0, 12(%ebp) # If the buffer has zero length, leave.
je loop_end

loop_begin: # TODO: try this instead: n = 10 * n + (c - '0') starting with n = 0.
movb (%ebx,%edi,1), %cl
subl $'0', %ecx
incl %edi
movl 12(%ebp), %edx
subl %edi, %edx
cmpl $0, %edx
je decimal_power_loop_end

decimal_power_loop_begin:
imull $10, %ecx
decl %edx
cmpl $0, %edx
je decimal_power_loop_end
jmp decimal_power_loop_begin

decimal_power_loop_end:
addl %ecx, %eax
cmpl %edi, 12(%ebp) # Continue unless we have reached the end.
jne loop_begin

loop_end:
movl %ebp, %esp
popl %ebp
ret
