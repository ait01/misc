.section .data
msg:
.ascii "Hello, World!\n\0"
.section .text
.globl _start
_start:
pushl $msg
call printf
pushl $0
call exit
