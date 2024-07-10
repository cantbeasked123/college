; Clear the Carry flag to ensure there is no carry from previous operations
clr c

mov r4, #0ah
mov r5, #04h
mov r6, #0fh
mov r7, #0ah
; Subtract the value of R6 from the value of R4 and store the result in the accumulator (A)
mov A, r7
subb A, r5

; Store the result of the subtraction (lower byte) in memory location 20h
mov 20h, A

; Subtract the value of R7 from the value of R5 and store the result in the accumulator (A)
mov A, r6
subb A, r4

; Store the result of the subtraction (higher byte) in memory location 21h
mov 21h, A

end