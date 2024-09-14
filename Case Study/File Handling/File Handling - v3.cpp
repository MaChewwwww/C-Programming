#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>

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
    char DateSTR[11];
    char TimeSTR[9];
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
void FilterData();
void SearchData(int AN, char *FN, char *LN, char *Month, char *Date, char *Year);
int Transaction(int AccountNumber, int EnteredPin);



int main() {

    while (1) {
        system("cls");
        printf("===================================\n");
        printf("      Welcome to the Bank\n");
        printf("===================================\n\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Admin\n");
        printf("4. Exit\n");
        printf("===================================\n");  

        printf("\nSelect a Choice (1-4): ");
        char input[10];
		int choice;	
		scanf("%s",&input);
		
		// Check if the input is a valid digit
        if (isdigit(input[0]) && strlen(input) == 1) {
            choice = atoi(input);
        } else {
            printf("Invalid option! Please enter a number between 1 and 4. (Press Any Key to Continue)\n");
            getch();
            continue;
        }
		
		
	         
        if (choice == 1) {
            LoginUser();
        } else if (choice == 2) {
            RegisterUser();
        } else if (choice == 3) {
            AdminMenu();
        } else if (choice == 4) {
        	printf("\nThank you for using the Bank system. Goodbye!\n");
            break;
        } else {
            printf("\nChoice Error: Please input a valid number! (Press Any Key to Continue)\n");
            getch(); // Wait for user input before clearing the screen
        }
    }

    return 0;
}


void AdminMenu() {
	
	char input_pass[50];
    int login = 0;

    while (1) { // Infinite loop until correct password is entered or 'x' is entered
        printf("\nEnter Admin Passcode ('x' to exit): ");
        scanf("%s", input_pass);

        if (strcmp(input_pass, "pass12345") == 0) {
        	printf("Successfully Logged in! (Press any key to proceed)...");
        	getch();
        	login = 1;
            break; // Exit the loop after successful login
        } else if (strcmp(input_pass, "x") == 0) {
            printf("Exiting...\n");
            getch();
            break;
        } else {
            printf("Wrong password. Try again.\n");
        }
    }
    
    if (login == 1){
    	while(1){
    		system("cls");
		    printf("Admin Menu\n");
		    printf("1. Approve Pending User\n");
		    printf("2. Deny Pending User\n");
		    printf("3. List Registered User\n");
		    printf("4. List of all Transactions\n");
		    printf("5. Exit\n");
		    printf("\nSelect a Choice: ");
	        char input[10];
			int choice;	
			scanf("%s",&input);
			
			// Check if the input is a valid digit
	        if (isdigit(input[0]) && strlen(input) == 1) {
	            choice = atoi(input);
	        } else {
	            printf("Invalid option! Please enter a number between 1 and 5. (Press Any Key to Continue)\n");
	            getch();
	            continue;
	        }
		
		    if (choice == 1)
		    	ApprovePendingUser();
		    else if (choice == 2)
		        DenyPendingUser();
		    else if (choice == 3)
		        ListRegisteredUser();
		    else if (choice == 4)
		        ListTransact();
		    else if (choice == 5)
		        break;
		    else
		        printf("\nChoice Error: Please input a valid number! (Press Any Key to Continue)\n");
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
    
    
    char EnteredNumber[100];
    printf("Registration Menu\n\n");

    while (1) {
        printf("Enter Account Number: ");
        scanf("%s", EnteredNumber);

        int length = strlen(EnteredNumber);
        int valid = 1;

        // Check if the entered number has 10 digits and is numeric
        if (length != 10) {
            valid = 0;
        } else {
            for (int i = 0; i < length; i++) {
                if (!isdigit(EnteredNumber[i])) {
                    valid = 0;
                    break;
                }
            }
        }

        if (valid) {
            break;
        } else {
            printf("\nPlease enter a 10-digit account number!\n");
        }
    }
    
    int NewAccNum = atoi(EnteredNumber);

    // Check if the account number already exists in pending_users.dat
    rewind(p_userFile); // Reset file position indicator to the beginning
    while (fread(&newUser, sizeof(struct PendingUser), 1, p_userFile)) {
        if (newUser.AccountNumber == NewAccNum) {
            accountExists = true;
            break;
        }
    }

    // Check if the account number already exists in users.dat
    rewind(userFile); // Reset file position indicator to the beginning
    while (fread(&existingUser, sizeof(struct RegisteredUser), 1, userFile)) {
        if (existingUser.AccountNumber == NewAccNum) {
            accountExists = true;
            break;
        }
    }

    if (accountExists) {
        printf("Account number already exists. Registration failed.\n");
    } else {
        // Proceed with registration if the account number is unique and write the new user to pending_users.dat
        printf("Enter First Name: ");
        scanf(" %[^\n]", &enteredFirstName); // Use space before %[^\n] to discard leading whitespace
        strcpy(newUser.FirstName, enteredFirstName);

        printf("Enter Last Name: ");
        scanf(" %[^\n]", &enteredLastName);
        strcpy(newUser.LastName, enteredLastName);

        printf("Enter Account Password: ");
        scanf("%s", newUser.AccountPassword);
        
        while (1){
        	printf("Enter Account Pin: ");
        	scanf("%d", &newUser.AccountPin);
        	
        	int count = 0;
        	int sub = newUser.AccountPin;
        	 do {
			    sub /= 10;
			    ++count;
			   } while (sub != 0);
			   
			if (count == 6)
			break;
			else
			printf("\nPlease Enter a 6 Digit Pin!\n");
			
		}
        
        while(newUser.AccountBalance < 100){
        	printf("Enter Initial Deposit: ");
       		scanf("%f", &newUser.AccountBalance);
       		
       		if (newUser.AccountBalance >= 100)
			break;
			else
			printf("\nPlease deposit atleast 100php!\n");
       		
		}
        
        system("cls");
        
        newUser.AccountNumber = NewAccNum;
        printf("\nAccount Details\n");
        printf("\nAccount Number : %d", newUser.AccountNumber);
        printf("\nFirst Name : %s", newUser.FirstName);
        printf("\nLast Name : %s", newUser.LastName);
        printf("\nPassword : %s", newUser.AccountPassword);
        printf("\nPin : %d", newUser.AccountPin);
        
        printf("\n\nUser registration is now pending for Approval! (Press Any Key to Continue)");
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
    FILE *userFile, *pendingFile;
    int accountNumber, enteredPin;
    char enteredPassword[50];
    int checkpass = 0;
    int checkpin = 0;
    int foundUser = 0;
    int isPending = 0;

    // Open the file in read/write mode
    userFile = fopen("users.dat", "r+b");
    if (userFile == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Open the pending users file in read-only mode
    pendingFile = fopen("pending_users.dat", "rb");
    if (pendingFile == NULL) {
        printf("Error opening pending users file!\n");
        fclose(userFile);
        return;
    }

    printf("Login Menu\n");
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    
    // Check if the user is in pending_users.dat
    while (fread(&user, sizeof(struct RegisteredUser), 1, pendingFile)) {
        if (user.AccountNumber == accountNumber) {
            isPending = 1;
            break;
        }
    }

    if (isPending == 1) {
        printf("\nYour account is still pending for approval. Please contact the bank for more information.\n");
        printf("(Press Any Key to Continue)\n");
        getch();
        fclose(pendingFile);
        fclose(userFile);
        return;
    }

    // Close pending file as it's no longer needed
    fclose(pendingFile);

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
    
    time_t rawtime;
    struct tm *timeinfo;
    char date[11]; // For storing date in the format YYYY-MM-DD
    char time_str[9];  // For storing time in the format HH:MM:SS
    
    FILE *userFile;
    FILE *transFile;
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
        
        int choice = 0;
        char input[10];
        scanf("%s", input);
        
        // Check if the input is a valid digit
        if (isdigit(input[0]) && strlen(input) == 1) {
            choice = atoi(input);
        } else {
            printf("Invalid option! Please enter a number between 1 and 5.\n");
            getch();
            continue;
        }
        
        // Reset TotalDeposit and TotalWithdrawal for each iteration
        float TotalDeposit = 0, TotalWithdrawal = 0;
        
         // Rewind the transaction file pointer to the beginning
        rewind(transFile);
        
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
                
                // Get the current time
			    time(&rawtime);
			    // Convert it to local time representation
			    timeinfo = localtime(&rawtime);
			    // Format the date and store it in the date array
			    strftime(date, sizeof(date), "%Y-%m-%d", timeinfo);
			    // Format the time and store it in the time array
			    strftime(time_str, sizeof(time_str), "%H:%M:%S", timeinfo);
			    // Copydate and time to Data Structure
			    strcpy(transaction.DateSTR, date);
			    strcpy(transaction.TimeSTR, time_str);	    
			    
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
                    
                    // Get the current time
				    time(&rawtime);
				    // Convert it to local time representation
				    timeinfo = localtime(&rawtime);
				    // Format the date and store it in the date array
				    strftime(date, sizeof(date), "%Y-%m-%d", timeinfo);
				    // Format the time and store it in the time array
				    strftime(time_str, sizeof(time_str), "%H:%M:%S", timeinfo);
				    // Copydate and time to Data Structure
				    strcpy(transaction.DateSTR, date);
				    strcpy(transaction.TimeSTR, time_str);	  
				  
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
                printf("| %15s | %15s | %10s | %8s |\n", "T-Code", "Amount", "Date", "Time");
                printf("------------------------------------------------------------\n");
				
				rewind(transFile); // Reset file pointer position to the beginning
			    // Read and print each transaction
			     while (fread(&transaction, sizeof(struct TransactionData), 1, transFile)) {
                    if (transaction.AccountNumber == AccountNumber) {
                        if (strcmp(transaction.TransactionCode, "D") == 0) {
                            printf("| %15s | %15.2f | %10s | %8s |\n", "Deposit", transaction.Amount, transaction.DateSTR, transaction.TimeSTR);
                        } else if (strcmp(transaction.TransactionCode, "W") == 0) {
                            printf("| %15s | %15.2f | %10s | %8s |\n", "Withdrawal", transaction.Amount, transaction.DateSTR, transaction.TimeSTR);
                        }
                    }
                }
                break;

            case 5: // Exit
                printf("Exiting...\n");
                quit = 1;  // Set quit to 1 to exit the loop
                break;

            default:
                printf("Invalid option!\n");
                quit = 0;
                break;
        }
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
    printf("| %-20s | %-25s | %-6s | %-15s | %-12s | %-8s |\n", "Account Number", "Name", "T-Code", "Date", "Time", "Amount");
    printf("----------------------------------------------\n");

    // Read and print each transaction
    while (fread(&transaction, sizeof(struct TransactionData), 1, transFile)) {
        char fullName[100]; // Assuming the combined length of first name and last name won't exceed 100 characters
        strcpy(fullName, transaction.FirstName); // Copy first name to fullName
        strcat(fullName, " "); // Add a space
        strcat(fullName, transaction.LastName); // Concatenate last name to fullName

        printf("| %20d | %-25s | %-6s | %-15s | %12s | %-8.2f |\n", transaction.AccountNumber, fullName, transaction.TransactionCode, transaction.DateSTR, transaction.TimeSTR, transaction.Amount);
    }
    
    
    while (1) {
        char decision;
        printf("\nWould you like to Filter Data? (Y/N): ");
        scanf(" %c", &decision); // Notice the space before %c to consume any leading whitespace      
        
        if (isalpha(decision)) {
            if (decision == 'Y' || decision == 'y') {
                printf("Filtering data...\n");
                FilterData();
                break; // Exit the loop after filtering
            } else if (decision == 'N' || decision == 'n') {
                break; // Exit the loop if no filtering is required
            } else {
                printf("Invalid input. Please enter Y or N.\n");
            }
        } else {
            printf("Invalid input. Please enter Y or N.\n");
        }
    }
     
    printf("\nReturning to Admin Menu! (Press Any Key to Proceed)...");
    getch();
    fclose(transFile);
}

void FilterData(){
    
    
    int enteredAN = 00000;
    char enteredFN[50] = "NULL";
    char enteredLN[50] = "NULL";
    char enteredDATE[5] = "NULL";
    char enteredMONTH[5] = "NULL";
    char enteredYEAR[5] = "NULL";
    
    
    while(1){
    	   	
    	system("cls");
    	SearchData(enteredAN, enteredFN, enteredLN, enteredMONTH, enteredDATE, enteredYEAR);
    	printf("\n(Press Any Number for to Edit Input)\n");
    	printf("\nSearch for the following datas :\n");
    	printf("1. Account Number : %d\n", enteredAN);
    	printf("2. First Name : %s\n", enteredFN);
    	printf("3. Last Name : %s\n", enteredLN);
    	printf("4. Month : %s\n", enteredMONTH);
    	printf("5. Date : %s\n", enteredDATE);
    	printf("6. Year : %s\n", enteredYEAR);
    	printf("7. Exit\n");
    	
    	printf("\nSelect a Choice: ");
        char input[10];
		int choice;	
		scanf("%s",&input);
		
		// Check if the input is a valid digit
        if (isdigit(input[0]) && strlen(input) == 1) {
            choice = atoi(input);
        } else {
            printf("Invalid option! Please enter a number between 1 and 5. (Press Any Key to Continue)\n");
            getch();
            continue;
        }
        
        if (choice == 1){
        	printf("\nEnter the Account Number that you would like to search : ");
        	scanf("\%d", &enteredAN);

		}
		else if (choice == 2){
        	printf("\nEnter the First Name that you would like to search : ");
        	scanf("%s", enteredFN);
		}
		else if (choice == 3){
        	printf("\nEnter the Last Number that you would like to search : ");
        	scanf("%s", enteredLN);
		}
		else if (choice == 4){
        	printf("\nEnter the Month that you would like to search : ");
        	scanf("%s", enteredMONTH);
		}
		else if (choice == 5){
        	printf("\nEnter the Date that you would like to search : ");
        	scanf("%s", enteredDATE);
		}
		else if (choice == 6){
        	printf("\nEnter the Year that you would like to search : ");
        	scanf("%s", enteredYEAR);
		}
		else if (choice == 7){
			printf("\nExiting...");
			getch();
			break;
		}
		else{
			printf("Invalid Choice!!!");
			getch();
		}
			
	}
    
}

void SearchData(int AN, char *FN, char *LN, char *Month, char *Date, char *Year) {
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
    printf("| %-20s | %-25s | %-6s | %-15s | %-12s | %-8s |\n", "Account Number", "Name", "T-Code", "Date", "Time", "Amount");
    printf("----------------------------------------------\n\n");
    

    // Read and print each transaction
    while (fread(&transaction, sizeof(struct TransactionData), 1, transFile)) {
        int match = 1; // Flag to check if the transaction matches the search criteria

        
        // Check each search condition
        if (AN && transaction.AccountNumber != AN) {
            match = 0;
        }
        if (FN && strcmp(FN, "NULL") != 0 && strcmp(transaction.FirstName, FN) != 0) {
            match = 0;
        }
        if (LN && strcmp(LN, "NULL") != 0 && strcmp(transaction.LastName, LN) != 0) {
            match = 0;
        }
        if (Date && strcmp(Date, "NULL") != 0 && strncmp(transaction.DateSTR + 8, Date, 2) != 0) {
            match = 0;
        }
        if (Month && strcmp(Month, "NULL") != 0 && strncmp(transaction.DateSTR + 5, Month, 2) != 0) { 
            match = 0;	
        }
        if (Year && strcmp(Year, "NULL") != 0 && strncmp(transaction.DateSTR, Year, 4) != 0) { 
            match = 0;
        }
        
        if (match == 1) {
            char fullName[100]; // Assuming the combined length of first name and last name won't exceed 100 characters
            strcpy(fullName, transaction.FirstName); // Copy first name to fullName
            strcat(fullName, " "); // Add a space
            strcat(fullName, transaction.LastName); // Concatenate last name to fullName
            printf("| %20d | %-25s | %-6s | %-15s | %12s | %-8.2f |\n", transaction.AccountNumber, fullName, transaction.TransactionCode, transaction.DateSTR, transaction.TimeSTR, transaction.Amount);
        }
    }
    
    fclose(transFile);
}




