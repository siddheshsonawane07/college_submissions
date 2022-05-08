section .data
    mesg1 db "enter the string",10,13
    mesg1len equ $-mesg1
    mesg2 db"length of the string is:",10,13
    mesg2len equ $-mesg2
    
section .bss
    strbuff resb 200
    strlen:equ $-strbuff
    alen resq 1
    num resb 16
    
    
    %macro print 2
    mov rax,1
    mov rdi,1
    mov rsi,%1
    mov rdx,%2
    syscall
    %endmacro
    
section .text
    global _start
_start:
    print mesg1,mesg1len
    mov rax,0
    mov rdi,0
    mov rsi,strbuff
    mov rdx,strlen
    syscall
    
    dec rax
    mov[alen],rax
    print mesg2,mesg2len
    call disp64_proc
    mov rax,60
    mov rdi,0
    syscall
    
    disp64_proc:
    mov rdi,num
    mov rdi,num
    mov rcx,16
    mov rbx,[alen]
    
    dispupl:
    rol rbx,4
    mov al,bl;
    and al,0fh
