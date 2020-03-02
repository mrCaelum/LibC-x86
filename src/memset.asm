BITS 64

SECTION .text

GLOBAL memset:function

memset:
    PUSH RBP
    MOV RBP, RSP
    MOV RAX, RDI
loop:
    CMP RDX, 0
    JE end
    MOV BYTE[RDI], SIL
    INC RDI
    DEC RDX
    JMP loop
end:
    LEAVE
    RET