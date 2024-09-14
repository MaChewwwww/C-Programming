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

// Transaction Process
char enteredAccountNumber[10];
int enteredPIN;
printf("\nEnter your account number: ");
scanf("%s", enteredAccountNumber);
printf("Enter your PIN: ");
scanf("%d", &enteredPIN);

// Validate PIN
bool validPIN = false;
struct Account *selectedAccount = NULL;
if (strcmp(enteredAccountNumber, user1.AccountNumber) == 0 && enteredPIN == user1.AccountPin) {
validPIN = true;
selectedAccount = &user1;
} else if (strcmp(enteredAccountNumber, user2.AccountNumber) == 0 && enteredPIN == user2.AccountPin) {
validPIN = true;
selectedAccount = &user2;
} else if (strcmp(enteredAccountNumber, user3.AccountNumber) == 0 && enteredPIN == user3.AccountPin) {
validPIN = true;
selectedAccount = &user3;
}

if (validPIN) {
printf("VALID PIN! The account belongs to %s.\n", selectedAccount->AccountName);

// Transaction processing II
char transactionType;
printf("Choose transaction type (B for balance inquiry, D for deposit, W for withdrawal): ");
scanf(" %c", &transactionType);

switch (transactionType) {
case 'B':
printf("Current balance: %.2f\n", selectedAccount->AccountBalance);
break;
case 'D':
{
float depositAmount;
printf("Enter deposit amount: ");
scanf("%f", &depositAmount);
selectedAccount->AccountBalance += depositAmount;
printf("New balance: %.2f\n", selectedAccount->AccountBalance);
}
break;
case 'W':
{
float withdrawalAmount;
printf("Enter withdrawal amount: ");
scanf("%f", &withdrawalAmount);
if (withdrawalAmount > selectedAccount->AccountBalance) {
printf("Not enough funds. Transaction not allowed.\n");
} else {
selectedAccount->AccountBalance -= withdrawalAmount;
printf("New balance: %.2f\n", selectedAccount->AccountBalance);
}
}
break;
default:
printf("Invalid transaction type.\n");
}
} else {
printf("INVALID PIN! Access denied.\n");
}

return 0;
}
