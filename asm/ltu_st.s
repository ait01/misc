# PURPOSE: This program reads from the standard input, converts all the
#          letters to uppercase and writes to the standard output.

# PROCESSING: 1. Read from the standard input.
#             2. While we are not at the end of the input:
#                a) read a part of the input into the memory buffer;
#                b) go through each byte of memory, if the byte is
#                   a lowercase letter, convert it to uppercase;
#                c) write the memory buffer to the standard output.

# NOTE: Not all labels are used for jumps. They are there for clarity.

.section .data

.equ SYS_OPEN, 5 # System call numbers.
.equ SYS_WRITE, 4
.equ SYS_READ, 3
.equ SYS_CLOSE, 6
.equ SYS_EXIT, 1
.equ STDIN, 0 # Standard file descriptors.
.equ STDOUT, 1
.equ STDERR, 2
.equ LINUX_SYSCALL, 0x80 # System call interrupt.
.equ END_OF_FILE, 0 # Read returns 0, when we hit the end of the file.
.equ NUMBER_ARGUMENTS, 2

.section .bss # This is the buffer, where the data is loaded into
              # from the input file and written from into the output
              # file. This should never exceed 16000 for various reasons.

.equ BUFFER_SIZE, 500
.lcomm BUFFER_DATA, BUFFER_SIZE

.section .text

.globl _start

_start:

movl %esp, %ebp # Save the stack pointer.

loop_begin:
movl $SYS_READ, %eax # Read system call.
movl $STDIN, %ebx # Standard input file descriptor goes to %ebx.
movl $BUFFER_DATA, %ecx # Buffer location to read into.
movl $BUFFER_SIZE, %edx # Buffer size to read.
int $LINUX_SYSCALL # Buffer size read is returned in %eax.
cmpl $END_OF_FILE, %eax # Check for error or end of file marker.
jle loop_end

loop_continue:
pushl $BUFFER_DATA # Buffer location.
pushl %eax # Buffer size.
call lower_to_upper
popl %eax # Get the buffer size back.
addl $4, %esp # Restore the stack pointer.
movl %eax, %edx # Buffer size to write.
movl $SYS_WRITE, %eax # Write system call.
movl $STDOUT, %ebx # Standard output file descriptor goes to %ebx.
movl $BUFFER_DATA, %ecx # Buffer location to write from.
int $LINUX_SYSCALL
jmp loop_begin

loop_end:
movl $SYS_EXIT, %eax # Exit system call.
movl $0, %ebx # Exit status.
int $LINUX_SYSCALL

# Function Definition.
# PURPOSE: This function converts letters in a block to upper case.

# INPUT: The first parameter is the location of the memory block
#        to convert. The second parameter is the length of that buffer.

# OUTPUT: This function overwrites the current buffer with the changed
#         to uppercase version.

# VARIABLES: %eax is the buffer beginning.
#            %ebx is the buffer length.
#            %edi is the current buffer offset.
#            %cl is the current byte being examined (first part of %ecx).

.equ LOWERCASE_A, 'a' # The lower boundary of our search.
.equ LOWERCASE_Z, 'z' # The upper boundary of our search.
.equ UPPER_CONVERSION, 'A'-'a' # Conversion between upper and lower case.
.equ ST_BUFFER_LEN, 8 # The buffer length.
.equ ST_BUFFER, 12 # The actual buffer.

lower_to_upper:

pushl %ebp
movl %esp, %ebp
movl ST_BUFFER(%ebp), %eax
movl ST_BUFFER_LEN(%ebp), %ebx
movl $0, %edi
cmpl $0, %ebx # If the buffer has zero length, leave.
je convert_loop_end

convert_loop_begin:
movb (%eax,%edi,1), %cl # Get the current byte.
cmpb $LOWERCASE_A, %cl # Go to the next byte, if it is not between 'a' and 'z'.
jl next_byte
cmpb $LOWERCASE_Z, %cl
jg next_byte
addb $UPPER_CONVERSION, %cl # Otherwise, convert the byte to uppercase.
movb %cl, (%eax,%edi,1) # And store it back.

next_byte:
incl %edi # The next byte.
cmpl %edi, %ebx # Continue unless we have reached the end.
jne convert_loop_begin

convert_loop_end:
movl %ebp, %esp # No return value, just leave.
popl %ebp
ret
