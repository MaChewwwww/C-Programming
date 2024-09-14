#include <stdio.h>
#include <conio.h>

int findGCD(int num1, int num2) {
    int max;

    if (num1 > num2)
        max = num1;
    else
        max = num2;

    int i = max;
    while (i > 0) {
        int remainder1 = num1 % i;
        int remainder2 = num2 % i;
        if (remainder1 == 0 && remainder2 == 0)
            break;
        else
            i--;
    }
    return i;
}

int main() {
    int continueProgram = 1;

    do {
        int number1, number2;
        printf("\n\nEnter the first number: ");
        scanf("%d", &number1);
        printf("Enter the second number: ");
        scanf("%d", &number2);

        if (number1 == 0 || number2 == 0) {
            continueProgram = 0;
            printf("\nYou have entered \"0\": PROGRAM TERMINATED!\n");
            break;
        } else {
            printf("Greatest Common Divisor of %d and %d is %d\n", number1, number2, findGCD(number1, number2));
        }
    } while (continueProgram != 0);

    return 0;
}

