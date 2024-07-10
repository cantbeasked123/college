;Programmer: Joshua Fernandes 22CO16
;write an ALP to:
;2)transfer a block of data from one location to another

%macro write 2
  mov eax,4
  mov ebx,1
  mov ecx,%1
  mov edx,%2
  int 80h
%endmacro

section .data
  msg1 db 10,13,"Before transfering the data, the array elements are: ",10,13
  len1 equ $-msg1
  msg2 db 10,13,"After transfering the data, the array elements are: ",10,13
  len2 equ $-msg2
  array db 12h,49h,53h,32h,67h
  darr db 00h,00h,00h,00h,00h
  newline db '',13,10

section .bss
  counter resb 1
  result resb 4

section .text
  global _start

 _start:
  write msg1,len1
  mov byte[counter],05
  mov esi,array

  next:    
mov al,[esi]
      push esi
      call disp
      pop esi
      inc esi
      dec byte[counter]
      jnz next
  mov byte[counter],05
  mov esi,array
  mov edi,darr

  nxt:    
mov al,[esi]
      mov [edi],al
      inc esi
      inc edi
      dec byte[counter]
      jnz nxt
  write msg2,len2
  mov byte[counter],05
  mov edi,darr

  a1:    
mov al,[edi]
      push edi
      call disp
      pop edi
      inc edi
      dec byte[counter]
      jnz a1

  mov eax,1
  mov ebx,0
  int 80h

  disp:
    mov bl,al
    mov edi,result
    mov cx,02

    again:  
rol bl,04
        mov al,bl
        and al,0fh
        cmp al,09h
        jg down
        add al,30h
        jmp skip1

    down:    
add al,37h    

    skip1:    
mov [edi],al
    inc edi
    dec cx
    jnz again
    write result,2
    write newline,2

  ret

