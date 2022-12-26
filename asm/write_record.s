# PURPOSE: This function writes a record to the file descriptor.
# INPUT: The file descriptor and a buffer.
# OUTPUT: It writes the data from the buffer and returns a status code.
# NOTE: %eax has the return value, which is given back to the caller.

.include "linux.s"
.include "record_def.s"

.equ ST_WRITE_BUFFER, 8
.equ ST_FILEDES, 12

.section .text

.globl write_record
.type write_record, @function

write_record:
pushl %ebp
movl %esp, %ebp
pushl %ebx
movl $SYS_WRITE, %eax
movl ST_FILEDES(%ebp), %ebx
movl ST_WRITE_BUFFER(%ebp), %ecx
movl $RECORD_SIZE, %edx
int $LINUX_SYSCALL
popl %ebx
movl %ebp, %esp
popl %ebp
ret
