#include <stdio.h>

int main() {
    int numUsers = 155; // Example number of users
    char str[50];

    for (int i = 1; i <= numUsers; i++) { // Iterate over user IDs from 1 to numUsers
        sprintf(str, "%010d", i); // Format the user ID as a 5-digit string with leading zeros
        printf("User %d ID: %s\n", i, str);
    }

    return 0;
}

