BITS 64

SECTION .text

GLOBAL strcasecmp:function

strcasecmp:
    PUSH RBP
    MOV RBP, RSP
    XOR RCX, RCX
    XOR R8, R8
    XOR R9, R9
loop:
    MOV R8B, [RDI+RCX]
    MOV R9B, [RSI+RCX]
    CMP R8B, 97
    JL b1
    CMP R8B, 122
    JG b1
    SUB R8B, 32
b1:
    CMP R9B, 97
    JL b2
    CMP R9B, 122
    JG b2
    SUB R9B, 32
b2:
    INC RCX
    CMP R8B, 0
    JE end
    CMP R8B, R9B
    JE loop
end:
    MOV RAX, R8
    SUB RAX, R9
    LEAVE
    RET