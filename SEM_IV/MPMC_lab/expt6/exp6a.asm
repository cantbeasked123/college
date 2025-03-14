;Programmer: Joshua Fernandes 22CO16
;Write an ALP Program:
;1)to read and display array elements

section .data
    msg01 db "Enter 5 elements in array : "
    msg01L equ $ - msg01
    msg02 db "Array : "
    msg02L equ $ - msg02
    space db " "
    spaceL  equ $ - space
    new_line db "", 13, 10
    new_lineL equ $ - new_line

section .bss
    array resb 5
    whitespace resb 1

%macro read 2
    PUSHA
    MOV EDX, %2
    MOV ECX, %1
    MOV EBX, 0
    MOV EAX, 3
    INT 80H
    POPA
%endmacro

%macro write 2
    PUSHA
    MOV EDX, %2
    MOV ECX, %1
    MOV EBX, 1
    MOV EAX, 4
    INT 80H
    POPA
%endmacro

section .text   
    global _start

_start:
    write msg01, msg01L
    write new_line, new_lineL

    MOV ECX, 5
    MOV EDI, array

    input:
        read EDI, 1
        read whitespace, 1
        INC EDI
        LOOP input
    
    MOV ECX, 5
    MOV ESI, array

    write msg02, msg02L

    output:
        write ESI, 1
        write space, spaceL
        INC ESI
        LOOP output
    MOV EBX, 0
    MOV EAX, 1
    INT 80H
