#include <stdio.h>

long int fibo(int n) {
    if (n <= 1) // Base case: if n is 0 or 1, return n
        return n;
    else // Recursive case: calculate Fibonacci of n
        return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int input;
    printf("Enter number of terms : ");
    scanf("%d", &input);
    
    printf("Fibonacci sequence up to F%d:\n", input);
    for (int i = 1; i <= input; i++) {
        printf("F%d = %ld\n", i, fibo(i));
    }
    
    return 0;
}

