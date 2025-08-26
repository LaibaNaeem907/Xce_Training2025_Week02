.global _start
.section .text
_start:
   
    li x1, 3          # num_set 
    li x2, 4          # num_clear
    li x3, 1          # bit_set 
    li x4, 0         # bit_clear 

    # Set bit operation

    # Set bit
    # result = num_set | (1 << bit_set);       
    slli x5, x3, 1    
    or x6, x1, x5  

    # Clear bit operation


    # Clear bit
   # result = num_clear & ~(1 << bit_clear);

    slli x7, x4, 1 
    not x7, x7      
    and x9, x2, x7  

exit:
     # x6 = set  result
     # x9 = clear result
    la x10,result1
    la x11,result2
    sw x6, 0(x10)
    sw x9, 0(x11)

    li x5, 1         
    la x6, tohost      
    sd x5, 0(x6)
    nop

.section .data

result1:   .word 0      
result2:  .word 0  

.section .tohost
.align 3
tohost:     .dword 0
fromhost:   .dword 0
