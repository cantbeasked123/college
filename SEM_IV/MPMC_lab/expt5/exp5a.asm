;Programmer: Joshua Fernandes 22CO16
;ALP to display a string using macros

%macro write 2
	mov eax, 4
	mov ebx, 1		
	mov ecx, %1         ;message to be printed 
	mov edx, %2         ;length of message 
	int 80h
%endmacro

section .data
    msg1 db 10,13,"Hello"
    len1 equ $-msg1
    msg2 db 10,13, "Goodmorning"
    len2 equ $-msg2
    newline db 10
    
section .text
    global _start
_start:
    write msg1, len1
    write msg2, len2
    write newline, 1
    mov eax, 1
    int 80h
