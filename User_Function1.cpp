#include <stdio.h>
#include <conio.h>

int calculateFactorial(int number) {
    if (number == 0 || number == 1) {
        return 1;
    } else {
        int product = 1;
        int i = 1;
        while (i <= number) {
            product *= i;
            printf("%d", i);
            i++;
            if (i <= number) {
                printf(" x ");
            }
        }
        printf(" = %d", product);
        return product;
    }
}

int main() {
    int input;

    do {
        printf("\nEnter a number: ");
        scanf("%d", &input);
        if (input == 0) {
            break;
        } else {
            printf("\nFactorial of %d is ", input);
            calculateFactorial(input);
            printf("\n");
        }
    } while (input != 0);

    printf("\nProgram Terminated! Do not enter ZERO.\n");

    return 0;
}

