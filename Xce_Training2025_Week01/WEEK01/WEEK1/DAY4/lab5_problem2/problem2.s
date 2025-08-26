    .section .text
    .globl _start

_start:
    li t0, 5         
    mv t1, t0         
    addi t2, t0, -1   

factorial:
    beqz t2, done    
    mul t1, t1, t2    
    addi t2, t2, -1  
    j factorial

done:
    # result is in t1
    # exit program properly
    la x8, a
    sw t9,0(x8)
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)
    nop

.section .data
a: .word 0
.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0
