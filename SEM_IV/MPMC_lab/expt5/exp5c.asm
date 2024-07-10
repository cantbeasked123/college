;Programmer: Joshua Fernandes 22CO16
;ALP to find the factorial of a number

%macro write 2
mov eax,4
mov ebx,1
mov ecx,%1
mov edx,%2
int 80h
%endmacro

%macro read 2
mov eax,3
mov ebx,0
mov ecx,%1
mov edx,%2
int 80h
%endmacro

section .data
msg1 db "enter the number",10,13
len1 equ $-msg1
msg2 db "the factorial is: ",10,13
len2 equ $-msg2
newline db 10,13

section .bss
num1 resb 2
num2 resw 1
dispbuff resq 1

section .text
global _start

_start:
write msg1,len1
read num1,num2
xor eax,eax
xor ebx,ebx
xor ecx,ecx
xor edx,edx
CALL convert
mov [num2],bx
write msg2,len2
xor eax,eax
xor ebx,ebx
xor ecx,ecx
xor edx,edx
mov bx,[num2]
mov eax,1
CALL proc_fact
mov ebx,eax
call display

exit: 
mov eax,1
mov ebx,0
int 80h

proc_fact:
cmp bl,1
jg xyz
ret

xyz:
mul ebx
dec bl
call proc_fact
ret

;procedure to convert 2 digit number stored in num1 from ascii to hex
convert:
mov esi,num1
mov edi,num2
mov cl,02h
xor eax,eax
xor ebx,ebx

up: 
rol bl,04h
mov al,[esi]
cmp al,39h
jbe skipc
sub al,07h

skipc: sub al,30h
add bl,al
mov[edi],bl
inc esi
inc edi
loop up
ret

;procedure to display 2-digit number stored on disbuff from hex to ascii
display:
mov ecx,8
mov edi,dispbuff

again: 
rol ebx,4
mov al,bl
and al,0fh
cmp al,09h
jbe down
add al,07h

down: 
add al,30h
mov[edi],al
inc edi
loop again
write dispbuff,8
write newline,1
ret
