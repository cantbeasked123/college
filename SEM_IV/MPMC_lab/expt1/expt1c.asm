;Joshua Fernandes
;ALP to display 9 stars(*)

	section .data		;data segment
	msg times 9 db "*" ;string
	len equ $ - msg 	;length of the string
	
	section .text		;code segment
		global _start	;must be declared for linker
	_start:			;tell linker its entry point
		mov edx, 9	;message length
		mov ecx, msg	;message to write
		mov ebx, 1	;file descriptor(stdout)
		mov eax, 4	;system call number(sys_write)
		int 80h		;call kernel

		mov eax,1	;system call number(sys_exit)
		int 80h		;call kernel

