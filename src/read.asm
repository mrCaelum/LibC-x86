BITS 64

SECTION .text

GLOBAL read:function

read:
    PUSH RBP
    MOV RBP, RSP
    XOR RAX, RAX
    SYSCALL
    LEAVE
    RET