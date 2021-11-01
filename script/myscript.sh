#!/bin/bash
# Script that shows how arguments are used
echo The name of this script is ${0##*/}
echo The full name of this script is $0
echo The first argument is $1
echo The length of the first argument is ${#1}
echo The second argument is $2
echo The length of the second argument is ${#2}
echo The third argument is $3
echo The length of the third argument is ${#3}
echo All the arguments are $@
echo The number of the arguments is $#
echo The PID of this script is $$
echo The PID of the current instance of Bash is $BASHPID
printf "%s\n" $@
# x-term 256 colours
for i in {0..255}; do printf "\x1b[38;5;${i}mcolour${i} "; done
printf '\n'
exit 0
