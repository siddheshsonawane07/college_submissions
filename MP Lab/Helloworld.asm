section .data
    msg db "Hello world!", 0ah   ;db=declare/define byte(8-bit)
    msglen: equ $-msg
    
section .text
    global _start

_start:
    mov rax, 1     ;system display call
    mov rdi, 1
    mov rsi, msg
    mov rdx, msglen
    syscall
    
    
    mov rax, 60    ;system exit call
    mov rdi, 0
    syscall
