# PURPOSE: This program demonstrates how to call "printf".

.section .data
# This is the format string. It is the first parameter, and "printf" uses it
# to find out how many parameters are given and what kind they are.
formatstring:
.ascii "Hello! %s is a %s who loves the number %d.\n\0"
name:
.ascii "Jonathan\0"
person:
.ascii "person\0"
number:
.long 3 # This could also have been an ".equ".

.section .text
.globl _start
_start:
# The parameters are passed in the reverse order than in the function prototype.
pushl number # This is the "%d".
pushl $person # This is the second "%s".
pushl $name # This is the first "%s".
pushl $formatstring # This is the format string.
call printf
pushl $0
call exit
