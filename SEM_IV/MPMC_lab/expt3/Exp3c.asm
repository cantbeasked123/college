;Programmer:Joshua Fernandes 22CO16
;Program to ask the user to enter 3 single digit numbers and return the largest of 3 numbers

section .data                                    ;data section
    msg1 db "Enter number 1: "                   ;string 1
    len1 equ $-msg1                              ;length of string 1
    msg2 db "Enter number 2: "                   ;string 2
    len2 equ $-msg2                              ;length of string 2
    msg3 db "Enter number 3: "                   ;string 3 
    len3 equ $-msg3                              ;length of string 3
    output_msg db"The largest number is: "       ;string 4
    len4 equ $-output_msg                        ;length of string 4

section .bss                                    ;bss section
    num1 resb 1
    num2 resb 1
    num3 resb 1
    largest resb 1                              ;reserve byte for largest

section .text                                   ;text section
    global _start
_start:                                         ;linker entry point

  ;Input for num1
    mov eax,4
    mov ebx,1
    mov ecx,msg1
    mov edx,len1
    int 80h

;Read the input for num1
    mov eax,3
    mov ebx,0
    mov ecx,num1
    mov edx,2
    int 80h

 ;Input for num2
    mov eax,4
    mov ebx,1
    mov ecx,msg2
    mov edx,len2
    int 80h

 ;Read the input for num2
    mov eax,3
    mov ebx,0
    mov ecx,num2
    mov edx,2
    int 80h

 ;Input for num3
    mov eax,4
    mov ebx,1
    mov ecx,msg3
    mov edx,len3
    int 80h

 ;Read the input for num3
    mov eax,3
    mov ebx,0
    mov ecx,num3
    mov edx,2
    int 80h

;Compare the first and the second number
    mov al,byte [num1]
    mov bl,byte [num2]
    cmp al,bl
    jge check_first_third
    mov al,byte[num2]
    jmp check_second_third
    int 80h

   
    check_second_third:                     ; Compare the second and the third number
    mov al,byte [num2]
    mov bl,byte [num3]
    cmp al,bl
    jge output
    mov al,byte [num3]
    jmp output
    int 80h

   check_first_third:
                                          ; Compare the first and the third number
    mov al,byte [num1]
    mov bl,byte [num3]
    cmp al,bl
    jge output
    mov al,byte [num3]
    jmp output
    int 80h


    output:
                                          ;Moving the value of al to the largest variable
    mov [largest],al

 ; Display the message
    mov eax,4
    mov ebx,1
    mov ecx,output_msg
    mov edx,len4
    int 80h

 ;Output the largest number
    mov eax,4
    mov ebx,1
    mov ecx,largest
    mov edx,1
    int 80h
   
    exit:
    mov eax,1                             ;sys_exit
    int 80h                               ;call kernel
