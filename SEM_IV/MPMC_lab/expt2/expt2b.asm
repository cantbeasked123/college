;joshua fernandes 22co16
;Experiment 2b:Write ALP to add 2 numbers stored in memory and then display the sum to the user on the output device
;Date: 14/02/2024

	section .data	;data segment
	msg db "***Basic Mathematical Operation***"	;
	len equ $ - msg
	msg1 db 10,13,"Sum is:"	;
	len1 equ $ - msg1	;

	section .bss
		sum resb 1

	section .text
		global _start
			_start:
			mov[sum],AX

			mov ECX, msg
			mov EDX, len
			mov EBX, 1
			mov EAX, 4
			int 80h

			mov ECX, msg1
			mov EDX, len1
			mov EBX, 1
			mov EAX, 4
			int 80h

			;***Addition***
			mov AX, '6'
			;Convert to ASCII '6' to Decimal	;AX<-36
			sub AX, '0'	;AX<-36-30<-06
			mov BX, '2'	;BX<-32
			sub BL, '0'	;BX<-32-30<-02	
			add AL, BL	;AL<-6+2<-8
			add AX, '0'	;AX<-08+30<-38
			mov[sum],AX	;[sum]<-38

			;display sum
			mov ECX, sum
			mov EDX, 1
			mov EBX, 1
			mov EAX, 4
			int 80h

			mov EAX, 1	;	
			int 80h	;

