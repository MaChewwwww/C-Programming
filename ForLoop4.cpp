#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
    int num;

    pf("Enter a number : ");
    sf("%d", &num);

    while (num > 0) {
        pf("Factors of %d: ", num);

        for (int loop = 1; loop <= num; ++loop) {
            if (num % loop == 0) {
                pf("%d ", loop);
            }
        }

        pf("\n");

        pf("\nEnter a number: ");
        sf("%d", &num);
    }

    pf("Exiting the program! The number you have entered is not positive.\n");

    return 0;
}



