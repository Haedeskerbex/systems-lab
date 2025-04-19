[BITS 16]

org 0x7C00

start:
	mov si, message

hello:
	lodsb
	cmp al,0
	je hang 
	mov ah,0x0E
	int 0x10
	jmp hello

hang:
	jmp $
message db "Hello from bootloader", 0
times 510 - ($ - $$) db 0
dw 0xAA55

