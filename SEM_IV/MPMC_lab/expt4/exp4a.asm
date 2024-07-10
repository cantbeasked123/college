;Programmer:Joshua Fernandes 22CO16
;Write an ALP to convert Hexadecimal number to ASCII

	section .data
	num dw 12h

	section .bss
		dispbuffer resb 2

	section .text
		global _start
	_start:

	mov bx, word[num]
	mov ecx, 2
	mov edi, dispbuffer

	DUP:
	rol bl, 04
	mov al, bl
	and al, 0Fh
 	cmp al, 09h
	jbe NEXT
	add al, 07h

	NEXT:
	add al, 30h
	mov[edi], al
	inc edi
	loop DUP

	mov eax, 4
	mov ebx, 1
	mov ecx, dispbuffer
	mov edx, 2
	int 80h

	EXIT:
	mov eax, 1
	int 80h
