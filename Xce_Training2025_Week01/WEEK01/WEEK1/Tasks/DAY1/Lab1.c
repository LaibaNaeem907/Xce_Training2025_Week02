#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    // Print their sizes and demonstrate type casting
    int a = 10;
    float b = 3.1;
    char c = 'L';
    double d = 3.124;
    printf("Task 1:\n");
    printf(" integer = %d\n",a);
    printf(" float = %f\n",b);
    printf(" character = %c\n",c);
    printf(" double = %f\n",d);
    printf("size of integer = %zu bytes\n",sizeof(a));
    printf("size of float = %zu bytes\n",sizeof(b));
    printf("size of character = %zu bytes\n",sizeof(c));
    printf("size of double = %zu bytes\n",sizeof(d));
    printf("float to double = %f\n",(double)b);
    printf("char to int = %d\n",(int)c);
}

// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    // Perform arithmetic operations
    // Implement switch-case calculator
    printf("\n");
    printf("Task2\n");
    int x,y;
    printf("Enter value of x\n");
    scanf("%d",&x);
    printf("Enter value of y\n");
    scanf("%d",&y);
    char operation;
    printf("x + y = %d\n",x + y);
    printf("x - y = %d\n",x - y);
    printf("x * y = %d\n",x * y);
    printf("x / y = %d\n", x/y);
    printf("x %% y = %d\n", x%y);
    printf("Enter operation:");
    scanf(" %c",&operation);
    switch(operation) {
    case '+':
     printf("x + y = %d\n",x + y);
    break;
    case '-':
     printf("x - y = %d\n",x - y);
    break;
    case '*':
     printf("x * y = %d\n",x * y);
    break;
    case '/':
     printf("x / y = %d\n", x/y);
    break;
    case '%':
     printf("x %% y = %d\n", x%y);
    break;
}
}
// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
   int number;
   int x = 0;
   int y = 1;
   int z;
   printf("\n");
   printf("Task 3 : Fibonacci Sequence\n");
   printf("Enter number:");
   scanf("%d",&number);
   for ( int i = 0; i<number; i++){
    printf("%d\n",x);
    z = x + y;
    x = y;
    y = z;
}
}

void task03_guessing_game() {
   // TODO: Implement guessing game with random number
   printf("\n");
   printf("Task 3: Guessing Game\n");
   int guess;
   int number = (rand()%100)+1;
   printf("Random Number= %d\n",number);
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess > number) {
            printf("Too High\n");
        } else if (guess < number) {
            printf("Too Low\n");
        } else {
            printf("Correct\n");
        }
    } while (guess != number);
}

int isPrime(int n) {

    if (n <= 1) 
      return 0;      

    for (int i = 2; i*i<= n; i++) {
        if (n % i == 0) return 0;  
    }

    return 1;  
}

int factorial(int n) {
    if (n == 0) {
        return 1;  
    }
    return n * factorial(n - 1);  
}

void task_factorial() {
    int n;
    printf("\n");
    printf("Task 4:Factorial\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = factorial(n);
    printf("factorial of %d = %d\n", n, result);
}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    printf("\n");
    printf("Task 4: Prime numbers from 1 to 100\n");
    for (int n = 2; n <= 100; n++) {
        if (isPrime(n)) {
            printf("%d\n ", n);
        }
    }
}
// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char string[100];
    printf("Task 5\n");
    printf("Enter String:\n");
    scanf("%[^\n]",string);
    for (int i = strlen(string)-1; i>=0; i--) {
        printf("%c",string[i]);
}
     printf("\n");
}
void task05_second_largest() {
    // TODO: Find the second largest element in an array
    
     int array[] = {1, 2, 3, 4, 5};
int n = sizeof(array) / sizeof(array[0]);

// Sort array in descending order 
for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
        if (array[j] < array[j+1]) {
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
}

printf("Second largest element is: %d\n", array[1]);

    
}
// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
     FILE *fp;
    int arr[5];
    int i;

    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    
    fp = fopen("numbers.txt", "w");  
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (i = 0; i < 5; i++) {
        fprintf(fp, "%d ", arr[i]);  
    }
    fclose(fp);
    printf("Numbers written to file successfully!\n");

   
    fp = fopen("numbers.txt", "r");  
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    printf("Numbers read from file:\n");
    int num;
    while (fscanf(fp, "%d", &num) == 1) {
        printf("%d\n ", num);  
    }

    fclose(fp);
}
int poweroftwo (int i) {
 if (i<=0) {
    return 0;
}
   return (i & (i-1)) == 0;
}
// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    printf("Task 7\n");
    int a = 5;
    int b = 9;
    int j = 16;
    printf(" a & b = %d\n",a&b);
    printf(" a | b = %d\n",a|b);
    printf(" a ^ b = %d\n",a^b);
    printf(" ~a = %d\n",~a);
    printf(" ~b = %d\n",~b);
    printf(" a << 1 = %d\n", a <<1);
    printf(" b << 1 = %d\n",b <<1);
    if (poweroftwo( j )) {
      printf("Number is power of 2\n");
}
   else {
   printf("Number is not power of 2\n");
}

}


// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    printf("Task 8\n");
    enum weekdays {MON = 1, TUE = 2, WED = 3, THURS = 4 ,FRI = 5, SAT = 6, SUN = 7};
    printf("Enter number\n");
    int i;
    scanf("%d",&i);
    switch(i) {
    case MON:
      printf("Monday\n");
      break;
    case TUE:
    printf("Tuesday\n");
     break;
    case WED:
       printf("Wednesday\n");
       break;
    case THURS:
       printf("Thursday\n");
       break;
    case FRI:
       printf("Friday\n");
       break;
    case SAT:
       printf("Saturday\n");
       break;
    case SUN:
       printf("Sunday\n");
}
}
struct Point {
    int x;
    int y;
};
void task09_struct_distance() {
  // TODO: Take two points and calculate Euclidean distance
  struct Point x1,x2;
  float distance;
    printf("Enter x1,y1 ");
    scanf("%d %d", &x1.x, &x1.y);

    printf("Enter x2,y2 ");
    scanf("%d %d", &x2.x, &x2.y);

    distance = sqrt((x2.x - x1.x) * (x2.x - x1.x) +
                    (x2.y - x1.y) * (x2.y - x1.y));

    printf("Euclidean distance  = %f\n", distance);
}
// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);


    int sum = num1 + num2;

    printf("Sum = %d\n", sum);
}
// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    // Uncomment tasks as you implement them
    //task01_datatypes();
    // task02_calculator();
    // task03_fibonacci();
    // task03_guessing_game();
    // task04_prime_numbers();
    // task_factorial();
    // task05_reverse_string();
     task05_second_largest();
    // task06_file_io();
    // task07_bitwise_ops();
    // task08_enum_weekday();
    // task09_struct_distance();
    // task10_cmd_args(argc, argv);

    return 0;
}
