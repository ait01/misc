.include "linux.s"
.equ ST_ERROR_CODE, 8
.equ ST_ERROR_MSG, 12
.globl error_exit
.type error_exit, @function

error_exit:
pushl %ebp
movl %esp, %ebp

movl ST_ERROR_CODE(%ebp), %ecx # Write out the error code.
pushl %ecx
call count_chars
popl %ecx
movl %eax, %edx
movl $STDERR, %ebx
movl $SYS_WRITE, %eax
int $LINUX_SYSCALL

movl ST_ERROR_MSG(%ebp), %ecx
pushl %ecx
call count_chars
popl %ecx
movl %eax, %edx
movl $STDERR, %ebx
movl $SYS_WRITE, %eax
int $LINUX_SYSCALL

pushl $STDERR
call write_newline

movl $SYS_EXIT, %eax
movl $1, %ebx
int $LINUX_SYSCALL
