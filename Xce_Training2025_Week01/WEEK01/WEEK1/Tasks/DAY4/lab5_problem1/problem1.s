.section .text
.globl _start

_start:
    # Load numbers
    li t0, 30          # first number
    li t1, 40          # second number

    # Compute absolute difference
    sub t2, t0, t1
    bltz t2, negate


negate:
    neg t2, t2

exit:

    la x8, a
    sw t2,0(x8)

    # Exit program
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)
    nop

.section .data
a: .word 0

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

# spike -d --log-commits problem5
