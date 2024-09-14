#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    // Get the current time
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    
    char firstLetterOfDay = asctime(localTime)[0]; // First letter of the day
    char firstLetterOfMonth = asctime(localTime)[4]; // First letter of the month
    
    char concatenatedStr[9]; // Make sure the array is large enough to hold the result
    strncat(concatenatedStr, &firstLetterOfDay, 1); // Concatenate the first letter of the day
    strncat(concatenatedStr, &firstLetterOfMonth, 1); // Concatenate the first letter of the month
    strcat(concatenatedStr, "202455"); // Concatenate the first letter of the month
    
    // Print the current time
    printf("Current time: %s", asctime(localTime));
    
    printf("Concatenated string: %s\n", concatenatedStr);


    return 0;
}

