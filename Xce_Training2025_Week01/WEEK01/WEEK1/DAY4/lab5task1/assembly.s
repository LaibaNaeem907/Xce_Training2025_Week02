.globl _start
.section .text
_start:  
    
    li x11, 13      # Dividend (Q)
    li x1,  3       # Divisor  (M)
    li x2,  0       # Remainder (R)
    li x3,  4       # number of iterations (n)
    li x5,  0       # loop counter
    li x6,  3       # n-1 = 3 
    li x12, 15      # mask (1111b)

loop:
    beq x3, x5, done

    #  R = (R << 1) | ((Q >> (n-1)) & 1)
    slli x2, x2, 1          # R << 1
    srl  x7, x11, x6        # Q >> (n-1)
    andi x7, x7, 1          # &1
    or   x2, x2, x7         # put into R

    # Q = (Q << 1) & mask
    slli x11, x11, 1
    and  x11, x11, x12

    # Step 3: R = R - M
    sub  x2, x2, x1

    # Step 4: if R < 0  (restore)
    blt  x2, x0, remainder
    ori  x11, x11, 1        # if positive, set Q0=1
    j next

remainder:
    add  x2, x2, x1         # restore remainder

next:
    addi x5, x5, 1          # loop counter++
    j loop

done:
    # quotient = Q in x11 
    # remainder = R in x2
    
    # store quotient
    la x8, quotient          # load address of quotient
    sw x11, 0(x8)            # store x11 → quotient

    # store remainder
    la x9, remainderr         # load address of remainder
    sw x2, 0(x9)             # store x2 → remainder

    li   t0, 1
    la   t1, tohost
    sd   t0, 0(t1)           # tell Spike to exit
    nop

.section .data
quotient:   .word 0      # 4 bytes reserve for quotient
remainderr:  .word 0      # 4 bytes reserve for remainder

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0
