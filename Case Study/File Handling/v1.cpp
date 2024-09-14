#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <ctype.h>

// Structure for a pending user
struct PendingUser{
    int AccountNumber;
    char FirstName[50];
    char LastName[50];
    char AccountPassword[50];
    int AccountPin;
    float AccountBalance;
};


// Structure for a denied user
struct DeniedUser{
    int AccountNumber;
    char FirstName[50];
    char LastName[50];
    char AccountPassword[50];
    int AccountPin;
    float AccountBalance;
};

// Structure for a registered user
struct RegisteredUser{
    int AccountNumber;
    char FirstName[50];
    char LastName[50];
    char AccountPassword[50];
    int AccountPin;
    int Attempts;
    float AccountBalance;
};

// Structure for a transactions
struct TransactionData{
    int AccountNumber;
    char FirstName[50];
    char LastName[50];
    char TransactionCode[2];
    float Amount;
};

// Functions to be used (Prototyping)
void AdminMenu();
void RegisterUser();
void LoginUser();
void ApprovePendingUser();
void DenyPendingUser();
void ListRegisteredUser();
void ListTransact();
int Transaction(int AccountNumber, int EnteredPin);

int main() {
	
    int choice;

    while (1) {
        system("cls");
        printf("Welcome to the Bank\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Admin\n");
        printf("4. Exit\n");  

        printf("\nSelect a Choice: ");

        if (scanf("%d", &choice) != 1) {
            // Clear invalid input from the buffer
            while (getchar() != '\n');
            printf("\nChoice Error: Please input a valid number!\n");
            getch(); // Wait for user input before clearing the screen
            continue; // Skip to the next iteration
        }

        if (choice == 1) {
            LoginUser();
        } else if (choice == 2) {
            RegisterUser();
        } else if (choice == 3) {
            AdminMenu();
        } else if (choice == 4) {
            break;
        } else {
            printf("\nChoice Error: Please input a valid number!\n");
            getch(); // Wait for user input before clearing the screen
        }
    }

    return 0;
}


void AdminMenu() {
	
	char choice[50];
    int choice2;

    while (1) { // Infinite loop until correct password is entered or 'x' is entered
        printf("\nEnter Admin Passcode ('x' to exit): ");
        scanf("%s", choice);

        if (strcmp(choice, "pass12345") == 0) {
            printf("Admin Menu\n");
            printf("1. Approve Pending User\n");
            printf("2. Deny Pending User\n");
            printf("3. List Registered User\n");
            printf("4. List of all Transactions\n");
            printf("\nSelect a Choice: ");
            scanf("%d", &choice2);

            if (choice2 == 1)
                ApprovePendingUser();
            else if (choice2 == 2)
                DenyPendingUser();
            else if (choice2 == 3)
            	ListRegisteredUser();
            else if (choice2 == 4)
            	ListTransact();
            else
                printf("Invalid choice. Returning to main menu...\n");

            break; // Exit the loop after successful login
        } else if (strcmp(choice, "x") == 0) {
            printf("Exiting...\n");
            getch();
            break;
        } else {
            printf("Wrong password. Try again.\n");
        }
    }
    
}

void RegisterUser() {
    struct RegisteredUser existingUser;
    struct PendingUser newUser;
    char enteredFirstName[50];
    char enteredLastName[50];

    FILE *p_userFile;
    FILE *userFile;
    bool accountExists = false; // Flag to indicate if account number exists

    system("cls");

    // Open the users file in read/write mode to check existing accounts, and create it if it doesn't exist
    userFile = fopen("users.dat", "a+b");
    if (userFile == NULL) {
        printf("Error opening users file!\n");
        getch();
        return;
    }

    // Open the pending users file in append mode, and create it if it doesn't exist
    p_userFile = fopen("pending_users.dat", "a+b");
    if (p_userFile == NULL) {
        printf("Error opening pending users file!\n");
        fclose(userFile);
        getch();
        return;
    }

    int EnteredNumber;
    printf("Registration Menu\n\n");
    printf("Enter Account Number: ");
    scanf("%d", &EnteredNumber);

    // Check if the account number already exists in pending_users.dat
    rewind(p_userFile); // Reset file position indicator to the beginning
    while (fread(&newUser, sizeof(struct PendingUser), 1, p_userFile)) {
        if (newUser.AccountNumber == EnteredNumber) {
            accountExists = true;
            break;
        }
    }

    // Check if the account number already exists in users.dat
    rewind(userFile); // Reset file position indicator to the beginning
    while (fread(&existingUser, sizeof(struct RegisteredUser), 1, userFile)) {
        if (existingUser.AccountNumber == EnteredNumber) {
            accountExists = true;
            break;
        }
    }

    if (accountExists) {
        printf("Account number already exists. Registration failed.\n");
    } else {
        // Proceed with registration if the account number is unique and write the new user to pending_users.dat
        printf("\nEnter First Name: ");
        scanf(" %[^\n]", &enteredFirstName); // Use space before %[^\n] to discard leading whitespace
        strcpy(newUser.FirstName, enteredFirstName);

        printf("Enter Last Name: ");
        scanf(" %[^\n]", &enteredLastName);
        strcpy(newUser.LastName, enteredLastName);

        printf("Enter Account Password: ");
        scanf("%s", newUser.AccountPassword);

        printf("Enter Account Pin: ");
        scanf("%d", &newUser.AccountPin);

        printf("Enter Initial Deposit: ");
        scanf("%f", &newUser.AccountBalance);

        newUser.AccountNumber = EnteredNumber;

        printf("User registration pending approval!\n");
        
        getch();

        // Write the new user to pending_users.dat
        fwrite(&newUser, sizeof(struct PendingUser), 1, p_userFile);
    }

    // Close the files
    fclose(p_userFile);
    fclose(userFile);
}

void LoginUser() {
    struct RegisteredUser user;
    FILE *userFile;
    int accountNumber, enteredPin;
    char enteredPassword[50];
    int checkpass = 0;
    int checkpin = 0;
    int foundUser = 0;

    // Open the file in read/write mode
    userFile = fopen("users.dat", "r+b");
    if (userFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Login Menu\n");
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    while (checkpass == 0) {
        printf("Enter Password: ");
        scanf("%s", enteredPassword);

        // Read the file to verify the password 
        rewind(userFile); // Reset file position indicator to the beginning
        while (fread(&user, sizeof(struct RegisteredUser), 1, userFile)) {
            if (user.AccountNumber == accountNumber) {
                foundUser = 1;
                if (strcmp(user.AccountPassword, enteredPassword) == 0) {
                    checkpass = 1;
                }
                break;
            }
        }
        if (checkpass == 0) {
            if (foundUser == 1) {
                printf("Invalid Password!\n");
            } else {
                printf("Account not found!\n");
                fclose(userFile);
                return;
            }
        }
    }

    while (checkpin == 0) {
    	
    	if (user.Attempts >= 3) {
                printf("Card is captured! Please visit your bank branch to retrieve your card.\n");
                getch();
                return;
        }
    	
    	
        printf("Enter Pin: ");
        scanf("%d", &enteredPin);

        if (user.AccountPin == enteredPin && user.Attempts<3) {
            checkpin = 1;
            user.Attempts = 0;
            // Move the file pointer back to the current record position
            fseek(userFile, -sizeof(struct RegisteredUser), SEEK_CUR);
            // Update the record in the file
            fwrite(&user, sizeof(struct RegisteredUser), 1, userFile);
            fflush(userFile); // Ensure the write operation is completed
            
            // Call Transaction function and handle exit
            int transactionResult = Transaction(accountNumber, enteredPin);
            if (transactionResult == 0) {
                // Transaction ended, return to stop further execution
                fclose(userFile);
                return;
            }
        } else {
            user.Attempts +=1;
            printf("Invalid Pin!\n");
            printf("Attempt %d/3!\n", user.Attempts);
            
            // Move the file pointer back to the current record position
            fseek(userFile, -sizeof(struct RegisteredUser), SEEK_CUR);
            // Update the record in the file
            fwrite(&user, sizeof(struct RegisteredUser), 1, userFile);
            fflush(userFile); // Ensure the write operation is completed

        }
    }
    
    getch();
    fclose(userFile);

    if (checkpass == 1 && checkpin == 1) {
        printf("Login successful!\n");
        printf("Welcome, %s\n", user.FirstName);
        getch();
    }
}


void ApprovePendingUser() {
    FILE *p_userFile, *userFile, *tempFile;
    int accountNumber;
    char choice;
    char TempName[100];
    char TempLastName[50];

    do {
        struct PendingUser pendingUser;
        struct RegisteredUser newUser;
        int found = 0;
        system("cls");

        // Open the files and create if it doesn't exist
        p_userFile = fopen("pending_users.dat", "rb");
        userFile = fopen("users.dat", "ab");

        if (p_userFile == NULL || userFile == NULL) {
            printf("Error opening file!\n");
            return;
        }

        // Display pending users
        printf("Contents of pending_users.dat:\n");
        while (fread(&pendingUser, sizeof(struct PendingUser), 1, p_userFile)) {
            printf("Account Number: %d\n", pendingUser.AccountNumber);
            
			strcpy(TempName, pendingUser.FirstName);
			strcpy(TempLastName, pendingUser.LastName);
    		strcat(TempName, " ");
    		strcat(TempName, TempLastName);
        
            printf("Name: %s\n", TempName);
            // Print other fields if needed
            printf("\n");
        }

        rewind(p_userFile); // Reset file pointer position to the beginning

        printf("Enter Account Number to Approve: ");
        scanf("%d", &accountNumber);

        // Read pending users and transfer the approved one to registered users
        tempFile = fopen("temp.dat", "wb");
        while (fread(&pendingUser, sizeof(struct PendingUser), 1, p_userFile)) {
            if (pendingUser.AccountNumber == accountNumber) {
                found = 1;
                newUser.AccountNumber = pendingUser.AccountNumber;
                strcpy(newUser.FirstName, pendingUser.FirstName);
                strcpy(newUser.LastName, pendingUser.LastName);
                strcpy(newUser.AccountPassword, pendingUser.AccountPassword);
                newUser.AccountPin = pendingUser.AccountPin;
                newUser.AccountBalance = pendingUser.AccountBalance;
                newUser.Attempts = 0;
                fwrite(&newUser, sizeof(struct RegisteredUser), 1, userFile);
            } else {
                fwrite(&pendingUser, sizeof(struct PendingUser), 1, tempFile);
            }
        }

        fclose(p_userFile);
        fclose(userFile);
        fclose(tempFile);

        // Delete the original pending_users.dat file and rename the temp file to pending_users.dat
        remove("pending_users.dat");
        rename("temp.dat", "pending_users.dat");

        if (found == 1)
            printf("User approved successfully!\n");
        else
            printf("Account number not found!\n");

        printf("Do you want to approve another user? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character

    } while (choice == 'y' || choice == 'Y');

    getch();
}

void DenyPendingUser() {
    FILE *p_userFile, *deniedFile, *tempFile;
    int accountNumber;
    char choice;
    char TempName[100];
    char TempLastName[50];

    do {
        struct PendingUser pendingUser;
        struct DeniedUser deniedUser;
        int found = 0;
        system("cls");

        // Open the files
        p_userFile = fopen("pending_users.dat", "rb");
        deniedFile = fopen("denied_users.dat", "ab");

        if (p_userFile == NULL || deniedFile == NULL) {
            printf("Error opening file!\n");
            return;
        }

        // Display pending users
        printf("Contents of pending_users.dat:\n");
        while (fread(&pendingUser, sizeof(struct PendingUser), 1, p_userFile)) {
            printf("Account Number: %d\n", pendingUser.AccountNumber);
            
            strcpy(TempName, pendingUser.FirstName);
			strcpy(TempLastName, pendingUser.LastName);
    		strcat(TempName, " ");
    		strcat(TempName, TempLastName);
    		
            printf("Name: %s\n", TempName);
            
            // Print other fields if needed
            printf("\n");
        }

        rewind(p_userFile); // Reset file pointer position to the beginning

        printf("Enter Account Number to Deny: ");
        scanf("%d", &accountNumber);

        // Read pending users and transfer the denied one to denied users
        tempFile = fopen("temp.dat", "wb");
        while (fread(&pendingUser, sizeof(struct PendingUser), 1, p_userFile)) {
            if (pendingUser.AccountNumber == accountNumber) {
                found = 1;
                deniedUser.AccountNumber = pendingUser.AccountNumber;
                strcpy(deniedUser.FirstName, pendingUser.FirstName);
                strcpy(deniedUser.LastName, pendingUser.LastName);
                strcpy(deniedUser.AccountPassword, pendingUser.AccountPassword);
                deniedUser.AccountPin = pendingUser.AccountPin;
                deniedUser.AccountBalance = pendingUser.AccountBalance;
                fwrite(&deniedUser, sizeof(struct DeniedUser), 1, deniedFile);
            } else {
                fwrite(&pendingUser, sizeof(struct PendingUser), 1, tempFile);
            }
        }

        fclose(p_userFile);
        fclose(deniedFile);
        fclose(tempFile);

        // Delete the original pending_users.dat file and rename the temp file to pending_users.dat
        remove("pending_users.dat");
        rename("temp.dat", "pending_users.dat");

        if (found == 1)
            printf("User denied successfully!\n");
        else
            printf("Account number not found!\n");

        printf("Do you want to deny another user? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character

    } while (choice == 'y' || choice == 'Y');

    getch();
}

void ListRegisteredUser() {
    FILE *userFile;
    struct RegisteredUser user;

    // Open the users file in read mode
    userFile = fopen("users.dat", "rb");
    if (userFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Print header
    printf("Registered Users:\n");
    printf("------------------------------------------------------------\n");
    printf("| %-20s | %-25s | %-15s | %-10s | %-15s | %-5s |\n", "Account Number", "Name", "Password", "PIN", "Balance", "Attempt");
    printf("------------------------------------------------------------\n");

    // Read and print each registered user
    while (fread(&user, sizeof(struct RegisteredUser), 1, userFile)) {
        printf("| %20d | %25s | %15s | %10d | %15.2f | %5d |\n", user.AccountNumber, user.FirstName, user.AccountPassword, user.AccountPin, user.AccountBalance, user.Attempts);
    }
    fclose(userFile);
    
    getch();
}

int Transaction(int AccountNumber, int EnteredPin) {
    struct RegisteredUser user;
    struct TransactionData transaction;
    FILE *userFile;
    FILE *transFile;
    int choice = 0;
    int quit = 0;
    float amount;
    bool foundUser = false;

    // Open the users file in read/write mode
    userFile = fopen("users.dat", "r+b");
    if (userFile == NULL) {
        printf("Error opening users file!\n");
        return -1;
    }

    // Open the transactions file in append mode, and create it if it doesn't exist
    transFile = fopen("transactions.dat", "a+b");
    if (transFile == NULL) {
        printf("Error opening transactions file!\n");
        fclose(userFile);
        return -1;
    }

    // Find the user in the file
    while (fread(&user, sizeof(struct RegisteredUser), 1, userFile)) {
        if (user.AccountNumber == AccountNumber && user.AccountPin == EnteredPin) {
            foundUser = true;
            break;
        }
    }

    if (!foundUser) {
        printf("Account not found!\n");
        fclose(userFile);
        fclose(transFile);
        return -1;
    }
    
    while(quit == 0) {
        system("cls");
        printf("Welcome %s!\n\n", user.FirstName);
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Balance Inquiry\n");
        printf("4. Transaction History\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        float TotalDeposit = 0, TotalWithdrawal = 0;
        
        while (fread(&transaction, sizeof(struct TransactionData), 1, transFile)) {
			if (user.AccountNumber == AccountNumber && (strcmp(transaction.TransactionCode, "D") == 0))
				    TotalDeposit += transaction.Amount;
			else if (user.AccountNumber == AccountNumber && (strcmp(transaction.TransactionCode, "W") == 0))
				    TotalWithdrawal += transaction.Amount;
		}

        switch (choice) {
            case 1: // Deposit
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                user.AccountBalance += amount;
                printf("Deposit successful! New balance: %.2f\n", user.AccountBalance);

                // Record the transaction
                transaction.AccountNumber = user.AccountNumber;
                strcpy(transaction.FirstName, user.FirstName);
                strcpy(transaction.LastName, user.LastName);
                strcpy(transaction.TransactionCode, "D"); // 'D' for Deposit
                transaction.Amount = amount;
                fwrite(&transaction, sizeof(struct TransactionData), 1, transFile);

                // Update the user's balance in the file
                fseek(userFile, -sizeof(struct RegisteredUser), SEEK_CUR);
                fwrite(&user, sizeof(struct RegisteredUser), 1, userFile);
                fflush(userFile); // Ensure the write operation is completed
                break;

            case 2: // Withdraw
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                
			    
                if (TotalDeposit < amount) {
                    printf("Insufficient funds!\n");
                } else {
                    user.AccountBalance -= amount;
                    printf("Withdrawal successful! New balance: %.2f\n", user.AccountBalance);

                    // Record the transaction
                    transaction.AccountNumber = user.AccountNumber;
                    strcpy(transaction.FirstName, user.FirstName);
                    strcpy(transaction.LastName, user.LastName);
                    strcpy(transaction.TransactionCode, "W"); // 'W' for Withdraw
                    transaction.Amount = amount;
                    fwrite(&transaction, sizeof(struct TransactionData), 1, transFile);

                    // Update the user's balance in the file
                    fseek(userFile, -sizeof(struct RegisteredUser), SEEK_CUR);
                    fwrite(&user, sizeof(struct RegisteredUser), 1, userFile);
                    fflush(userFile); // Ensure the write operation is completed
                }
                break;

            case 3: // View Balance
                printf("Your total deposit is: %.2f\n", TotalDeposit);
                printf("Your total withdrawal is: %.2f\n", TotalWithdrawal);
                printf("Your current balance is: %.2f\n", user.AccountBalance);
                break;
                
            case 4: // See Transaction History
                // Print header
			    printf("\nTransaction History:\n");
			    printf("------------------------------------------------------------\n");
			    printf("| %15s | %15s |\n", "T-Code", "Amount");
			    printf("------------------------------------------------------------\n");
				
				rewind(transFile); // Reset file pointer position to the beginning
			    // Read and print each transaction
			    while (fread(&transaction, sizeof(struct TransactionData), 1, transFile)) {
			    	if (user.AccountNumber == AccountNumber){
			    		if (strcmp(transaction.TransactionCode, "D") == 0)
				        printf("| %15s | %15.2f |\n", "Deposit", transaction.Amount);
				        else if (strcmp(transaction.TransactionCode, "W") == 0)
				        printf("| %15s | %15.2f |\n", "Withdrawal", transaction.Amount);
					}
			    }
                break;

            case 5: // Exit
                printf("Exiting...\n");
                quit = 1;  // Set quit to 1 to exit the loop
                break;

            default:
                printf("Invalid option!\n");
                break;
        }
        rewind(transFile);
        getch();
    }

    fclose(userFile);
    fclose(transFile);
    return 0;
}

void ListTransact(){
    struct TransactionData transaction;
    FILE *transFile;

    // Open the transactions file in read mode
    transFile = fopen("transactions.dat", "rb");
    if (transFile == NULL) {
        printf("Error opening transactions file!\n");
        return;
    }

    // Print header
    printf("All Transaction in the Bank:\n");
    printf("----------------------------------------------\n");
    printf("| %-20s | %-25s | %-6s | %-8s |\n", "Account Number", "Name", "T-Code", "Amount");
    printf("----------------------------------------------\n");

    // Read and print each transaction
    while (fread(&transaction, sizeof(struct TransactionData), 1, transFile)) {
        char fullName[100]; // Assuming the combined length of first name and last name won't exceed 100 characters
        strcpy(fullName, transaction.FirstName); // Copy first name to fullName
        strcat(fullName, " "); // Add a space
        strcat(fullName, transaction.LastName); // Concatenate last name to fullName

        printf("| %20d | %-25s | %-6s | %-8.2f |\n", transaction.AccountNumber, fullName, transaction.TransactionCode, transaction.Amount);
    }
    getch();
    fclose(transFile);
}




