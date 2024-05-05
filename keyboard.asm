.model small
.stack 100h
.data
.code
main proc
    mov ax, @data
    mov ds, ax
    
    ;take first input
    
    mov ah,1
    int 21h
    mov bl, al
    
    ;take 2nd input
    mov ah,1
    int 21h
    mov cl, al
    
    ;print newline
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h
    
    ;print first input
    mov ah,2
    mov dl,bl
    int 21h
    
    ;print 2nd input
    mov ah,2
    mov dl,cl
    int 21h
    
    mov ah,4ch
    int 21h
    main endp
end main
    
    