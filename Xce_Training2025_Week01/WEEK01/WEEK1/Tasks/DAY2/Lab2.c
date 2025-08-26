#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    // Print value using direct and pointer
    int x = 5;
    int *ptr = &x;
    printf("value of x = %d\n",x);
    printf("value of x using pointer = %d\n",*ptr);
    //printf("value of x using pointer = %p\n",ptr);
    //printf("value of x using pointer = %p\n",&x);
    // Modify via pointer and print new value
    *ptr = 100;
    printf("Modified value of x = %d\n",x);
    printf("Modified value of x  with pointer = %d\n",*ptr);
    
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
     printf("value of a before swapping = %d\n",*a);
     printf("value of b before swapping = %d\n",*b);
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("value of a after swapping = %d\n",*a);
    printf("value of b after swapping = %d\n",*b);
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    int arr[] = {1,2,3,4,5,6,7};
    int sum = 0;
    // Print all elements using pointers
    int *ptr = arr;
    int enteries = sizeof(arr)/sizeof(int);
    for (int i = 0; i < enteries; i++) {
       printf("enteries of array = %d\n",*(ptr));
       sum += *ptr;
       ptr++;
       
}
    // Calculate sum
    printf("sum of all enteries = %d\n",sum);

    // Reverse in place
    ptr = arr;
    int temp;
    int *start = arr;
    int *end = arr + enteries - 1;
    while ( start < end ) {
        temp = *start;
        *start = *end;
        *end = temp;
       start++;
       end--;
      
}
    printf("Reverse array is\n");
    for (int i = 0; i < enteries; i++) {
       printf("enteries of array = %d\n",*(ptr));
       ptr++;
}
}
// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int counter = 0;
    while (*s != '\0') {
      counter = counter+1;
      s++;
}
    return counter;
}

void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;  // copy character
        src++;         // move source pointer
        dest++;       
    }
    *dest = '\0';     
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    int counter1 = 0;
    int counter2 = 0;
    while (*s1 != '\0') {
         counter1 = counter1 + 1;
         s1++;
}
    while (*s2 != '\0') {
         counter2 = counter2 + 1;
         s2++;
}
   if (counter1 - counter2 == 0)
     {
      return 0;
}
  else if ( counter1 > counter2 ) {

    return 1;
}
   else if ( counter1 < counter2 ) {

    return -1;
}
}
// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
   const char *start = s;
   const char *end = s + strlen(s) - 1;
   while(start<end) {
    if (tolower(*start) != tolower(*end)){
			return 0;
     }
	start++;
	end--;
     }
  return 1;
}


// ======================= Part 3: Preprocessor & File I/O =======================

#define SQUARE(x) ((x)*(x))
#define MAX2(a,b) ((a) > (b) ? (a) : (b))
#define MAX3(a,b,c) (MAX2(MAX2(a,b), c))
#define MAX4(a,b,c,d) (MAX2(MAX2(MAX2(a,b), c), d))
#define TO_UPPER(c) ((c) >= 'a' && (c) <= 'z' ? ((c) - 32) : (c))

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
}

// Student struct
struct Student {
    char name[50];
    int roll;
    float gpa;
};

// Task 3.2: File I/O
void task3_2_fileio() {
    // TODO: Input 5 students
    struct Student s1[5] = {{"A",7,3.4},
                         {"B",2,3.5},
                         {"C",4,3.1},
                         {"D",6,3.7},
                         {"E",9,1.9}}; 
    // Print student with highest GPA
    int i,j=0;
    for ( i = 1; i < 5; i++) {
       if (s1[i].gpa > s1[j].gpa ) {
            j = i;
      }
   }
   printf("student wit highest gpa is %s\n",s1[j].name);
    // Save to "students.txt"
    FILE *fp = fopen("students.txt","w");
    if (fp == NULL) {
     printf("File is empty\n");
    }
    for (int k = 0; k<5; k++) {
       fprintf(fp,"%s %d %.2f\n",s1[k].name,s1[k].roll,s1[k].gpa); 
}
    fclose(fp);
    printf("done\n");

    // Read back and print
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char name[50];
    int roll;
    float gpa;

    printf("Reading back from file\n");
    while (fscanf(fp, "%s %d %f", name, &roll, &gpa) == 3) {
        printf("%s %d %f\n", name, roll, gpa);
    }

    fclose(fp);
}
// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning 
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data= value;
    newnode -> next= head;
    head = newnode ;
    return head;
    
}

struct Node* delete_value(struct Node *head, int value) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Node found\n");
                prev->next = temp->next;
            }

        else if (temp->data == value && temp->next == NULL) {
            printf("Node found\n");
   
                head = NULL;
            }
       
   
        else if (temp->data == value && prev == NULL) {
            printf("Node found\n");
            temp = temp -> next;
        }

        prev = temp;
        temp = temp -> next;

}
    return head;
}


void print_list(struct Node *head) {
    // TODO: Print linked list
      struct Node *temp = head;
     while (temp != NULL ) {
     printf("linked list is %d\n",temp->data);
     temp = temp->next;
}
}
void task4_1_linkedlist() {
    struct Node *head = NULL;         
    head = insert_begin(head, 10);  
    head = insert_begin(head, 20);    
    head = insert_begin(head, 30);
    head = insert_begin(head, 40);   
    head = delete_value(head,20);
    head = delete_value(head,30);
    print_list(head); 
}


// ======================= Part 5: Dynamic Memory Allocation =======================

void task5_1_dynamic_array() {
    int n, i;
    int sum = 0;
    float average;

    printf("Enter total numbers: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", (arr+i));
    }

 
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }


    average = (float)sum / n;
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f\n", average);
    free(arr);
}


void task5_2_realloc_array() {
    int entries = 5;
    int *arr = (int*) malloc(entries * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    for(int i=0; i<entries; i++)
        arr[i] = i+1;   // 1,2,3,4,5

    int n = 7;
    arr = (int*) realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        printf("Reallocation failed!\n");
        return;
    }

    
    arr[5] = 3;
    arr[6] = 5;

    for (int i=0; i<n; i++)
        printf("%d\n", arr[i]);
    printf("done\n");
    free(arr);
}


#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    if (allocated_count >= MAX_PTRS) {
        printf("Cannot track more pointers!\n");
        return NULL;
    }
    
    void* ptr = malloc(size);         
    if (ptr != NULL) {
        allocated_ptrs[allocated_count++] = ptr;   
    }
    return ptr;
}

void my_free(void* ptr) {
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
           
            for (int j = i; j < allocated_count - 1; j++)
                allocated_ptrs[j] = allocated_ptrs[j+1];
            allocated_count--;
            free(ptr);   
            return;
        }
    }
    printf("Pointer not found!\n");
}


void check_leaks() {
    if (allocated_count == 0) {
        printf("No memory leaks detected.\n");
    } else {
        printf("Memory leaks detected for %d pointer(s):\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf("  Leak at address: %p\n", allocated_ptrs[i]);
        }
    }
}

// ======================= Final Task: Booth's Multiplication =======================

// Bitwise addition (without '+')
int sum(int a, int b) {
    while (b != 0) {
        unsigned carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}


long long booth_multiply(int M, int Q) {
    int A = 0;
    int Q_1 = 0;
    int n = 32;

    for (int i = 0; i < n; i++) {
        int Q0 = Q & 1;

        // Booth decision
        if (Q0 == 1 && Q_1 == 0)
            A = sum(A, -M);
        else if (Q0 == 0 && Q_1 == 1)
            A = sum(A, M);

        
        int new_Q1 = Q & 1;
        // combine A and Q into one 64-bit value to simplify shifting
        long long combined = ((long long)A << 32) | ((unsigned)Q);
        combined >>= 1; // arithmetic shift: sign preserved
        A = (int)(combined >> 32); //extracted A
        Q = (int)(combined & 0xFFFFFFFF); // extracted Q
        Q_1 = new_Q1;
    }

    return ((long long)A << 32) | ((unsigned)Q);
}

// Test
void test_booth() {
    printf(" 5 *  3 = %lld\n", booth_multiply(5, 3));
    printf(" 5 * -3 = %lld\n", booth_multiply(5, -3));
    printf("-5 *  3 = %lld\n", booth_multiply(-5, 3));
    printf("-5 * -3 = %lld\n", booth_multiply(-5, -3));
}
// ======================= Main =======================
int main() {
    // Uncomment and run tasks as you implement

    // --- Part 1 ---
           // task1_1();
    //int a=5, b=10; swap(&a,&b);
    // task1_3();

    // --- Part 2 ---
    //printf("Len = %d\n", my_strlen("Hello"));
    //char buf[100]; 
    //my_strcpy(buf,"World");
    //printf("Copied: %s\n", buf);
    //char arr1[100] = "Hello";
    //char arr2[45] = "worlddd";
    //printf("output = %d\n", my_strcmp(arr1,arr2));
    //printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");

    // --- Part 3 ---
    //printf("SQUARE(5) = %d\n", SQUARE(5));
    //printf("MAX2(3,7) = %d\n", MAX2(3,7));
    //printf("MAX3(3,7,5) = %d\n", MAX3(3,7,5));
    //printf("MAX4(3,7,5,10) = %d\n", MAX4(3,7,5,10));
    char ch1 = 'g';
    char ch2 = 'A';

    //printf("%c to %c\n", ch1, TO_UPPER(ch1)); 
    //printf("%c to %c\n", ch2, TO_UPPER(ch2));

    // task3_1_macros();
    //task3_2_fileio();

    // --- Part 4 ---
    //task4_1_linkedlist();

    // --- Part 5 ---
    //task5_1_dynamic_array();
    //task5_2_realloc_array();
    //int *a = (int*) my_malloc(sizeof(int));
    //int *b = (int*) my_malloc(sizeof(int));

   // *a = 10;
    //*b = 20;

    //my_free(a);       

    //check_leaks();    

    // --- Final Task ---
    test_booth();

    return 0;
}
