;exchange the content of FFh(internal RAM) and FF00h (external RAM)

mov dptr, #FF00h 	; Load the address 0xFF00h into the Data Pointer (DPTR) register
movx A, @dptr     ; Move the data from the external memory location pointed by DPTR into the accumulator (A) register
			; MOVX is used to move data between internal and external memory locations 
mov r0, FFh      	; Save the content of the accumulator (A) into the R0 register as a temporary storage....***r0=temp***
mov FFh, A       	; Write the value 0xFF from the accumulator (A) into the external memory location 0xFFh****
mov A, r0         ; Retrieve the previously saved value from R0 and move it into the accumulator (A)
movx @dptr, A     ; Move the data in the accumulator (A) back to the external memory location pointed by DPTR
end