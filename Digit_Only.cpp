#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h> // Include the stdlib.h header for atoi
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Odd or Even Categorizer Program\" (Digit Only)");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
    char input[20];

    pf("Enter a value: ");
    sf("%s", input);

    int isOnlyDigits = 1; // Assume it contains only digits

    for (int i = 0; input[i] != '\0'; i++) {
        if (i == 0 && input[i] == '-') {
            continue; // Skip the first character if it's a negative sign
        }
        if (!isdigit(input[i])) {
            isOnlyDigits = 0; // Found a non-digit character
            break;
        }
    }

    if (isOnlyDigits) {
        // Convert the input string to a long integer using strtol
        long value = strtol(input, NULL, 10);

        if (value == 0) {
            pf("The number you entered is ZERO!\n");
        } else if (value % 2 == 0) {
            pf("The number \"%ld\" is an EVEN number.\n", value);
        } else {
            pf("The number \"%ld\" is an ODD number.\n", value);
        }
    } else {
        pf("The entered value contains non-digit characters or is not a valid number.\n");
    }

    return 0;
}
