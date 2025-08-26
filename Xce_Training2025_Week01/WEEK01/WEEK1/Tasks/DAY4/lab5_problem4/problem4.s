.section .text
.globl _start
_start:
  la x5, array          # x5 = address of original array
  la x6, rev_array      # x6 = address of reversed array
  li x7, 3              # x7 = index of last element
  li x8, 0              # x8 = index for reversed array

loop:
  blt x7, x0, done      # if index < 0 => exit

  add x9, x5, x7        # x9 = &array[x7]
  lb  x10, 0(x9)        # x10 = array[x7]

  add x11, x6, x8       # x11 = &rev_array[x8]
  sb  x10, 0(x11)       # rev_array[x8] = array[x7]

  addi x7, x7, -1       # x7--
  addi x8, x8, 1        # rev_index++
  j loop

done:
  li x12, 1
  la x13, tohost
  sd x12, 0(x13)
  nop

.section .data
array: .byte 1, 2, 3, 4    # Original array
rev_array: .space 4        # Reversed array will be stored here

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
