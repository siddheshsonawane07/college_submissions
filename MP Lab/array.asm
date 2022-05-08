section .data
    mesg1 db "Enter the numbers ",10,13
    mesg1len equ $-mesg1
    mesg2 db "Display the numbers ",10,13
    mesg2len equ $-mesg2
    
section .bss
    num resb 10 
    
section .text 
    global _start 
_start:
    mov rax,1
    mov rdi,1
    mov rsi,mesg1 
    mov rdx,mesg1len
    syscall 
    
    mov rax,0
    mov rdi,3O
    mov rsi,num
    syscall
    
    mov rax,1
    mov rdi,1
    mov rsi,mesg2
    mov rdx,mesg2len 
    
    syscall
    mov rax,1
    mov rdi,1
    mov rsi,num
     
    syscall
    mov rax,60
    mov rdi,3O
    syscall
