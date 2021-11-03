# PURPOSE: This program manages memory use.
#          It allocates and deallocates memory as requested.

# NOTE: A program using these routines asks for a certain amount of memory.
#       We actually use more than that size, but we put it in the beginning,
#       before the pointer we hand back. We add a "Size" field and
#       an "Available/Unavailable" marker. So, the memory looks like this:
#  _______________________________________________________________
# |                       |             |                         |
# | Available/Unavailable | Memory Size | Actual Memory Locations |
# |_______________________|_____________|_________________________|
#                                        ^
#                                        |
#                            The returned pointer points here
#
# The returned pointer only points to the actual locations requested,
# to make it easier for the caller. It also allows changing the structure
# without the calling program having to change at all.

.section .data

heap_begin:
.long 0 # This points to the beginning of the managed memory.
current_break:
.long 0 # This points to one location past the managed memory.

.equ HEADER_SIZE, 8 # Size of the memory region header.
.equ HDR_AVAIL_OFFSET, 0 # The "Available/Unavailable" flag location in the header.
.equ HDR_SIZE_OFFSET, 4 # The "Size" field location in the header.
.equ UNAVAILABLE, 0 # Mark the space given out.
.equ AVAILABLE, 1 # Mark the space ready for giving.
.equ SYS_BRK, 45 # Break system call number.
.equ LINUX_SYSCALL, 0x80 # System call interrupt.

.section .text

# =============== #
# || FUNCTIONS || #
# =============== #

# ----------------- #
# | allocate_init | #
# ----------------- #

# PURPOSE: This function initializes the memory manager. It sets "heap_begin"
#          and "current_break". It has no parameters and no return value.

.globl allocate_init
.type allocate_init, @function

allocate_init:
pushl %ebp
movl %esp, %ebp
movl $SYS_BRK, %eax # Find out where the break is.
movl $0, %ebx
int $LINUX_SYSCALL
incl %eax # We want the memory location after the last valid address.
movl %eax, current_break # Store the current break.
movl %eax, heap_begin # Store the current break as our first address.
movl %ebp, %esp
popl %ebp
ret

# ------------ #
# | allocate | #
# ------------ #

# PURPOSE: This function grabs a section of memory. It checks to see if there
#          are any free blocks and, if not, asks Linux for a new one.

# PARAMETERS: This function has one parameter - the size of the memory block
#             we want to allocate.

# RETURN VALUE: This function returns the address of the allocated memory in %eax.
#               If there is no memory available, it returns 0 in %eax.

# REGISTERS: %eax is the current memory region being examined;
#            %ebx is the current break position;
#            %ecx is the size of the requested memory (the only parameter);
#            %edx is the size of the current memory region.

# NOTE: The function examines each memory region starting with "heap_begin".
#       It looks at its size and if it is available. If it is OK, it grabs that one.
#       If it does not find a region large enough, it asks Linux for more memory.
#       In that case, it moves "current_break" up.

.globl allocate
.type allocate, @function
.equ ST_MEM_SIZE, 8 # Stack position of the memory size to allocate.

allocate:
pushl %ebp
movl %esp, %ebp
movl ST_MEM_SIZE(%ebp), %ecx # The requested memory size, which is the only parameter.
movl heap_begin, %eax # The current search location.
movl current_break, %ebx # The current break.

loop_begin: # Iterate through each memory region.
cmpl %ebx, %eax # Need more memory, if these are equal.
je move_break
movl HDR_SIZE_OFFSET(%eax), %edx # Grab the size of this memory.
cmpl $UNAVAILABLE, HDR_AVAIL_OFFSET(%eax) # If the space is unavailable,
je next_location                          # go to the next.
cmpl %edx, %ecx # If it is big enough, allocate here.
jle allocate_here

next_location:
addl $HEADER_SIZE, %eax # Adding the header size and the current memory region size
addl %edx, %eax         # to the current location gets the next memory region address.
jmp loop_begin # Now examine the next location.

allocate_here:
movl $UNAVAILABLE, HDR_AVAIL_OFFSET(%eax) # Mark the space as unavailable.
addl $HEADER_SIZE, %eax # Move the returned pointer past the header to the usable memory.
movl %ebp, %esp
popl %ebp
ret

move_break:
addl $HEADER_SIZE, %ebx # Adding the header size and the requested memory size
addl %ecx, %ebx         # to the current break moves its position to where we need.
pushl %eax # Save the needed registers.
pushl %ecx
pushl %ebx
movl $SYS_BRK, %eax # Reset the break, %ebx has the requested break point.
int $LINUX_SYSCALL # The new break is returned in %eax.
cmpl $0, %eax # Check for error conditions.
je error
popl %ebx # Restore the saved registers.
popl %ecx
popl %eax
movl $UNAVAILABLE, HDR_AVAIL_OFFSET(%eax) # Set this memory as unavailable.
movl %ecx, HDR_SIZE_OFFSET(%eax) # Set the size of the memory.
addl $HEADER_SIZE, %eax # Move the returned pointer to the start of usable memory.
movl %ebx, current_break # Save the new break.
movl %ebp, %esp
popl %ebp
ret

error:
movl $0, %eax # On error return zero.
movl %ebp, %esp
popl %ebp
ret

# -------------- #
# | deallocate | #
# -------------- #

# PURPOSE: This function gives back a region of memory to the heap.
# PARAMETERS: The only parameter is the address of the memory region.
# RETURN VALUE: There is no return value.
# NOTE: This function goes back 8 locations in the memory region to the start
#       of its header and marks the memory as available.

.globl deallocate
.type deallocate, @function
.equ ST_MEMORY_SEG, 4 # Stack position of the parameter.

deallocate:
movl ST_MEMORY_SEG(%esp), %eax
subl $HEADER_SIZE, %eax # Move the pointer to the header start.
movl $AVAILABLE, HDR_AVAIL_OFFSET(%eax) # Mark it as available.
ret
