#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
    int burgers = 0, minutes = 0, hours = 0;

    pf("JEMIMAH'S HAMBURGERS DELIVERY\n\n");
    
    pf("| Hour | Minute | Hamburgers |");
    pf("\n|-------|--------|-----------|\n");

    while (burgers < 600) {
        pf("|   %d   |   %d   |   %d   |\n", hours, minutes, burgers);

        minutes = minutes + 2;
        burgers = burgers + 12;

        if (minutes >= 60) {
            hours = hours + minutes / 60;
            minutes = minutes % 60;
        }
    }

    pf("\nGary delivered 600 hamburgers in %d hour/s and %d minutes\n", hours, minutes);

    return 0;
}
