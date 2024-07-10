;Programmer:Joshua Fernandes 22CO16
;ALP to display numbers from 0 to 9 using loops

section .data                                  ;data section
msg db "Numbers displayed using loop: ",0AH    ;string 1
len equ $-msg                                  ;length of string 1
nl db " ",0AH                                  ;new line instruction

section .bss                                   ;bss section
 num resb 1                                    ;resreve byte for num

section .text                                  ;text section
 global _start
_start:                                        ;linker entry point

;display string
 mov edx,len
 mov ecx,msg
 mov ebx,1
 mov eax,4
 int 80h

 mov eax,'0'                                  ;set range
 mov ecx,10

up:
 mov [num],eax
 mov edx,1
 push ecx
 mov ecx,num
 mov ebx,1
 mov eax,4
 int 80h
 
 mov ecx,nl                                  ;create space between numbers
 mov ebx,1
 mov eax,4
 int 80h
 
 mov eax,[num]                              ;take input num
 sub eax,'0'                                ;ASCII to decimal
 add eax,'1'                                ;increment the number
 pop ecx                                    ;end process
 loop up

 mov eax,1                                  ;sys_exit
 int 80h                                    ;call kernel
