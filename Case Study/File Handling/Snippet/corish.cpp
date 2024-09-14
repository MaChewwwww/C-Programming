#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Account {
char AccountNumber[10];
char AccountName[100];
int AccountPin;
float Amount;
float AccountBalance;
};

//function of prototypes
void deposit(struct Account *account, float amount);
bool withdraw(struct Account *account, float amount);

int main() {
// Dummy data
struct Account user1 = {"12345", "John Doe", 1234, 500.0, 1500.0};
struct Account user2 = {"98765", "Jane Smith", 5678, 300.0, 2000.0};
struct Account user3 = {"11223", "Alice Johnson", 4321, 1000.0, 5000.0};

// Print table header
printf("| %-10s | %-20s | %-10s | %-10s | %-15s |\n", "Account #", "Account Name", "PIN", "Amount", "Balance");
printf("|------------|--------------|------------|------------|----------|\n");

// Print dummy data
printf("| %-10s | %-20s | %-10d | %-10.2f | %-15.2f |\n", user1.AccountNumber, user1.AccountName, user1.AccountPin, user1.Amount, user1.AccountBalance);
printf("| %-10s | %-20s | %-10d | %-10.2f | %-15.2f |\n", user2.AccountNumber, user2.AccountName, user2.AccountPin, user2.Amount, user2.AccountBalance);
printf("| %-10s | %-20s | %-10d | %-10.2f | %-15.2f |\n", user3.AccountNumber, user3.AccountName, user3.AccountPin, user3.Amount, user3.AccountBalance);

// Transactions
deposit(&user1, 500.0);
withdraw(&user2, 300.0);
withdraw(&user3, 1000.0);

// Updated print of data
printf("\nAfter Transactions:\n");
printf("| %-10s | %-20s | %-10s | %-10s | %-15s |\n", "Account #", "Account Name", "PIN", "Amount", "Balance");
printf("|------------|-----------------|------------|------------------------|\n");
printf("| %-10s | %-20s | %-10d | %-10.2f | %-15.2f |\n", user1.AccountNumber, user1.AccountName, user1.AccountPin, user1.Amount, user1.AccountBalance);
printf("| %-10s | %-20s | %-10d | %-10.2f | %-15.2f |\n", user2.AccountNumber, user2.AccountName, user2.AccountPin, user2.Amount, user2.AccountBalance);
printf("| %-10s | %-20s | %-10d | %-10.2f | %-15.2f |\n", user3.AccountNumber, user3.AccountName, user3.AccountPin, user3.Amount, user3.AccountBalance);

return 0;
}

// Deposit keme keme
void deposit(struct Account *account, float amount) {
account->AccountBalance += amount;
printf("%s Deposited %.2f to account %s. New balance: %.2f\n", account->AccountName, amount, account->AccountNumber, account->AccountBalance);
}
// Withdraw keme keme
bool withdraw(struct Account *account, float amount) {
if (amount > account->AccountBalance) {
printf("Insufficient Amount: %s. Withdrawal denied.\n", account->AccountNumber);
return false;
} else {
account->AccountBalance -= amount;
printf("%s Withdrawn %.f from account %s. New balance: %.2f\n", account->AccountName, amount, account->AccountNumber, account->AccountBalance);
return true;
}
}
