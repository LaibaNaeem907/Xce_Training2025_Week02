#include <stdio.h>
int main() {
    int set;
    int clear;
    int a,b;
    int result1,result2;
    
    printf("Enter value of a:\n");
    scanf("%d",&a);
    printf("Enter value of b:\n");
    scanf("%d",&b);
    printf("Enter set bit position :\n");
    scanf("%d",&set);
    printf("Enter clear bit position :\n");
    scanf("%d",&clear);

    // Set bit
    result1 = a | (1 << set);

    // Clear bit
    result2 = b & ~(1 << clear);

    printf("Final answer after setting bit = %d\n",result1);
    printf("Final answer after clearing bit = %d\n",result2);

    return 0;
}
//gcc -o task2 task2.c
//gcc -S task2.c -o task2.s