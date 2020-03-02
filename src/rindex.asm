BITS 64

SECTION .text

GLOBAL rindex:function

rindex:
    PUSH RBP
    MOV RBP, RSP
    XOR RAX, RAX
loop:
    CMP BYTE[RDI], SIL
    JNE loopnext
    MOV RAX, RDI
loopnext:
    CMP BYTE[RDI], 0
    JE end
    INC RDI
    JMP loop
end:
    LEAVE
    RET