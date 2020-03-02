BITS 64

SECTION .text

GLOBAL strcspn:function

strcspn:
    PUSH RBP
    MOV RBP, RSP
    XOR RAX, RAX
loop:
    MOV DL, BYTE[RDI + RAX]
    CMP DL, 0
    JE end
    XOR RCX, RCX
check:
    CMP BYTE[RSI + RCX], 0
    JE loopnext
    CMP BYTE[RSI + RCX], DL
    JE end
    INC RCX
    JMP check
loopnext:
    INC RAX
    JMP loop
end:
    LEAVE
    RET