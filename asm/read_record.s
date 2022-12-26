# PURPOSE: This function reads a record from the file descriptor.
# INPUT: The file descriptor and a buffer.
# OUTPUT: It reads the data to the buffer and returns a status code.
# NOTE: %eax has the return value, which is given back to the caller.

.include "linux.s"
.include "record_def.s"

.equ ST_READ_BUFFER, 8
.equ ST_FILEDES, 12

.section .text

.globl read_record
.type read_record, @function

read_record:
pushl %ebp
movl %esp, %ebp
pushl %ebx
movl $SYS_READ, %eax
movl ST_FILEDES(%ebp), %ebx
movl ST_READ_BUFFER(%ebp), %ecx
movl $RECORD_SIZE, %edx
int $LINUX_SYSCALL
popl %ebx
movl %ebp, %esp
popl %ebp
ret
