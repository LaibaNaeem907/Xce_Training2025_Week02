.section .text
.globl _start
_start:
    li t1,0b10110111001101010010011111001010 
    li   t2, 0
    li   t4, 32

loop:
    andi t3, t1, 1
    beqz t3, skip
    addi t2, t2, 1

skip:
    srli t1, t1, 1
    addi t4, t4, -1
    bnez t4, loop

done:

    la x8, a
    sw t3,0(x8)
    li   t0, 1
    la   t1, tohost
    sd  t5, 0(t1)
    nop

.section .data
a: .word 0
.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0
