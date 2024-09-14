#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
    int decimalNumber;

    // Read an integer from the user
    pf("Enter an integer: ");
    sf("%d", &decimalNumber);

    // Display the original decimal number
    pf("Decimal: %d\n", decimalNumber);

    // Convert to binary
    pf("Binary: ");
    if (decimalNumber == 0) {
        pf("0");
    } else {
        int binary[32]; // Assuming a 32-bit integer
        int i = 0;

        // Convert decimal to binary representation
        while (decimalNumber > 0) {
            binary[i] = decimalNumber % 2;
            decimalNumber = decimalNumber / 2;
            i++;
        }

        // Display the binary representation in reverse order
        for (int j = i - 1; j >= 0; j--) {
            pf("%d", binary[j]);
        }
    }

    pf("\n");

    return 0;
}

