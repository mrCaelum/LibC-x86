BITS 64

SECTION .text

GLOBAL memmove:function

memmove:
    PUSH RBP
    MOV RBP, RSP
    MOV RAX, RDI
    CMP RDX, 0
    JE end
    CMP RSI, RDI
    JE end
    JG loop2
loop1:
    DEC RDX
    MOV CL, [RSI+RDX]
    MOV [RDI+RDX], CL
    CMP RDX, 0
    JNE loop1
    JMP end
loop2:
    DEC RDX
    MOV CL, [RSI]
    MOV [RDI], CL
    INC RSI
    INC RDI
    CMP RDX, 0
    JNE loop2
end:
    LEAVE
    RET