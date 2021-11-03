# PURPOSE: This program reads an integer from the standard input,
#          adds 3 to it and writes the result to the standard output.

.section .bss
.lcomm buffer, 50

.section .text

.globl _start

_start:

movl %esp, %ebp # Save the stack pointer.

begin:
movl $3, %eax # Read system call.
movl $0, %ebx # Standard input file descriptor goes to %ebx.
movl $buffer, %ecx # Buffer location to read into.
movl $50, %edx # Buffer size to read.
int $0x80 # Buffer size read is returned in %eax.
cmpl $0, %eax # Check for error or end of file marker.
jle end
pushl %eax # Buffer size.
pushl $buffer # Buffer location.
call str2int
addl $8, %esp # Restore the stack pointer.
addl $3, %eax
pushl $buffer
pushl %eax
call int2str
addl $8, %esp
pushl $buffer
call count_chars
addl $4, %esp
movl %eax, %edx
movl $4, %eax
movl $1, %ebx
movl $buffer, %ecx
int $0x80
pushl $1
call write_newline

end:
movl $0, %ebx
movl $1, %eax
int $0x80
