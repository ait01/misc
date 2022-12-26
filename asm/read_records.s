.include "linux.s"
.include "record_def.s"

.section .data
file_name:
.ascii "test.dat\0"

#.section .bss
#.lcomm record_buffer, RECORD_SIZE

record_buffer_ptr:
.long 0

.section .text
.globl _start

_start:
.equ ST_INPUT_DESCRIPTOR, -4
.equ ST_OUTPUT_DESCRIPTOR, -8
movl %esp, %ebp
subl $8, %esp # Allocate space for the file descriptors.
call allocate_init
pushl $RECORD_SIZE
call allocate
movl %eax, record_buffer_ptr
movl $SYS_OPEN, %eax # Open the file.
movl $file_name, %ebx
movl $0, %ecx # Open read only.
movl $0666, %edx
int $LINUX_SYSCALL
movl %eax, ST_INPUT_DESCRIPTOR(%ebp) # Save the file descriptor.
movl $STDOUT, ST_OUTPUT_DESCRIPTOR(%ebp)

read_loop_begin:
pushl ST_INPUT_DESCRIPTOR(%ebp)
#pushl $record_buffer
pushl record_buffer_ptr
call read_record # Returns the number of bytes read in %eax.
addl $8, %esp # Restore the stack pointer.
cmpl $RECORD_SIZE, %eax # If it is not the same number we requested,
jne read_loop_end       # then it is either the end of file or an error.
#pushl $RECORD_FIRSTNAME + record_buffer
movl record_buffer_ptr, %eax
addl $RECORD_FIRSTNAME, %eax
pushl %eax
call count_chars # Count the size of the first name.
addl $4, %esp
movl %eax, %edx
movl ST_OUTPUT_DESCRIPTOR(%ebp), %ebx
movl $SYS_WRITE, %eax
#movl $RECORD_FIRSTNAME + record_buffer, %ecx
movl record_buffer_ptr, %ecx
addl $RECORD_FIRSTNAME, %ecx
int $LINUX_SYSCALL
pushl ST_OUTPUT_DESCRIPTOR(%ebp)
call write_newline
addl $4, %esp
jmp read_loop_begin

read_loop_end:
pushl record_buffer_ptr
call deallocate
movl $SYS_EXIT, %eax
movl $0, %ebx
int $LINUX_SYSCALL
