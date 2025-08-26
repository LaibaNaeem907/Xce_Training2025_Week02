#include <stdio.h>

int main() {
    int dividend, divisor;
    int n = 4;   

    printf("Enter dividend:\n");
    scanf("%d", &dividend);
    printf("Enter divisor:\n");
    scanf("%d", &divisor);

    int A = 0;              
    int Q = dividend;       
    int M = divisor;        
    

    for (int i = 0; i < n; i++) {
        A = (A << 1) | ((Q >> (n - 1)) & 1);  
        Q = (Q << 1) & ((1 << n) - 1);        


        if (A >= 0)
            A = A - M;
        else
            A = A + M;

        if (A >= 0)
            Q = Q | 1; 
    }

    if (A < 0)
        A = A + M;

    printf("Quotient = %d\n", Q);
    printf("Remainder = %d\n", A);

    return 0;
}
//gcc -S task2.c -o task2.s