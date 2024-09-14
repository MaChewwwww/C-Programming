#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

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
    float Deposit;
    float Withdraw;
};

// Functions to be used (Prototyping)
void AdminMenu();
void RegisterUser();
void LoginUser();
void ApprovePendingUser();
void DenyPendingUser();
void ListRegisteredUser();

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
            printf("\nSelect a Choice: ");
            scanf("%d", &choice2);

            if (choice2 == 1)
                ApprovePendingUser();
            else if (choice2 == 2)
                DenyPendingUser();
            else if (choice2 == 3)
            	ListRegisteredUser();
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
        scanf("%s", &newUser.AccountPassword);

        printf("Enter Account Pin: ");
        scanf("%s", &newUser.AccountPin);

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
    char password[50];
    int found = 0;
    int attempt;
    
    // Open the file in read mode and create it if it ddoesn't exist
    userFile = fopen("users.dat", "rb");
    if (userFile == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("Login Menu\n");
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    
    while (found == 0){
    	printf("Enter Password: ");
	    scanf("%s", &password);
	
	    // Read the file to find the user
	    while (fread(&user, sizeof(struct RegisteredUser), 1, userFile)) {
	        if (user.AccountNumber == accountNumber && strcmp(user.AccountPassword, password) == 0) {
	            found = 1;
	            // Read the file to verify the pin 
			    do {			    	
			    	int current_attempt;
			    	found = 0;
			    	if (user.Attempts < 3){
			    		printf("Attempt : %d/3", user.Attempts);
			    		printf("\nPlease Enter you 6 Digit Pin : ");
			    		scanf("%d", &enteredPin);
			    		rewind(userFile); // Reset file position indicator to the beginning	
				   		while (fread(&user, sizeof(struct RegisteredUser), 1, userFile)) {
				        	if (user.AccountNumber == accountNumber && user.AccountPin == enteredPin){
				            	found = 1;
				            	user.Attempts = 0;
				            	fseek(userFile, -sizeof(struct RegisteredUser), SEEK_CUR); // Set file position
			                    fwrite(&user, sizeof(struct RegisteredUser), 1, userFile); // Write updated user
			                    break;
				       		}
				       		else if (user.AccountNumber == accountNumber && user.AccountPin != enteredPin){
				       			attempt += 1;
								user.Attempts = attempt;
				       			fseek(userFile, -sizeof(struct RegisteredUser), SEEK_CUR); // Set file position
			                    fwrite(&user, sizeof(struct RegisteredUser), 1, userFile); // Write updated user
			                    break;
							}
				    	}
					}
					else{
					printf("Card is captured! Please visit your bank branch to retrieve your card.");
					break;
					}	
				}while (found == 0);
	
	        }
	        else
	        printf("Invalid Password!\n");
	    }
	    rewind(userFile); // Reset file position indicator to the beginning
	  
	}
    
    

    fclose(userFile);

    if (found == 1) {
	
		printf("Login successful!\n");	  	
        printf("Welcome, %s\n", user.FirstName);
        getch();
        
    } else {
        printf("Invalid account number or password.\n");
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
    printf("| %-15s | %-20s | %-10s | %-10s | %-15s |\n", "Account Number", "Name", "Password", "PIN", "Balance");
    printf("------------------------------------------------------------\n");

    // Read and print each registered user
    while (fread(&user, sizeof(struct RegisteredUser), 1, userFile)) {
        printf("| %-15d | %-20s | %-10s | %-10s | %-15.2f |\n", user.AccountNumber, user.FirstName, user.AccountPassword, user.AccountPin, user.AccountBalance);
    }
    fclose(userFile);
    
    getch();
}


