;Programmer: Joshua Fernandes 22CO16
;ALP to perform linear search

section .data
msg db "enter 5 elements:"
len equ $-msg
msg1 db "enter element to be searched :"
len1 equ $-msg1
fString db "element found at index : "
flen equ $-fString
NfString db "element not found"
Nflen equ $-NfString
nl db 10,13
size db 5

section .bss
index resb 1
key resb 1
num resb 1
array resb 5

section .text
 global _start

%macro read 2
    pusha
    mov eax, 3
    mov ebx, 0
    mov ecx, %1
    mov edx, %2
    int 80h
    popa
%endmacro

%macro write 2
    pusha
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
    popa
%endmacro

_start:

write msg, len
;accept elements from user
mov cl, 5
mov edi, array
l1:
read num, 1
mov eax, [num]
sub eax, '0'
mov [edi], eax
read nl, 1
inc edi
loop l1

write msg1, len1
read key, 1
mov eax, [key]
sub eax, '0'

mov ecx, 5
mov esi, array
mov dl, 0
linear:
mov bl, [esi]
cmp al, bl
je found
inc esi
inc dl
loop linear

write NfString, Nflen
jmp exit

found:
write fString,flen
add dl, '0'
mov [index], dl
write index, 1

exit:
     write nl, 1
     mov eax, 1
     int 80h


