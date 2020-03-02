BITS 64

SECTION .text

GLOBAL write:function

write:
    PUSH RBP
    MOV RBP, RSP
    MOV RAX, 1
    SYSCALL
    LEAVE
    RET