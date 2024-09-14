#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm *timeinfo;
    char date[11]; // For storing date in the format YYYY-MM-DD
    char time_str[9];  // For storing time in the format HH:MM:SS

    // Get the current time
    time(&rawtime);

    // Convert it to local time representation
    timeinfo = localtime(&rawtime);

    // Format the date and store it in the date array
    strftime(date, sizeof(date), "%Y-%m-%d", timeinfo);

    // Format the time and store it in the time array
    strftime(time_str, sizeof(time_str), "%H:%M:%S", timeinfo);

    // Print the formatted date and time
    printf("Current local date: %s\n", date);
    printf("Current local time: %s\n", time_str);

    return 0;
}

