.model small
.stack 100h

.data
.code
main proc
    mov ax, @data
    mov ds, ax
    
    ;------ input -----
    
    mov ah, 1
    int 21h
    sub al, 48
    
    mov cl, al
    mov al, 1
    mov ah, 0
    
factorial_loop:
    mul cl
    dec cl
    cmp cl,0
    jnz factorial_loop
    
    ; ---- output ----
    mov cx, 0
    mov bx, 10
    
convert_loop:
    mov dx, 0
    div bx
    push dx
    inc cx
    cmp ax, 0
    jne convert_loop
    
display_loop:
    pop dx
    add  dl, 48
    mov ah, 2
    int 21h
    loop display_loop
    
exit:
    mov ah,4ch
    int 21h
    
main endp
end main
        
    
    