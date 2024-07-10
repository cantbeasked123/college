;Programmer: Joshua Fernandes 22CO16
;ALP to to count number of Positive and Negative numbers from the array using procedures


	section .data
	title db "count of Positive and negative nums in array",10,13
	title_len equ $-title
 
	pos_msg db "positive count:",10,13
	pos_len equ $-pos_msg
           
	neg_msg db "negative count:",10,13
	neg_len equ $-neg_msg    
 
   	newline db 10
 
	;array declaration and initialization
	array dw 10H, -21H, 45H, 12H, -34H, 48H, 98H, -89H
	arrcnt equ 9   ;static array count
 
	pcnt dw 0      ;+ve num count
	ncnt dw 0      ;-ve num count
 
	section .bss
 		dispbuffer resb 2
 
	section .text
  		global _start
	 _start:
 
 	;code to disp title
		mov EAX,4
   		mov EBX,1
   		mov ECX, title
   		mov EDX, title_len                                    
   		int 80h

 	;initializing array start address
  		mov ESI,array
  		mov ECX, arrcnt
 
	UP: BT word[ESI],15 ; check for msb
    		JC NCXT
    		INC byte[pcnt]
    		JMP PSKIP
   
 
	NCXT: INC byte[ncnt]

	PSKIP: INC ESI
		INC ESI
       
		LOOP UP  
 
 	;code to display pos_msg
   		mov eax, 4
   		mov ebx, 1
   		mov ecx, pos_msg
   		mov edx, pos_len            
   		int 80h
 
  		mov BL, [pcnt]
  		CALL HEX_ASCII ;call procedure
 
  	;to print newlinw
  		mov eax, 4
  		mov ebx, 1
  		mov ecx, newline
  		mov edx, 1            
  		int 80h  
 
  	;write code to disp neg_msg
  		mov eax, 4
  		mov ebx, 1
  		mov ecx, neg_msg
  		mov edx, neg_len            
  		int 80h
 
  		MOV BL, [ncnt]
  		CALL HEX_ASCII
 
  	;to print newline
  		mov eax, 4
  		mov ebx, 1
  		mov ecx, newline
  		mov edx, 1            
  		int 80h
 
  	;code to exit program
  		mov EAX,1          ;system call number(sys_exit)
  		int 80h

 
  	;HEX_ACII procedure
	  	HEX_ASCII:
		mov ECX, 2
        	mov EDI, dispbuffer
   
   
    	DUP:   ROL BL, 04 ;rotate left //only using BL register ie lower order byte
  		mov AL, Bl
  		AND Al, 0Fh ;to turn higher nible 0
  		CMP Al, 09   ;compare if number is in 0-9 range
           	JBE NEXT
      		ADD AL, 07h
     
   	NEXT: ADD al, 30h ;to convert to ascii
         	mov [EDI], al ;store where edi is pointing
         	INC EDI     ;inc by 1
         	LOOP DUP  
         
   	;display count
   		mov eax, 4
   		mov ebx, 1
   		mov ecx, dispbuffer
   		mov edx, 2                                          
   		int 80h  
 
   	RET
