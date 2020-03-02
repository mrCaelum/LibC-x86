BITS 64

SECTION .text

GLOBAL strpbrk:function

strpbrk:
    PUSH RBP
    MOV RBP, RSP
    XOR RAX, RAX
    CMP RDI, 0
    JE end
    CMP RSI, 0
    JE end
    CMP BYTE[RSI], 0
    JE end
loop:
    CMP BYTE[RDI], 0
    JE end
    JMP compare
loopnext:
    INC RDI
    JMP loop
compare:
    XOR RCX, RCX
cmploop:
    MOV DL, BYTE[RSI + RCX]
    CMP DL, 0
    JE loopnext
    CMP BYTE[RDI], DL
    JE addptr
    INC RCX
    JMP cmploop
addptr:
    MOV RAX, RDI
end:
    LEAVE
    RET