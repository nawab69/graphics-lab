.model small
.stack 100h
.data
.code
main proc
    mov ax, @data
    mov ds, ax
    
    ;input
    mov ah,1
    int 21h
    sub al, 48
    mov bl, al
    
    ;input   
    mov ah,1
    int 21h
    sub al, 48
    mov cl, al
    
    
    ;multiplication
    mov al,bl
    mul cl
    add al, 48
    
    
    ;print
    mov dl, al
    mov ah, 2
    int 21h
    
    mov ah,4ch
    int 21h
    
    main endp
end main
    
    
    
    
    
    
    