#include <stdio.h>

int main() {
    int dividend, divisor;
    int n = 4;   
    printf("Enter dividend:\n");
    scanf("%d", &dividend);
    printf("Enter divisor:\n");
    scanf("%d", &divisor);

    int R = 0;              
    int Q = dividend;       
    int M = divisor;       

    for (int i = 0; i < n; i++) {
       
        R = (R << 1) | ((Q >> (n - 1)) & 1); // left shift R by 1 and make MSB of Q as LSB OF R
        Q = (Q << 1) & ((1 << n) - 1);   // left shift Q 
        R = R - M;

        if (R < 0) {
            
            R = R + M;  // because remainder cannot be negative
        } else {
           
            Q = Q | 1; // if remainder is positive set Q LSB = 1
        }
    }

    printf("Quotient = %d\n", Q);
    printf("Remainder = %d\n", R);

    return 0;
}
// gcc -S task1.c -o task1.s
