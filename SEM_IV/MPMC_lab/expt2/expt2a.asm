;Joshua fernandes 22co16
;Experiment 2a:Write ALP to enter a number and display it
;Date: 14/02/2024

	section .data				;DATA SECTION
	  msg db "Enter a digit: "		
	  len equ $-msg				;length of msg
	  msg1 db 10, 13, "Entered number: "	
	  len1 equ $-msg1			;length of msg1
	  nline db 0ah				
	  nlen equ $-nline			

	section .bss				;BSS SECTION
	  num resb 0				;Reserve byte for num

	section .text				;TEXT SECTION
	  global _start				
		_start:				;linker entry point
							
		mov edx, len			;Display msg
		mov ecx, msg			
		mov ebx, 1			
		mov eax, 4			
		int 80h				
	

		mov eax, 3			;take input from keyboard
		mov ebx, 0			;(stdin)
		mov ecx, num			;input stored to ecx containing num
		mov edx, 1			;number of locations
		int 80h				;call kernel
				
		mov edx, len1			;display msg1
		mov ecx, msg1				
		mov ebx, 1				
		mov eax, 4				
		int 80h
	
		mov edx, 1			;Display num(entered number)
		mov ecx, num			;move num value to ecx
		mov ebx, 1				
		mov eax, 4				
		int 80h
	
		mov edx, nlen			;newline
		mov ecx, nline				
		mov ebx, 1				
		mov eax, 4				
		int 80h	
		
		mov eax, 1			;sys_exit
		int 80h				
