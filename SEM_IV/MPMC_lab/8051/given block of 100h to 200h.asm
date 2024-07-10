;given block of 100h to 200h. Find out how many bytes from this block are
;greater then the number in r2 and less then number in r3. Store the count in r4.

ORG 100h		; the origin directive, tells the assembler where to start allocating memory
START:
    MOV R2, #175h
    MOV R3, #125h
    MOV R4, #0    ; Initialize the count of bytes in R4
    MOV R0, #100h ; Initialize the pointer to the start of the block

CHECK_BYTE:
    MOV A, @R0    		; Load the current byte into the accumulator
    CJNE A, R2, GREATER		; Compare the byte with R2
			        	; Compare and jump if not equal
    JNC LESS			; If the byte is less than or equal to R2, skip the next instruction
					; Jump if carry not set
    INC R4         		; *****Otherwise, increment the count of bytes

LESS:
    CJNE A, R3, GREATER		; Compare the byte with R3
    JC GREATER			; If the byte is greater than or equal to R3, skip the next instruction
    INC R4        	 	; Otherwise, increment the count of bytes

GREATER:
    INC R0         			; Move the pointer to the next byte
    CJNE R0, #200h, CHECK_BYTE	; Check if the pointer has reached the end of the block

    RET            ; Return from the subroutine
