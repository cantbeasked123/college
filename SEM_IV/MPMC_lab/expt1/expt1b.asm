;Joshua Fernandes
;ALP to display 2 strings

	section .data			;data segment
	msg1 db "My name is joshua",13,10
					;string1
	len1 equ $ - msg1 		;length of the string1
	msg2 db "This is my first 80386 program",13,10
					;string2
	len2 equ $ - msg2 		;length of the string2

	
	section .text			;code segment
		global _start		;must be declared for linker
	_start:				;tell linker its entry point
		mov edx, len1		;message length1
		mov ecx, msg1		;message to write
		mov ebx, 1		;file descriptor(stdout)
		mov eax, 4		;system call number(sys_write)
		int 80h			;call kernel

		mov edx, len2		;message length
		mov ecx, msg2		;message to write
		mov ebx, 1		;file descriptor(stdout)
		mov eax, 4		;system call number(sys_write)
		int 80h			;call kernel
	
		mov eax,1		;system call number(sys_exit)
		int 80h			;call kernel

