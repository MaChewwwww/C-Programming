#include <stdio.h>

int main() {
    int x, a, b, c, d;

    // To ask for an input and store it in the "x" variable
    printf("Enter a four-digit number: ");
    scanf("%d", &x);

    printf("\nOriginal Value: %d", x);

    // Extracting individual digits correctly
    a = x / 1000;
    x = x - (a * 1000);
    b = x / 100;
    x = x - (b * 100);
    c = x / 10;
    x = x - (c * 10);
    d = x;

    printf("\nSwapped Value: %3d %3d %3d %3d", d, c, b, a );

    return 0;
}
