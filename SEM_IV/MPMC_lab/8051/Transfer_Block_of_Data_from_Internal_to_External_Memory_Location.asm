;transfer the block of data from 20h to 30h(internal memory) to external location 1020h to 1030h.

mov r7, #0Ah         ; Initialize counter R7 with the value 10 (decimal) - ****Loop will repeat 10 times
mov r0, #20h         ; Initialize register R0 with the value 20h - Starting address of the source data
mov dptr, #1020h     ; Initialize DPTR (Data Pointer) with the value 1020h - Starting address of the ***destination data***

up:
    mov A, @r0       ; Move the content of memory location pointed by R0 to the accumulator (A)
    movx @dptr, A    ; Move the data from the accumulator (A) to the memory location pointed by DPTR
    inc r0           ; Increment the value of R0 - Move to the next source memory location
    inc dptr         ; Increment DPTR - Move to the next destination memory location
    djnz r7, up      ; Decrement R7 and jump to "up" if it's not zero (loop back to copy next data item)

end