.globl _start
.section .text
_start:

    la   x5, array       # x5 = base address of array
    li   x6, 5           # x6 = size of array (n = 5)
    li   x7, 1           # i = 1 (outer loop counter)

outer_loop:
    bge  x7, x6, done     # if i >= n -> done
    addi x8, x7, -1       # j = i-1 (inner loop counter)

inner_loop:
    blt  x8, x0, next     # if j < 0 -> exit inner loop

    add  x9, x5, x8       # &array[j]
    lb   x10, 0(x9)       # array[j]

    addi x11, x8, 1
    add  x12, x5, x11     # &array[j+1]
    lb   x13, 0(x12)      # array[j+1]

    ble  x10, x13, skip_swap  # if array[j] <= array[j+1] -> no swap

    # Swap array[j] and array[j+1]
    sb   x10, 0(x12)      # array[j+1] = array[j]
    sb   x13, 0(x9)       # array[j]   = array[j+1]

skip_swap:
    addi x8, x8, -1       # j--
    j inner_loop

next:
    addi x7, x7, 1        # i++
    j outer_loop

done:
    li   x14, 1
    la   x15, tohost
    sd   x14, 0(x15)      # exit
    nop

.section .data
array: .byte 3,2,1,4,5

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
