;Programmer: Joshua Fernandes 22CO16
;;Write an ALP to display ‘Hello World’ vertically downwards.
SYS_WRITE EQU 4
SYS_READ EQU 3
SYS_EXIT EQU 1
STDOUT EQU 1
STDIN EQU 0
Section .data
strr db 'Hello World'
strlen equ $ - strr
nl db ' ', 0Ah
nllen equ $ - nl
Section .bss
NUM RESB 1
Section .text
 global _start
 _start:
Mov ECX, strlen ; strlen is length of string
Mov EAX, strr ; strr is the string Hello World
up:
MOV EBX, EAX
MOV [NUM], EBX
ADD EAX, 1
PUSH EAX
PUSH ECX
;Display Num
MOV EAX, SYS_WRITE
MOV EBX,STDOUT
MOV ECX,[NUM]
MOV EDX,1
INT 80H
;Display nl
MOV EAX, SYS_WRITE
MOV EBX, STDOUT
MOV ECX, nl
MOV EDX, nllen
INT 80H
POP ECX
POP EAX
LOOP up

exit:
 MOV EAX,SYS_EXIT
 XOR EBX, EBX
 INT 80H
