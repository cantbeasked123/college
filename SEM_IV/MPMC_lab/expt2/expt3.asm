;Joshua fernandes 22co16
;Experiment 3:To input 2 numbers and display its sum
;Date: 14/02/2024

	section .data				;DATA SECTION
	msg db "Enter a number: "		
	len equ $-msg				
	msg1 db 10, 13, "Sum: "			
	len1 equ $-msg1				

	section .bss				;BSS SECTION
		num1 resb 2				;Reserve byte for num1
		num2 resb 2				;Reserve byte for num2
		sum resb 1				;Reserve byte for sum

	section .text				;TEXT SECTION
		global _start					
		_start:				;linker entry point						
		mov edx, len				;Display msg
		mov ecx, msg				
		mov ebx, 1			
		mov eax, 4				
		int 80h					
	
		mov eax, 3				;take input for num1
		mov ebx, 0				
		mov ecx, num1				
		mov edx, 2				
		int 80h					

		mov edx, len				;Display msg
		mov ecx, msg				
		mov ebx, 1			
		mov eax, 4				
		int 80h
	
		mov eax, 3				;take input for num2
		mov ebx, 0				
		mov ecx, num2				
		mov edx, 2				
		int 80h					

		 	
		mov edx, len1				;display msg1
		mov ecx, msg1				
		mov ebx, 1				 
		mov eax, 4				
		int 80h	

		mov ax, [num1]				;mov num1 value to ax
		sub al, '0'				;ascii to decimal
		mov bx, [num2]				;mov num2 value to bx
		sub bl, '0'				;ascii to decimal
		add ax, bx				;ax<-ax+bx
		add ax, '0'				;decimal to ascii
		mov [sum], ax

		mov edx, 1				;display msg1
		mov ecx, sum				
		mov ebx, 1				 
		mov eax, 4				
		int 80h	
		
		mov eax, 1				;sys_exit
		int 80h					

