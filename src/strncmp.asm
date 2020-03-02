BITS 64

SECTION .text

GLOBAL strncmp:function

strncmp:
    PUSH RBP
    MOV RBP, RSP
    XOR RCX, RCX
    XOR R8, R8
    XOR R9, R9
loop:
    MOV R8B, [RDI+RCX]
    MOV R9B, [RSI+RCX]
    INC RCX
    CMP R8B, 0
    JE end
    CMP RCX, RDX
    JE end
    CMP R8B, R9B
    JE loop
end:
    MOV RAX, R8
    SUB RAX, R9
    LEAVE
    RET