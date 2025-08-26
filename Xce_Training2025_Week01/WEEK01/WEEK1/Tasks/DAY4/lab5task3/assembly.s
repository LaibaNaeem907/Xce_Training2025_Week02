    .globl _start
    .section .text
_start:  
    li x11, 13      # Dividend (Q)
    li x1,  3       # Divisor  (M)
    li x2,  0       # Remainder (R)
    li x3,  4       # number of iterations (n)
    li x5,  0       # loop counter
    li x6,  3       # n-1 = 3 
    li x12, 15      # mask = 1111b

loop:
    beq x3, x5, done         # if loop counter == n : end

    # 1. Shift R left and bring in MSB of Q
    slli x2, x2, 1
    srl  x7, x11, x6
    andi x7, x7, 1
    or   x2, x2, x7

    # 2. Subtract M if R >= 0
    blt x2, x0, neg_case
    sub  x2, x2, x1
    blt  x2, x0, next       # if R < 0 after subtract, Q LSB = 0
    ori  x11, x11, 1        # else set LSB of Q = 1
    j next

neg_case:
    # R < 0  => restore R (Q LSB stays 0)
    add x2, x2, x1

next:
    # Shift Q left and mask to keep n bits
    slli x11, x11, 1
    and  x11, x11, x12

    # Increment loop counter
    addi x5, x5, 1
    j loop

done:
    # Final restore of R if negative
    blt x2, x0, final_restore
    j store

final_restore:
    add x2, x2, x1

store:
    # Store quotient and remainder
    la x8, quotient
    sw x11, 0(x8)
    la x9, remainderr
    sw x2, 0(x9)

    # Exit Spike
    li   t0, 1
    la   t1, tohost
    sd   t0, 0(t1)
    nop

.section .data
quotient:   .word 0
remainderr: .word 0

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0
