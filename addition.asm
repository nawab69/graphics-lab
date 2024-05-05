.model small
.stack 100h
.data
    a db "Enter First Input : $"
    b db "Enter 2nd input : $"
    c db "Result : $"
.code
main proc
    mov ax, @data
    mov ds, ax
    
    ;print enter first input
    mov ah,9
    lea dx,a
    int 21h
    
    ;take first input
    mov ah, 1
    int 21h
    mov bl,al
    sub bl, 48
    
    ;print newline
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    
    ;print enter 2nd input
    mov ah, 9
    lea dx,b
    int 21h
    
    ;take 2nd input
    mov ah,1
    int 21h
    mov cl, al
    sub cl, 48 
    
    ;print newline
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h  
    
    ;addition
    add bl, cl
    
    ;convert result back to ascii
    add bl, 48
    
    ;print result
    mov ah,9
    lea dx,c
    int 21h
    
    mov ah,2
    mov dl, bl
    int 21h
    
    mov ah, 4ch
    int 21h
    main endp
end main
    
    
    
    
        


