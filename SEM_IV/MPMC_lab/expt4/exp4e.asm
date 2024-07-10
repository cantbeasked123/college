; Programmer:Joshua Fernandes 22CO16
;ALP to ask the user to enter a Uppercase character and to convert it to a lowercase character and display it


section .data
    msg1 db 10,30," Enter a uppercase character:"
    len1 equ $-msg1
    msg2 db 10,30," The character in lowercase is: "
    len2 equ $-msg2

section .bss
    buff resb 1

section .text
    global _start
 _start:

    ;display msg1
    mov eax,4
    mov ebx,1
    mov ecx,msg1
    mov edx,len1
    int 80h

    mov eax,3
    mov ebx,0
    mov ecx, buff
    mov edx,2
    int 80h

    call lower

    ;display msg2
    mov eax,4
    mov ebx,1
    mov ecx, msg2
    mov edx, len2
    int 80h

    mov eax,4
    mov ebx,1
    mov ecx, buff
    mov edx,1
    int 80h

    invalid:  
    mov eax,1
    int 80h    

    lower:    
    cmp byte[buff],41h
    jb invalid
    cmp byte[buff],5ah
    ja invalid
    add byte[buff],20h

    ret
