;store the higher nibble of r7 into both nibbles of r6

mov r7, #0ah
mov A, r7     ; Copy the content of R7 into the accumulator (A)
anl A, #0F0h  ; Apply a bitmask to the accumulator to extract the higher nibble (4 most significant bits) and set the lower nibble to zero
		  ; ****Mask out the lower nibble, keep the higher nibble

mov r6, A     ; Move the extracted higher nibble from the accumulator into R6
swap A        ; ****Swap nibbles again to bring the higher nibble back to its original position

orl A, r6     ; Perform a logical OR operation between the swapped nibbles in the accumulator and the content of R6 
		  ; ****This duplicates the higher nibble of R7 into both nibbles of the accumulator

mov r6, A     ; Move the duplicated higher nibble from the accumulator back into R6
end

;nibble:(4 most significant bits)