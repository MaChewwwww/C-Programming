#include <stdio.h>

void convert(float amt) {
    int a, b, c, d, e;

    a = amt / 100;      // Amount in pesos
    amt = amt - (a * 100); // Remaining amount in centavos

    b = amt / 25;   // Amount in 25-centavo coins
    amt = amt - (b * 25); // Remaining amount in centavos

    c = amt / 10;   // Amount in 10-centavo coins
    amt = amt - (c * 10); // Remaining amount in centavos

    d = amt / 5;    // Amount in 5-centavo coins
    amt = amt - (d * 5); // Remaining amount in centavos

    e = amt;        // Amount in 1-centavo coins
    amt = amt - (e * 1); // Remaining amount in centavos (should be zero)

    printf("Peso: %d\n", a);
    printf("Centavo (25): %d\n", b);
    printf("Centavo (10): %d\n", c);
    printf("Centavo (5): %d\n", d);
    printf("Centavo (1): %d\n", e);
}

int main() {
    float amount;
    printf("Enter the amount in pesos: ");
    scanf("%f", &amount);
    convert(amount);
    return 0;
}

