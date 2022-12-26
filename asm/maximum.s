# PURPOSE: This program finds the maximum number
#          of a set of data items.

# VARIABLES: The registers have the following uses:
# %edi - holds the index of the data item being examined;
# %ebx - holds the largest data item found;
# %eax - holds the current data item.

# MEMORY LOCATIONS: The following memory locations are used:
# data_items - contains the item data; a 0 is used to terminate the data.

.section .data

data_items:                      # These are the data items.
.long 3,67,34,222,45,75,54,34,44,33,22,11,66,0
buffer:
.ascii "\0\0\0\0\0\0\0\0\0\0\0"

.section .text

.globl _start

_start:
movl $0, %edi                    # Move 0 into the index register.
movl data_items(,%edi,4), %eax   # Load the first byte of data.
movl %eax, %ebx                  # Since this is the first time, %eax is the biggest.

start_loop:                      # Start the loop.
cmpl $0, %eax                    # Check to see if we have hit the end.
je end_loop
incl %edi                        # Increment the index register.
movl data_items(,%edi,4), %eax   # Load the nex value.
cmpl %ebx, %eax                  # Compare the values.
jle start_loop                   # Jumo to the loop start, if the new one is not bigger.
movl %eax, %ebx                  # Move the value as the biggest.
jmp start_loop                   # Jump to the loop start.

end_loop:
pushl $buffer
pushl %ebx                       # %ebx has the maximum number.
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

movl $0, %ebx                    # Exit status code.
movl $1, %eax                    # 1 is the exit() system call.
int $0x80
