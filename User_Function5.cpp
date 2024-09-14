#include <stdio.h>

int divide(int dividend, int divisor) {
    // Base case: if divisor is 0, return an error code (-1)
    if (divisor == 0) {
        printf("Error: Division by zero\n");
        return -1;
    }

    // Base case: if dividend is less than divisor, return 0
    if (dividend < divisor) {
        return 0;
    }

    // Recursive case: subtract divisor from dividend until dividend is less than divisor
    return 1 + divide(dividend - divisor, divisor);
}

int main() {
    int dividend, divisor;

    while (1) {
        printf("\n");
        printf("Enter the dividend: ");
        scanf("%d", &dividend);

        if (dividend == 0) {
            printf("Do not enter zero as your dividend. Exiting the program.\n");
            break; // Exit the loop if the user enters 0
        }

        printf("Enter the divisor: ");
        scanf("%d", &divisor);

        // Check if the divisor is zero
        if (divisor == 0) {
            printf("Error: Division by zero\n");
            continue; // Skip the rest of the loop and ask for input again
        }

        // Check if the dividend is less than the divisor
        if (dividend < divisor) {
            printf("Error: Dividend is less than divisor\n");
            continue; // Skip the rest of the loop and ask for input again
        }

        int quotient = divide(dividend, divisor);

        printf("%d / %d = %d\n", dividend, divisor, quotient);
    }

    return 0;
}


