;Joshua Fernandes
;ALP to display: "Hello, world!"

	section .data		;data segment
	msg db "Hello,world!",13,10	
				;Hello,world! string
	len equ $ - msg 	;length of the string
	
	section .text		;code segment
		global _start	;must be declared for linker
	_start:			;tell linker its entry point
		mov edx, len	;message length
		mov ecx, msg	;message to write
		mov ebx, 1	;file descriptor(stdout)
		mov eax, 4	;system call number(sys_write)
		int 80h		;call kernel

		mov eax,1	;system call number(sys_exit)
		int 80h		;call kernel

