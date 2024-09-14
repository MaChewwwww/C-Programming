#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
    int mainArray[10], subsetArray[5];
    int mainSize, subsetSize;

    // Read the size for the main array
    pf("Enter the size for the main array (up to 10): ");
    sf("%d", &mainSize);

    if (mainSize < 1 || mainSize > 10) {
        pf("Error: Invalid size for the main array. Size should be between 1 and 10.\n");
        return 1;
    }

    // Read elements for the main array
    pf("Enter elements for the main array:\n");
    for (int i = 0; i < mainSize; i++) {
        pf("Enter element %d: ", i + 1);
        sf("%d", &mainArray[i]);
    }

    // Read the size for the subset array
    pf("Enter the size for the subset array (up to 5): ");
    sf("%d", &subsetSize);

    if (subsetSize < 1 || subsetSize > 5) {
        pf("Error: Invalid size for the subset array. Size should be between 1 and 5.\n");
        return 1;
    }

    // Read elements for the subset array
    pf("Enter elements for the subset array:\n");
    for (int i = 0; i < subsetSize; i++) {
        pf("Enter element %d: ", i + 1);
        sf("%d", &subsetArray[i]);
    }

    // Check if subsetArray is a subset of mainArray
    int isSubset = 1;  // Assume subset until proven otherwise

    for (int i = 0; i < subsetSize; i++) {
        int found = 0;
        for (int j = 0; j < mainSize; j++) {
            if (subsetArray[i] == mainArray[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            isSubset = 0;
            break;
        }
    }

    // Display the result
    if (isSubset) {
        pf("The second array is a subset of the main array.\n");
    } else {
        pf("The second array is not a subset of the main array.\n");
    }

    return 0;
}

