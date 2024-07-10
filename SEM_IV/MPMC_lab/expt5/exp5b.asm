;Programmer: Joshua Fernandes 22CO16
;write an ALP which contains the following macros:
;a) For calculating the fibonacci series for N
;b) For entering the value of N
;c) For displaying Numbers.

%macro read 2
    mov eax, 3
    mov ebx, 2
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

%macro write 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

 
%macro fibo 1
    mov eax, 0    
    mov ebx, 1
    mov ecx, %1
back:
    mov edx, eax
    add edx, ebx
    ;add eax, '0'
    mov [temp], eax
    pusha
    call display
    write disp_buffer, 2
    write spc, spclen
    popa
    mov eax, ebx
    mov ebx, edx
    loop back
%endmacro


section .data
    msg1 db 'Enter a Hexadecimal Number : '
    len1 equ $ -msg1
    msg2 db 0xa,'Fibonacii series: '
    len2 equ $ -msg2
    spc db '  '
    spclen equ $ -spc
 
section .bss
    num resb 2
    temp resb 2
    disp_buffer resb 2
   
section .text
    global _start          

_start:            
    write msg1, len1
    read num, 2
    call convert
    mov [num], ebx
    write msg2, len2  
    fibo [num]
    mov eax,1           ;system call
    int 80h             ;call kernel

convert:
mov esi, num
mov ecx, 02h
xor eax, eax
xor ebx, ebx
loop_start:
    rol bl, 04h
    mov al, [esi]
    cmp al, 39h
    jbe sub
    sub al, 07h

    sub:
    sub al, 30h
        add bl, al
        inc esi
        loop loop_start
ret

display:
mov bl, [temp]
mov cl, 2
mov edi, disp_buffer

next_digit:
    rol bl, 4
    mov al, bl
    and al, 0Fh
    cmp al, 09h
    jbe add
    add al, 07h

    add:
        add al, 30h
        mov [edi], al
        inc edi
        loop next_digit
        ret


