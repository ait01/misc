.include "linux.s"
.include "record_def.s"

.section .data
input_file_name:
.ascii "test.dat\0"
output_file_name:
.ascii "testout.dat\0"

.section .bss
.lcomm record_buffer, RECORD_SIZE

.section .text
.globl _start

_start:
.equ ST_INPUT_DESCRIPTOR, -4
.equ ST_OUTPUT_DESCRIPTOR, -8
movl %esp, %ebp
subl $8, %esp # Allocate space for the file descriptors.
movl $SYS_OPEN, %eax # Open the input file.
movl $input_file_name, %ebx
movl $0, %ecx
movl $0666, %edx
int $LINUX_SYSCALL
movl %eax, ST_INPUT_DESCRIPTOR(%ebp) # Save the input file descriptor.

cmpl $0, %eax # Check for error.
jge continue_processing

.section .data
no_open_file_code:
.ascii "0001: \0"
no_open_file_msg:
.ascii "Cannot Open Input File\0"

.section .text
pushl $no_open_file_msg
pushl $no_open_file_code
call error_exit

continue_processing:

movl $SYS_OPEN, %eax # Open the output file.
movl $output_file_name, %ebx
movl $0101, %ecx
movl $0666, %edx
int $LINUX_SYSCALL
movl %eax, ST_OUTPUT_DESCRIPTOR(%ebp) # Save the output file descriptor.

loop_begin:
pushl ST_INPUT_DESCRIPTOR(%ebp)
pushl $record_buffer
call read_record # Returns the number of bytes read in %eax.
addl $8, %esp # Restore the stack pointer.
cmpl $RECORD_SIZE, %eax # If it is not the same number we requested,
jne loop_end            # then it is either the end of file or an error.
incl record_buffer + RECORD_AGE # Increment the age.
pushl ST_OUTPUT_DESCRIPTOR(%ebp)
pushl $record_buffer
call write_record
addl $8, %esp
jmp loop_begin

loop_end:
movl $SYS_EXIT, %eax
movl $0, %ebx
int $LINUX_SYSCALL
