;Programmer:Joshua Fernandes 22CO16
;ALP to check if the number is odd or even

 section .data                            ;data section
  msg db 10,13,"Enter a number: "         ;string 1
  len equ $-msg                           ;length of string 1

  even_msg db "Even Number!",10,13         ;string 2
  len1 equ $ - even_msg                   ;length of string 2
    
  odd_msg db "Odd Number!",10,13          ;string 3
  len2 equ $ - odd_msg                    ;length of string 3
    
 section .bss                             ;bss section
  num resb 1                              ;Reserve a byte for num 
    
 section .text                            ;text section
   global _start                            
 _start:                                  ;linker entry point

 ;Display msg                                        
   	mov eax,4  
   	mov ebx,1
   	mov ecx,msg	
   	mov edx,len	                                 
   	int 80h                                         
   
 ;Accept num
   	mov eax,3                        ;take input from keyboard
   	mov ebx,2                        ;(stdin)
   	mov ecx,num                      ;input stored to ecx containing num
   	mov edx,1                        ;number of locations
        int 80h                          ;call kernel
   
        mov eax,[num]
        ror eax,1    
        jnc evnn                         ;jump to even block 
        
;Display number is odd
        mov eax,4
        mov ebx,1
        mov ecx,odd_msg
        mov edx,len2
        int 80h
        jmp exit 
        
;Display number is even    
 evnn: mov eax,4 
       mov ebx,1
       mov ecx,even_msg
       mov edx,len1
       int 80h
   
   exit: mov eax,1                       ;sys_exit
         int 80h  
