; Programmer: Joshua Fernandes 22CO16
;ALP to initialize the give array members and to display the number of even and odd numbers in the array



 	section .data
     		title db "Count of ODD and EVEN nums in array",10,13
     		title_len equ $-title
 
   		odd_msg db "Odd count",10,13
   		odd_len equ $-odd_msg
           
   		even_msg db "Even count",10,13
  		even_len equ $-even_msg    
 
   		newline db 10
 
  	;array declaration and initialization
   		array dw 1H, 2H, 3H, 4H, 5H, 6H, 7H, 8H, 9H
   		arrcnt equ 9   			;static array count
 
  		ocnt dw 0      			;odd num count
  		ecnt dw 0      			;even num count
 
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
 
	UP: 
		BT word[ESI] ,0 		; check for msb using 0
    		JC ECXT
    		INC byte[ecnt]
    		JMP OSKIP
   
 
	ECXT: 
		INC byte[ocnt]

		OSKIP: INC ESI
		INC ESI
       
		LOOP UP  
 
 	;code to displa odd_msg
   		mov eax, 4
   		mov ebx, 1
   		mov ecx, odd_msg
   		mov edx, odd_len            
   		int 80h
 
  		mov BL, [ocnt]
    		CALL HEX_ASCII 			;call procedure
 
  	;to print newlinw
    		mov eax, 4
    		mov ebx, 1
    		mov ecx, newline
    		mov edx, 1            
    		int 80h  
 
  	;write code to disp even_msg
    		mov eax, 4
    		mov ebx, 1
    		mov ecx, even_msg
    		mov edx, even_len            
    		int 80h
 
  		MOV BL, [ecnt]
   		CALL HEX_ASCII
 
  	;to print newline
    		mov eax, 4
    		mov ebx, 1
    		mov ecx, newline
   		 mov edx, 1            
    		int 80h
 
  	;code to exit program
    		 mov EAX,1      		;system call number(sys_exit)
     		int 80h

 
  	;HEX_ACII procedure
 		HEX_ASCII: mov ECX, 2
      		mov EDI, dispbuffer
           
   
    	DUP:   
		ROL BL, 04 			;rotate left //only using BL register ie lower order byte
  		mov AL, Bl
  		AND Al, 0Fh 			;to turn higher nible 0
  		CMP Al, 09   			;compare if number is in 0-9 range
           	JBE NEXT
      		ADD AL, 07h
     
   	NEXT: 
		ADD al, 30h 			;to convert to ascii
         	mov [EDI], al 			;store where edi is pointing
         	INC EDI     			;inc by 1
         	LOOP DUP  
         
   	;display count
     		mov eax, 4
     		mov ebx, 1
     		mov ecx, dispbuffer
     		mov edx, 2                                          
     		int 80h  
 
  	 RET
