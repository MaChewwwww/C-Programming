#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
    // Declare an array with 10 elements
    int array[10];

    // Read values into the array
    printf("Please Enter 10 Numbers\n\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter a number (%d): ", i + 1);
        scanf("%d", &array[i]);
    }

    // Bubble Sort to sort the array in ascending order
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap the elements if they are in the wrong order
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Display the sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    // Display the highest and lowest values
    printf("The highest value is: %d\n", array[9]);
    printf("The lowest value is: %d\n", array[0]);

    return 0;
}


