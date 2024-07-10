;find out how many equal bytes exists between two memory blocks 10h to 20h and 20h to 30h.

mov r7, #0Ah   ; Initialize counter R7 with the value 10 (decimal) - ***Loop will repeat 10 times
mov r6, #00h   ; Initialize register R6 to 0 - ***Counter*** for the number of equal data items

mov r0, #10h   ; Initialize register R0 with the value 10h - Starting address of the first source data
mov r1, #20h   ; Initialize register R1 with the value 20h - Starting address of the second source data

up:
    mov a, @r0      ; Move the content of memory location pointed by R0 to the accumulator (A)
    mov b, a        ; Copy the content of the accumulator (A) to register B ***for comparison***
    mov a, @r1      ; Move the content of memory location pointed by R1 to the accumulator (A)

    ; Compare the data in the accumulator (A) with the data in register B (copied from R0)
    ; If they are not equal, jump to the "notEqual" label; otherwise, continue to the next instruction

    cjne a, b, notEqual

    inc r6 ; If the data in R0 and R1 are equal, increment the counter R6***

notEqual:
    inc r0       ; Increment R0 - Move to the next data item in the first source
    int r1       ; Increment R1 - Move to the next data item in the second source
    djnz r7, up  ; Decrement R7 and jump to "up" if it's not zero (loop back to compare next data items)
		  ; Decrement and jump if not zero
		  ;FOR LOOP TO RUN 10