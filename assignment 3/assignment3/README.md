1. Difference Between a Normal Variable and a Pointer
 Normal variable: Stores a value directly (e.g., int x = 7; stores the number 7).
 Pointer: Stores the memory address of another variable (e.g., int *p = &x; stores the address of x).
Memory access:
 Normal variable → accessed directly by name.
 Pointer → accessed indirectly by dereferencing (*p).
Reading and modifying:
 Normal variable → x = 10; changes the value.
 Pointer → *p = 10; changes the value at the address stored in p.

2. Variable vs Pointer Declaration and Definition
 Variable declaration: this step lets the compilerknow that it should allocate some memory for it.
                        int num; → reserves memory for an integer.
 Variable definition: involves assigning an initial value to the variable, int num =10;

 Pointer declaration: States that a variable will hold an address of a certain type.
                      int *ptr;  ptr holds an integer.
 Pointer definition: Assigns it an actual address to store.
                      int num = 20; int *ptr = &num; ptr now stores address of num.
 Operators:
   & → address-of operator (e.g., ptr = &num; stores the address of num).
   * → dereference operator: accesses or modifies the value at the address stored in a pointer.
                             e.g., *ptr = 20;

3. Dereferencing a Pointer
     Dereferencing means accessing the value stored at the memory address a pointer holds.
     Example:
int num = 10;
int *ptr = &num;
printf("%d", *ptr);   // prints 10
*ptr = 20;            // modifies num
printf("%d", num);    // prints 20

4. Scenarios Where Pointers Are Preferred
    Dynamic memory allocation: Managing memory at runtime using malloc/free.
    Function arguments: Passing large structures/arrays efficiently without copying.

5. Limitations and Risks of Pointers
   Dangling pointers: Accessing memory after it’s freed.
   Memory leaks: Forgetting to free allocated memory.
   Complexity: Harder to debug compared to normal variables.

6. Call by Value vs Call by Reference
     Call by value: Function gets a copy of the variable; changes don’t affect the original.
     Call by reference: Function gets the address; changes affect the original variable.
         Example:
         void byValue(int x) { x++; }
         void byReference(int *x) { (*x)++; }
7. Practical Scenarios
     Call by value preferred: When you don’t want the original data modified (e.g., printing values).
     Call by reference preferred: When you want to modify data inside a function (e.g., swapping numbers).
