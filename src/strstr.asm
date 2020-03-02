BITS 64

SECTION .text

GLOBAL strstr:function

strstr:
    PUSH RBP
    MOV RBP, RSP
    XOR RAX, RAX
    CMP BYTE[RSI], 0
    JE addptr
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
    JE addptr
    CMP BYTE[RDI + RCX], DL
    JNE loopnext
    INC RCX
    JMP cmploop
addptr:
    MOV RAX, RDI
end:
    LEAVE
    RET