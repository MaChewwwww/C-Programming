#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for an account
struct Account {
    char AccountNumber[10];
    char AccountName[100];
    int AccountPin;
    float Amount;
    float AccountBalance;
};

int main() {
    // Dummy data
    struct Account user1 = {"123456789", "John Doe", 1234, 500.0, 1500.0};
    struct Account user2 = {"987654321", "Jane Smith", 5678, 300.0, 2000.0};
    struct Account user3 = {"112233445", "Alice Johnson", 4321, 1000.0, 5000.0};

    // Print table header
    printf("| %-10s | %-20s | %-10s | %-10s | %-15s |\n", "Account #", "Account Name", "PIN", "Amount", "Balance");
    printf("|------------|----------------------|------------|------------|-----------------|\n");

    // Print dummy data
    printf("| %-10s | %-20s | %-10d | %-10.2f | %-15.2f |\n", user1.AccountNumber, user1.AccountName, user1.AccountPin, user1.Amount, user1.AccountBalance);
    printf("| %-10s | %-20s | %-10d | %-10.2f | %-15.2f |\n", user2.AccountNumber, user2.AccountName, user2.AccountPin, user2.Amount, user2.AccountBalance);
    printf("| %-10s | %-20s | %-10d | %-10.2f | %-15.2f |\n", user3.AccountNumber, user3.AccountName, user3.AccountPin, user3.Amount, user3.AccountBalance);
    
    // Put Transaction Process Here

    return 0;
}

