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
void ClearScreen();
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
int ExitFunction(char *str);


// ANSI escape codes for colors and formatting
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

int main() {
    while (1) {
        ClearScreen();
        printf(GREEN "==============================================\n" RESET);
        printf(WHITE BOLD BG_GREEN "\t   Welcome to the Bank   \n" RESET);
        printf(GREEN "==============================================\n" RESET);
        printf(CYAN "\n\t\t1. Login\n" RESET);
        printf(YELLOW "\t\t2. Register\n" RESET);
        printf(MAGENTA "\t\t3. Admin\n" RESET);
        printf(RED "\t\t4. Exit\n\n" RESET);
        printf(GREEN "==============================================\n" RESET);

        printf(WHITE BOLD "\nSelect a Choice (1-4): " RESET);
        char input[10];
        int choice;    
        scanf("%s", input);

        // Check if the input is a valid digit between 1 and 4
        if (isdigit(input[0]) && strlen(input) == 1 && input[0] >= '1' && input[0] <= '4') {
            choice = atoi(input);
        } else {
            printf(RED "\nInvalid option! Please enter a number between 1 and 4. (Press any key to continue)\n" RESET);
            getch();
            continue;
        }

        switch (choice) {
            case 1:
                LoginUser();
                break;
            case 2:
                RegisterUser();
                break;
            case 3:
                AdminMenu();
                break;
            case 4:
                printf(WHITE BG_GREEN BOLD "\nThank you for using the Bank system. Goodbye!\n" RESET);
                return 0;
            default:
                printf(RED "\nChoice Error: Please input a valid number! (Press any key to continue)\n" RESET);
                getch(); // Wait for user input before clearing the screen
                break;
        }
    }

    return 0;
}


void AdminMenu() {
    char input_pass[50];
    int login = 0;

    while (1) { // Infinite loop until correct password is entered or 'x' is entered
        ClearScreen();
        printf(MAGENTA BOLD "=================================\n" RESET);
        printf(MAGENTA BOLD "        Admin Login Menu         \n" RESET);
        printf(MAGENTA BOLD "=================================\n" RESET);
        printf(MAGENTA "Enter Admin Passcode ('x' to exit): " RESET);
        scanf("%s", input_pass);

        if (strcmp(input_pass, "pass12345") == 0) {
            printf(GREEN "\nSuccessfully Logged in! (Press any key to proceed)..." RESET);
            getch();
            login = 1;
            break; // Exit the loop after successful login
        } else if (strcmp(input_pass, "x") == 0) {
            printf("Exiting...\n");
            getch();
            break;
        } else {
            printf(RED "Wrong password. Try again.\n" RESET);
            printf("(Press any key to continue)");
            getch();
        }
    }

    if (login == 1) {
        while (1) {
            ClearScreen();
            printf(MAGENTA BOLD "=================================\n" RESET);
            printf(MAGENTA BOLD "            Admin Menu           \n" RESET);
            printf(MAGENTA BOLD "=================================\n" RESET);
            printf(GREEN "\n1. Approve Pending User\n" RESET);
            printf(YELLOW "2. Deny Pending User\n" RESET);
            printf(CYAN "3. List Registered User\n" RESET);
            printf(WHITE "4. List of all Transactions\n" RESET);
            printf(RED "5. Exit\n\n" RESET);
            printf(MAGENTA BOLD "Select a Choice (1-5): " RESET);
            
            char input[10];
            int choice;
            scanf("%s", input);

            // Check if the input is a valid digit between 1 and 5
            if (isdigit(input[0]) && strlen(input) == 1 && input[0] >= '1' && input[0] <= '5') {
                choice = atoi(input);
            } else {
                printf(RED "\nInvalid option! Please enter a number between 1 and 5. (Press Any Key to Continue)\n" RESET);
                getch();
                continue;
            }

            switch (choice) {
                case 1:
                    ApprovePendingUser();
                    break;
                case 2:
                    DenyPendingUser();
                    break;
                case 3:
                    ListRegisteredUser();
                    break;
                case 4:
                    ListTransact();
                    break;
                case 5:
                    printf(GREEN BOLD "\nExiting Admin Menu...\n" RESET);
                    getch();
                    return;
                default:
                    printf(RED "\nChoice Error: Please input a valid number! (Press Any Key to Continue)\n" RESET);
                    getch(); // Wait for user input before clearing the screen
                    break;
            }
        }
    }
}


void RegisterUser() {
    struct RegisteredUser existingUser;
    struct PendingUser newUser;
    char enteredFirstName[50];
    char enteredLastName[50];
    char strpin[6]; // 6 digits
    int NewAccNum;

    FILE *p_userFile;
    FILE *userFile;
    bool accountExists = false; // Flag to indicate if account number exists

    ClearScreen();

    // Open the users file in read/write mode to check existing accounts, and create it if it doesn't exist
    userFile = fopen("users.dat", "a+b");
    if (userFile == NULL) {
        printf(RED "Error opening users file!\n" RESET);
        getch();
        return;
    }

    // Open the pending users file in append mode, and create it if it doesn't exist
    p_userFile = fopen("pending_users.dat", "a+b");
    if (p_userFile == NULL) {
        printf(RED "Error opening pending users file!\n" RESET);
        fclose(userFile);
        getch();
        return;
    }

    printf(YELLOW BOLD "================================\n" RESET);
    printf(YELLOW BOLD "        Registration Menu       \n" RESET);
    printf(YELLOW BOLD "================================\n" RESET);

    char EnteredNumber[10];
    while (1) {
        printf(YELLOW "\nEnter Account Number: " RESET);
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
        	NewAccNum = atoi(EnteredNumber);
        	newUser.AccountNumber = NewAccNum;
            break;
        } else {
            printf(RED "\nPlease Enter a 10-digit Account Number!\n" RESET);
        }
    }

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
        printf(RED "\nAccount number already exists. Registration failed.\n" RESET);
        printf(YELLOW "(Press Any Key to Continue)" RESET);
        getch();
    } else {
        // Proceed with registration if the account number is unique and write the new user to pending_users.dat
        printf(YELLOW "Enter First Name: " RESET);
        scanf(" %[^\n]", enteredFirstName); // Use space before %[^\n] to discard leading whitespace
        strcpy(newUser.FirstName, enteredFirstName);

        printf(YELLOW "Enter Last Name: " RESET);
        scanf(" %[^\n]", enteredLastName);
        strcpy(newUser.LastName, enteredLastName);

        printf(YELLOW "Enter Account Password: " RESET);
        scanf("%s", newUser.AccountPassword);

        while (1) {
            printf(YELLOW "Enter Account Pin (6 digits): " RESET);
            scanf("%s", strpin);

            if (strlen(strpin) == 6 && 
			    isdigit(strpin[0]) != 0 &&
			    isdigit(strpin[1]) != 0 &&
			    isdigit(strpin[2]) != 0 &&
			    isdigit(strpin[3]) != 0 &&
			    isdigit(strpin[4]) != 0 &&
			    isdigit(strpin[5]) != 0) 
				{
	            	newUser.AccountPin = atoi(strpin);
	                break;
            } 
			else {
                printf(RED "\nPlease enter a 6-digit Pin!\n" RESET);
            }
        }
        
        newUser.AccountBalance = 0;
        while (newUser.AccountBalance < 100) {
            printf(YELLOW "Enter Initial Deposit (minimum 100php): " RESET);
            scanf("%f", &newUser.AccountBalance);

            if (newUser.AccountBalance >= 100) {
                break;
            } else {
                printf(RED "\nPlease deposit at least 100php!\n" RESET);
            }
        }

        system("cls");

        printf(YELLOW BOLD "================================\n" RESET);
        printf(YELLOW BOLD "         Account Details         \n" RESET);
        printf(YELLOW BOLD "================================\n" RESET);
        printf(WHITE "Account Number  : %d\n", newUser.AccountNumber);
        printf("First Name      : %s\n", newUser.FirstName);
        printf("Last Name       : %s\n", newUser.LastName);
        printf("Password        : %s\n", newUser.AccountPassword);
        printf("Pin             : %d\n", newUser.AccountPin);
        printf("Initial Deposit : %.2f Php\n", newUser.AccountBalance);
        printf(YELLOW BOLD "================================\n" RESET);

        printf(GREEN "\nUser registration is now pending for Approval!\n");
        printf(YELLOW "(Press Any Key to Continue)\n" RESET);
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
    char input[6];
    int checkpass = 0;
    int checkpin = 0;
    int foundUser = 0;
    int isPending = 0;

    // Open the file in read/write mode
    userFile = fopen("users.dat", "r+b");
    if (userFile == NULL) {
        printf(RED "Error opening file!\n" RESET);
        return;
    }
    
    // Open the pending users file in read-only mode
    pendingFile = fopen("pending_users.dat", "rb");
    if (pendingFile == NULL) {
        printf(RED "Error opening pending users file!\n" RESET);
        fclose(userFile);
        return;
    }
    
    int exitLoop = 0;
    while (exitLoop == 0) {
    	char strAN[10];
        ClearScreen();
		printf(BLUE BOLD "=========================\n" RESET);
		printf(BLUE BOLD "       Login Menu        \n" RESET);
		printf(BLUE BOLD "=========================\n" RESET);
		printf(WHITE BOLD "(Press X key to Exit)\n" RESET);
		printf(CYAN "\nEnter Account Number: " RESET);
		scanf("%s", strAN);
		
		if (strcmp(strAN, "x") == 0 || strcmp(strAN, "X") == 0){
			exitLoop = 1;
			isPending = 4;
			printf(RED "\nGoing Back to the Menu...\n" RESET);
	        printf(YELLOW "(Press Any Key to Continue)\n" RESET);
	        getch();
	        fclose(pendingFile);
	        fclose(userFile);
			break;
		}
        else if (strlen(strAN) == 10 && 
			isdigit(strAN[0]) != 0 &&
			isdigit(strAN[1]) != 0 &&
			isdigit(strAN[2]) != 0 &&
			isdigit(strAN[3]) != 0 &&
			isdigit(strAN[4]) != 0 &&
			isdigit(strAN[5]) != 0 &&
			isdigit(strAN[6]) != 0 &&
			isdigit(strAN[7]) != 0 &&
			isdigit(strAN[8]) != 0 &&
			isdigit(strAN[9]) != 0)
			{
				accountNumber = atoi(strAN);
	            // Check if the user is in pending_users.dat
				rewind(pendingFile);
				while (fread(&user, sizeof(struct RegisteredUser), 1, pendingFile)) {
				    if (user.AccountNumber == accountNumber) {
				        isPending = 1;
				        break;
				    }
				}
				    
				// Check if the user is in users.dat
				rewind(userFile); // Reset file position indicator to the beginning
				while (fread(&user, sizeof(struct RegisteredUser), 1, userFile)) {
				    if (user.AccountNumber == accountNumber) {
				        isPending = 2;
				        break;
				    }
				}
	            break;
            } 
		else {
            printf(RED "\nPlease enter a 10-digit Account Number!\n" RESET);
            getch();
        }
    } // end of while

    if (isPending == 1) {
        printf(RED "\nYour account is still pending for approval. Please contact the bank for more information.\n" RESET);
        printf(YELLOW "(Press Any Key to Continue)\n" RESET);
        getch();
        fclose(pendingFile);
        fclose(userFile);
        return;
    }

    // Close pending file as it's no longer needed
    fclose(pendingFile);
    
    if (isPending == 2){
    	while (checkpass == 0) {
        printf(CYAN "Enter Password: " RESET);
        scanf("%s", enteredPassword);
        
         if (ExitFunction(enteredPassword) == 1){
         	fclose(userFile);
            return;
		 }

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
                printf(RED "Invalid Password!\n" RESET);
            } else {
                printf(RED "Account not found!\n" RESET);
                fclose(userFile);
                return;
            }
        }
    }

    while (checkpin == 0) {
        if (user.Attempts >= 3) {
            printf(RED "\nCard is captured! Please visit your bank branch to retrieve your card.\n" RESET);
            printf(YELLOW "(Press Any Key to Continue)" RESET);
            getch();
            fclose(userFile);
            return;
        }
        
        
        
        while(1){
        	
        	printf(CYAN "Enter Pin: " RESET);
	        scanf("%s", input);
	        if (ExitFunction(input) == 1){
	         	fclose(userFile);
	            return;
			 }	
      	
        	if (strlen(input) == 6){
        		
        		enteredPin = atoi(input);
        		if (user.AccountPin == enteredPin) {
		            checkpin = 1;
		            user.Attempts = 0;
		            // Move the file pointer back to the current record position
		            fseek(userFile, -sizeof(struct RegisteredUser), SEEK_CUR);
		            // Update the record in the file
		            fwrite(&user, sizeof(struct RegisteredUser), 1, userFile);
		            fflush(userFile); // Ensure the write operation is completed
		            
		            printf(GREEN BOLD "\nLogin Successful!\n" RESET);
		            printf(CYAN BOLD "Welcome, %s\n" RESET, user.FirstName);
		            getch();
		            
		            // Call Transaction function and handle exit
		            int transactionResult = Transaction(accountNumber, enteredPin);
		            if (transactionResult == 0) {
		                // Transaction ended, return to stop further execution
		                fclose(userFile);
		                return;
		            }
		        } else {
		            user.Attempts += 1;
		            printf(RED "\nInvalid Pin! " RESET);
		            printf(YELLOW "Attempt %d/3\n" RESET, user.Attempts);
		            
		            // Move the file pointer back to the current record position
		            fseek(userFile, -sizeof(struct RegisteredUser), SEEK_CUR);
		            // Update the record in the file
		            fwrite(&user, sizeof(struct RegisteredUser), 1, userFile);
		            fflush(userFile); // Ensure the write operation is completed
		        }	
		}
		else {
			printf(RED "\nPlease Enter a 6 Digit Pin!\n" RESET);
		}
        	
	}
}
 	
	} else if (isPending == 0){
		printf(RED "\nThe Account Number that you have entered does not exist!\n" RESET);
        printf(YELLOW "(Press Any Key to Continue)\n" RESET);
        getch();
        fclose(pendingFile);
        fclose(userFile);
        return;
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
        ClearScreen();

        // Open the files and create if they don't exist
        p_userFile = fopen("pending_users.dat", "rb");
        userFile = fopen("users.dat", "ab");

        if (p_userFile == NULL || userFile == NULL) {
            printf(RED "Error opening file!\n" RESET);
            return;
        }

        // Display pending users
        printf(GREEN BOLD "========================================\n" RESET);
        printf(GREEN BOLD "      Pending Users for Approval        \n" RESET);
        printf(GREEN BOLD "========================================\n" RESET);
        while (fread(&pendingUser, sizeof(struct PendingUser), 1, p_userFile)) {
            printf(GREEN "Account Number: " WHITE "%d\n" RESET, pendingUser.AccountNumber);

            strcpy(TempName, pendingUser.FirstName);
            strcat(TempName, " ");
            strcat(TempName, pendingUser.LastName);

            printf(GREEN "Name: " WHITE "%s\n\n" RESET, TempName);
        }
        
        printf(GREEN BOLD "========================================\n" RESET);
        rewind(p_userFile); // Reset file pointer position to the beginning

        printf(YELLOW "Enter Account Number to Approve: " RESET);
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
            printf(GREEN "User approved successfully!\n" RESET);
        else
            printf(RED "Account number not found!\n" RESET);

        printf(WHITE "Do you want to approve another user? (y/n): " RESET);
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
        ClearScreen();

        // Open the files
        p_userFile = fopen("pending_users.dat", "rb");
        deniedFile = fopen("denied_users.dat", "ab");

        if (p_userFile == NULL || deniedFile == NULL) {
            printf(RED "Error opening file!\n" RESET);
            return;
        }

        // Display pending users
        printf(RED BOLD "========================================\n" RESET);
        printf(RED BOLD "       Pending Users for Denial         \n" RESET);
        printf(RED BOLD "========================================\n" RESET);
        while (fread(&pendingUser, sizeof(struct PendingUser), 1, p_userFile)) {
            printf(RED "Account Number: " WHITE "%d\n" RESET, pendingUser.AccountNumber);

            strcpy(TempName, pendingUser.FirstName);
            strcat(TempName, " ");
            strcat(TempName, pendingUser.LastName);

            printf(RED "Name: " WHITE "%s\n\n" RESET, TempName);
        }
        
        printf(RED BOLD "========================================\n" RESET);
        rewind(p_userFile); // Reset file pointer position to the beginning

        printf(YELLOW "Enter Account Number to Deny: " RESET);
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
            printf(RED "User denied successfully!\n" RESET);
        else
            printf(RED "Account number not found!\n" RESET);

        printf(WHITE "Do you want to deny another user? (y/n): " RESET);
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
        printf(CYAN "Error opening file!\n" RESET);
        return;
    }

    // Print header
    printf(CYAN BOLD "========================================================================================================================\n" RESET);
    printf(GREEN BOLD "| %-20s "CYAN"|"BLUE BOLD" %-25s "CYAN"|"MAGENTA BOLD" %-15s "CYAN"|"WHITE" %-10s "CYAN"|"YELLOW BOLD" %-15s "CYAN"|"RED BOLD" %-5s "CYAN"|\n" RESET, "Account Number", "Name", "Password", "PIN", "Balance", "Attempt");
    printf(CYAN BOLD "========================================================================================================================\n" RESET);

    // Read and print each registered user
    while (fread(&user, sizeof(struct RegisteredUser), 1, userFile)) {
        printf(WHITE "| %20d | %-25s | %-15s | %10d | %15.2f | %5d   |\n" RESET, user.AccountNumber, user.FirstName, user.AccountPassword, user.AccountPin, user.AccountBalance, user.Attempts);
    }
    
    printf(CYAN BOLD "========================================================================================================================\n" RESET);
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
    char str[10];
    bool foundUser = false;

    // Open the users file in read/write mode
    userFile = fopen("users.dat", "r+b");
    if (userFile == NULL) {
        printf(CYAN "Error opening users file!\n" RESET);
        return -1;
    }

    // Open the transactions file in append mode, and create it if it doesn't exist
    transFile = fopen("transactions.dat", "a+b");
    if (transFile == NULL) {
        printf(CYAN "Error opening transactions file!\n" RESET);
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
        printf(CYAN "Account not found!\n" RESET);
        fclose(userFile);
        fclose(transFile);
        return -1;
    }
    
    while (quit == 0) {
        system("cls");
        printf(CYAN BOLD "========================================\n" RESET);
        printf(CYAN BOLD "            Welcome %s!            \n" RESET, user.FirstName);
        printf(CYAN BOLD "========================================\n" RESET);
        printf(GREEN "1. Deposit\n");
        printf(YELLOW "2. Withdraw\n");
        printf(CYAN "3. Balance Inquiry\n");
        printf(MAGENTA "4. Transaction History\n");
        printf(RED "5. Exit\n");
        printf(CYAN BOLD "========================================\n" RESET);
        printf("Select an option: ");
        
        int choice = 0;
        char input[10];
        
        scanf("%s", input);
        
        // Check if the input is a valid digit
        if (isdigit(input[0]) && strlen(input) == 1) {
            choice = atoi(input);
        } else {
            printf(CYAN "Invalid option! Please enter a number between 1 and 5.\n" RESET);
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
            	printf(WHITE BOLD "\n(Enter X key to Cancel Deposit)" RESET);
                printf(GREEN "\nEnter Amount to Deposit: " RESET);
                scanf("%s", str);
                
                if (ExitFunction(str) == 1){
   					break;
				}
				else if (strlen(str) > 10) {
			        printf(RED "\nInput exceeds maximum length of 10 digit!\n" RESET);
			        printf(YELLOW "(Press Any Key to Continue)\n" RESET);
			        break; 
		   		}				
				
				//int isValid = 1;
				//for (int i = 0; i < strlen(str); ++i) {
		        //if (!isdigit(str[i])) {
		            //isValid = 0;
		            //break;
		        	//}
		   		//}	
		   		
		   		//if (isdigit(str[0]) == 0 && isdigit(str[1]) == 0 &&
					//isdigit(str[2]) == 0 && isdigit(str[3]) == 0 &&
					//isdigit(str[4]) == 0 && isdigit(str[5]) == 0 &&
					//isdigit(str[6]) == 0 && isdigit(str[7]) == 0 &&
					//isdigit(str[8]) == 0 && isdigit(str[9]) == 0 ){
					//	printf(RED "\nPlease Only Enter a Numerical Character!\n" RESET);
	                //	break;
				//}
		   		
				else{
					amount = atof(str);
	                if (amount <= 0){
	                	printf(RED "\nPlease Enter a Positive Amount!\n" RESET);
	                	printf(YELLOW "(Press Any Key to Continue)\n" RESET);
					}
	                else {
	                	user.AccountBalance += amount;
		                printf(GREEN "Deposit successful! \n"YELLOW"New balance: %.2f\n" RESET, user.AccountBalance);
		                
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
		                // Copy date and time to Data Structure
		                strcpy(transaction.DateSTR, date);
		                strcpy(transaction.TimeSTR, time_str);
		                
		                fwrite(&transaction, sizeof(struct TransactionData), 1, transFile);
		
		                // Update the user's balance in the file
		                fseek(userFile, -sizeof(struct RegisteredUser), SEEK_CUR);
		                fwrite(&user, sizeof(struct RegisteredUser), 1, userFile);
		                fflush(userFile); // Ensure the write operation is completed
					}
				} 
				break; // end of case 1
				
            case 2: // Withdraw              
                printf(WHITE BOLD "\n(Enter X key to Cancel Deposit)" RESET);
                printf(YELLOW "\nEnter Amount to Withdraw: " RESET);
                scanf("%s", str);
                
                if (ExitFunction(str) == 1){
   					break;
				}
				else if (strlen(str) > 10) {
			        printf(RED "\nInput exceeds maximum length of 10 digit!\n" RESET);
			        printf(YELLOW "(Press Any Key to Continue)\n" RESET);
			        break; 
		   		}	
		   		
		   		amount = atof(str);
		   		TotalWithdrawal += amount;
		   		if (amount <= 0){
	                printf(RED "\nPlease Enter a Positive Amount!\n" RESET);
	                break;
					}
                else if (TotalDeposit < TotalWithdrawal) {
                    printf(RED "Insufficient funds!\n" RESET);
                    break;
                } else {
                    user.AccountBalance -= amount;
                    printf(CYAN "Withdrawal successful! "YELLOW"New balance: %.2f\n" RESET, user.AccountBalance);

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
                    // Copy date and time to Data Structure
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
                printf(GREEN "\nYour total deposit: "WHITE"%.2f\n", TotalDeposit);
                printf(YELLOW"Your total withdrawal: "WHITE"%.2f\n", TotalWithdrawal);
                printf(CYAN"Your current balance: "WHITE"%.2f\n" RESET, user.AccountBalance);
                break;
                
            case 4: // See Transaction History
                // Print header
                printf(CYAN BOLD "\nTransaction History:\n" RESET);
                printf(CYAN BOLD "--------------------------------------------------------------\n" RESET);
                printf(CYAN BOLD "|"WHITE" %15s "CYAN BOLD"|"WHITE" %15s "CYAN BOLD"|"WHITE" %10s "CYAN BOLD" |"WHITE" %8s "CYAN BOLD"|\n" RESET, "T-Code", "Amount", "Date", "Time");
                printf(CYAN BOLD "--------------------------------------------------------------\n" RESET);
                
                // Rewind the transaction file pointer to the beginning
                rewind(transFile);
                
                // Read and print each transaction
                while (fread(&transaction, sizeof(struct TransactionData), 1, transFile)) {
                    if (transaction.AccountNumber == AccountNumber) {
                        if (strcmp(transaction.TransactionCode, "D") == 0) {
                            printf(CYAN BOLD "|"GREEN" %15s "CYAN BOLD"|"YELLOW" %15.2f+ "CYAN BOLD"|"WHITE" %10s "CYAN BOLD"|"WHITE" %8s "CYAN BOLD"|\n" RESET, "Deposit", transaction.Amount, transaction.DateSTR, transaction.TimeSTR);
                        } else if (strcmp(transaction.TransactionCode, "W") == 0) {
                            printf(CYAN BOLD "|"RED" %15s "CYAN BOLD"|"YELLOW" %15.2f- "CYAN BOLD"|"WHITE" %10s "CYAN BOLD"|"WHITE" %8s "CYAN BOLD"|\n" RESET, "Withdrawal", transaction.Amount, transaction.DateSTR, transaction.TimeSTR);
                        }
                    }
                }
                printf(CYAN BOLD "--------------------------------------------------------------\n" RESET);
                break;

            case 5: // Exit
                printf(RED "\nExiting...\n" RESET);
                printf(YELLOW "(Press Any Key to Continue)\n" RESET);
                quit = 1;  // Set quit to 1 to exit the loop
                break;

            default:
                printf(RED BOLD"\nInvalid option!\n" RESET);
                printf(YELLOW "(Press Any Key to Continue)\n" RESET);
                quit = 0;
                break;
        }
        getch();
    }

    fclose(userFile);
    fclose(transFile);
    return 0;
}


void ListTransact() {
    struct TransactionData transaction;
    FILE *transFile;

    // Open the transactions file in read mode
    transFile = fopen("transactions.dat", "rb");
    if (transFile == NULL) {
        printf(MAGENTA "Error opening transactions file!\n" RESET);
        return;
    }

    // Print header
	printf(MAGENTA BOLD "===========================================================================================================\n" RESET);
	printf(MAGENTA BOLD "                    All Transactions in the Bank                      \n" RESET);
	printf(MAGENTA BOLD "===========================================================================================================\n" RESET);
	printf(YELLOW " %-20s "MAGENTA"|"CYAN BOLD" %-25s "MAGENTA"| "GREEN"%-6s   "MAGENTA"|"WHITE" %-15s "MAGENTA"|"WHITE" %-12s "MAGENTA"|"YELLOW BOLD" %-8s "MAGENTA"|\n", "Account Number", "Name", "T-Code", "Date", "Time", "Amount");
	printf(MAGENTA BOLD "===========================================================================================================\n" RESET);
	
	// Read and print each transaction
	while (fread(&transaction, sizeof(struct TransactionData), 1, transFile)) {
	    char fullName[100]; // Assuming the combined length of first name and last name won't exceed 100 characters
	    strcpy(fullName, transaction.FirstName); // Copy first name to fullName
	    strcat(fullName, " "); // Add a space
	    strcat(fullName, transaction.LastName); // Concatenate last name to fullName
	
	    // Format and print each transaction row
	    if (strcmp(transaction.TransactionCode, "D") == 0) {
	        printf(WHITE " %-20d "MAGENTA"|"WHITE" %-25s "MAGENTA"| " GREEN "%-6s" MAGENTA "  |"WHITE" %-15s "MAGENTA"|"WHITE" %-12s "MAGENTA"| " WHITE "%-8.2f "MAGENTA"|\n" RESET, transaction.AccountNumber, fullName, "Deposit", transaction.DateSTR, transaction.TimeSTR, transaction.Amount);
	    } else if (strcmp(transaction.TransactionCode, "W") == 0) {
	        printf(WHITE " %-20d "MAGENTA"|"WHITE" %-25s "MAGENTA"| " RED "%-6s" MAGENTA " |"WHITE" %-15s "MAGENTA"|"WHITE" %-12s "MAGENTA"| " WHITE "%-8.2f "MAGENTA"|\n" RESET, transaction.AccountNumber, fullName, "Withdraw", transaction.DateSTR, transaction.TimeSTR, transaction.Amount);
	    } else {
	        printf(WHITE " %-20d "MAGENTA"|"WHITE" %-25s "MAGENTA"| " YELLOW "%-6s" MAGENTA " |"WHITE" %-15s "MAGENTA"|"WHITE" %-12s "MAGENTA"| " WHITE "%-8.2f "MAGENTA"|\n" RESET, transaction.AccountNumber, fullName, "Unknown", transaction.DateSTR, transaction.TimeSTR, transaction.Amount);
	    }
	}
	
	printf(MAGENTA BOLD "===========================================================================================================\n" RESET);



    // Prompt for filtering data
	while (1) {
	    char decision;
	    printf(YELLOW BOLD "\nWould you like to Filter Data? ("GREEN"Y"WHITE"/"RED"N"YELLOW BOLD"): " RESET);
	    scanf(" %c", &decision); // Notice the space before %c to consume any leading whitespace
	
	    if (isalpha(decision)) {
	        if (decision == 'Y' || decision == 'y') {
	            printf(GREEN"\nFiltering data... "YELLOW"\n(Press Any Key to Continue)...\n");
	            getch();
	            FilterData();
	            break; // Exit the loop after filtering
	        } else if (decision == 'N' || decision == 'n') {
	            break; // Exit the loop if no filtering is required
	        } else {
	            printf(YELLOW"\nInvalid input. Please enter "GREEN"Y "YELLOW"or "RED"N"YELLOW".\n");
	        }
	    } else {
	        printf(YELLOW"\nInvalid input. Please enter "GREEN"Y "YELLOW"or "RED"N"YELLOW".\n");
	    }
	}
	
	printf(GREEN "\nReturning to Admin Menu! "YELLOW"(Press Any Key to Proceed)..." RESET);
	getch();
    fclose(transFile);
}


void FilterData() {
    int enteredAN = 0000000000; //1231231231
    char enteredFN[50] = "NULL"; //
    char enteredLN[50] = "NULL";
    char enteredDATE[5] = "NULL";
    char enteredMONTH[5] = "NULL";
    char enteredYEAR[5] = "NULL";
    
    while (1) {
        system("cls");
        SearchData(enteredAN, enteredFN, enteredLN, enteredMONTH, enteredDATE, enteredYEAR);
        
        printf(MAGENTA BOLD "\n===========================================================================================================\n" RESET);
        printf(MAGENTA BOLD "           Search for the Following Data              \n" RESET);
        printf(MAGENTA BOLD "===========================================================================================================\n" RESET);
        printf(GREEN"(Press Any Number to Edit Input)\n");
        printf(CYAN "1. Account Number   : %d\n", enteredAN);
        printf(CYAN BOLD "2. First Name       : %s\n", enteredFN);
        printf(CYAN BOLD "3. Last Name        : %s\n", enteredLN);
        printf(YELLOW "4. Month            : %s\n", enteredMONTH);
        printf(YELLOW "5. Date             : %s\n", enteredDATE);
        printf(YELLOW "6. Year             : %s\n", enteredYEAR);
        printf(RED "7. Exit\n" RESET);
        printf(MAGENTA BOLD "===========================================================================================================\n" RESET);
        
        printf("\nSelect a Choice: ");
        int choice = 0;
        char input[10];
        scanf("%s", input);
        
        // Check if the input is a valid digit
        if (isdigit(input[0]) && strlen(input) == 1) {
            choice = atoi(input);
        } else {
            printf(RED "Invalid option! Please enter a number between 1 and 7. "YELLOW"(Press Any Key to Continue)\n" RESET);
            getch();
            continue;
        }
        
        switch (choice) {
            case 1:
                printf(CYAN "Enter the Account Number that you would like to search: ");
                scanf("%d", &enteredAN);
                break;
            case 2:
                printf(CYAN BOLD "Enter the First Name that you would like to search: ");
                scanf("%s", enteredFN);
                break;
            case 3:
                printf(CYAN BOLD "Enter the Last Name that you would like to search: ");
                scanf("%s", enteredLN);
                break;
            case 4:
                printf(YELLOW "Enter the Month that you would like to search: ");
                scanf("%s", enteredMONTH);
                break;
            case 5:
                printf(YELLOW "Enter the Date that you would like to search: ");
                scanf("%s", enteredDATE);
                break;
            case 6:
                printf(YELLOW "Enter the Year that you would like to search: ");
                scanf("%s", enteredYEAR);
                break;
            case 7:
                return;
            default:
                printf(RED "Invalid Choice! "YELLOW"(Press Any Key to Continue)...\n" RESET);
                getch();
                break;
        }
    }
}


void SearchData(int AN, char *FN, char *LN, char *Month, char *Date, char *Year) {
    struct TransactionData transaction;
    FILE *transFile;

    // Open the transactions file in read mode
    transFile = fopen("transactions.dat", "rb");
    if (transFile == NULL) {
        printf(RED "Error opening transactions file!\n" RESET);
        return;
    }
    
    // Print header
    printf(MAGENTA BOLD "===========================================================================================================\n" RESET);
    printf(MAGENTA BOLD "             All Transactions in the Bank              \n" RESET);
    printf(MAGENTA BOLD "===========================================================================================================\n" RESET);
    printf(YELLOW " %-20s " MAGENTA "|" CYAN BOLD " %-25s " MAGENTA "| %-6s " MAGENTA "| %-15s " MAGENTA "| %-12s " MAGENTA "| %-10s |\n" RESET, "Account Number", "Name", "T-Code", "Date", "Time", "Amount");
    printf(MAGENTA BOLD "===========================================================================================================\n" RESET);

    // Read and print each transaction
    while (fread(&transaction, sizeof(struct TransactionData), 1, transFile)) {
        int match = 1; // Flag to check if the transaction matches the search criteria

        // Check each search condition
        if (AN != 0000000000 && transaction.AccountNumber != AN) {
            match = 0;
        }
        if (strcmp(FN, "NULL") != 0 && strcmp(transaction.FirstName, FN) != 0) {
            match = 0;
        }
        if (strcmp(LN, "NULL") != 0 && strcmp(transaction.LastName, LN) != 0) {
            match = 0;
        }
        if (strcmp(Date, "NULL") != 0 && strncmp(transaction.DateSTR + 8, Date + 0, 2) != 0) {
            match = 0;
        }
        if (strcmp(Month, "NULL") != 0 && strncmp(transaction.DateSTR + 5, Month + 0, 2) != 0){
            match = 0;
        }
        if (strcmp(Year, "NULL") != 0 && strncmp(transaction.DateSTR, Year, 4) != 0) {
            match = 0;
        }
        
        if (match == 1) {
            char fullName[100]; // Assuming the combined length of first name and last name won't exceed 100 characters
            strcpy(fullName, transaction.FirstName); // Copy first name to fullName
            strcat(fullName, " "); // Add a space
            strcat(fullName, transaction.LastName); // Concatenate last name to fullName
            
            // Print formatted transaction data
            printf(WHITE " %-20d " MAGENTA "|" WHITE " %-25s " MAGENTA "| " WHITE "%-6s" MAGENTA " |" WHITE " %-15s " MAGENTA "|"WHITE" %-12s " MAGENTA "| " WHITE "%-10.2f " MAGENTA "|\n" RESET,
                   transaction.AccountNumber, fullName, transaction.TransactionCode, transaction.DateSTR, transaction.TimeSTR, transaction.Amount);
        }
    }
    
    fclose(transFile);
}



void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int ExitFunction(char *str){
	if (strcmp(str, "x") == 0){
        	printf(RED "\nGoing Back to the Menu...\n" RESET);
	        printf(YELLOW "(Press Any Key to Continue)\n" RESET);
	        getch();
        	return 1; // Indicate exit
		}
	else if (strcmp(str, "X") == 0){
			printf(RED "\nGoing Back to the Menu...\n" RESET);
	        printf(YELLOW "(Press Any Key to Continue)\n" RESET);
	        getch();
			return 1; // Indicate exit
	}
	else
		return 0; // Indicate continue
}



