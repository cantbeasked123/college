;Programmer:Joshua Fernandes 22CO16
;ALP to find if the entered number is positive or negative

section .data                                  ;data section
msg db "Enter a number: "                      ;string 1
len equ $-msg                                  ;length of string 1

msg1 db "The entered number is Positive!"       ;string 2
len1 equ $-msg1                                ;length of string 2

msg2 db "The entered number is Negative!"       ;string 3
len2 equ $-msg2                                ;length of string 3

section .bss                                   ;bss section
num resb 1                                     ;Reserve a byte for num

section .text                                  ;text section   
global _start
_start:                                        ;linker entry point

;Display msg
mov eax,4
mov ebx,1
mov ecx,msg
mov edx,len
int 80h

;Accept num
mov eax,3                                     ;take input from keyboard
mov ebx,0                                     ;(stdin)
mov ecx,num                                   ;input stored to ecx containing num
mov edx,1                                     ;number of locations
int 80h                                       ;call kernel

;Check for positive number
mov al,[num]
sub al,'0'                                    ;convert ASCII to integer
test al, 80h                                  ; Check the sign bit Performs bitwise AND operation
jz pos                                        ;Jump if zero
jmp neg                                       ;Jump to the negative label

pos:	                                      ; Display positive message
mov eax,4
mov ebx,1
mov ecx,msg1
mov edx,len1
int 80h
jmp exit

neg:	                                      ; Display the negative messgae
mov eax,4
mov ebx,1
mov ecx,msg2
mov edx,len2
int 80h

exit:mov eax, 1                               ;Sys_exit
     int 80h                                  ;call kernel

