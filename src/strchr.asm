BITS 64

SECTION .text

GLOBAL strchr:function

strchr:
    PUSH RBP
    MOV RBP, RSP
    XOR RAX, RAX
loop:
    CMP BYTE[RDI], SIL
    JE addptr
    CMP BYTE[RDI], 0
    JE end
    INC RDI
    JMP loop
addptr:
    MOV RAX, RDI
end:
    LEAVE
    RET