#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added for strcmp function

// ANSI escape codes for colors and formatting
#define RESET "\x1b[0m"
#define CYAN_BOLD "\x1b[1;36m"
#define WHITE "\x1b[0;37m"
#define GRAY "\x1b[1;90m"
#define GREEN "\x1b[0;32m"
#define GOLD_BOLD "\x1b[1;33m"

// Function prototypes
void login();
void registerUser();
void admin();
void exitProgram();

int main() {
int choice;

while (1) {
// Clear the console
printf("\033[H\033[J");

// Display the menu
printf(GRAY "=====================================\n" RESET);
printf(CYAN_BOLD " --- Welcome to the Bank ---\n" RESET);
printf(GRAY "=====================================\n" RESET);
printf(GOLD_BOLD " [1]" RESET GREEN " Login\n" RESET);
printf(GOLD_BOLD " [2]" RESET GREEN " Register\n" RESET);
printf(GOLD_BOLD " [3]" RESET GREEN " Admin\n" RESET);
printf(GOLD_BOLD " [4]" RESET GREEN " Exit\n" RESET);
printf(GRAY "=====================================\n" RESET);

// Prompt user for choice
printf(WHITE "Select a Choice: " RESET);
scanf("%d", &choice);

// Handle the user's choice
switch (choice) {
case 1:
login();
break;
case 2:
registerUser();
break;
case 3:
admin();
break;
case 4:
exitProgram();
return 0;
default:
printf(GOLD_BOLD "Invalid choice. Please try again.\n" RESET);
printf("Press Enter to continue...");
getchar(); // To consume the newline character left by scanf
getchar(); // Wait for Enter key
break;
}
}
return 0;
}

// Login function
void login() {
char username[30];
char password[30];

printf("\033[H\033[J");
printf(CYAN_BOLD "========== Login ==========\n" RESET);
printf("Username: ");
scanf("%s", username);
printf("Password: ");
scanf("%s", password);

// Dummy validation for demonstration
if (strcmp(username, "user") == 0 && strcmp(password, "pass") == 0) {
printf(GREEN "Login successful!\n" RESET);
} else {
printf(GOLD_BOLD "Invalid credentials.\n" RESET);
}
printf("Press Enter to continue...");
getchar(); // To consume the newline character left by scanf
getchar(); // Wait for Enter key
}

// Register function
void registerUser() {
char username[30];
char password[30];

printf("\033[H\033[J");
printf(CYAN_BOLD "======= Register =======\n" RESET);
printf("New Username: ");
scanf("%s", username);
printf("New Password: ");
scanf("%s", password);

// Dummy registration for demonstration
printf(GREEN "User registered successfully!\n" RESET);
printf("Press Enter to continue...");
getchar(); // To consume the newline character left by scanf
getchar(); // Wait for Enter key
}

// Admin function
void admin() {
char adminPassword[30];

printf("\033[H\033[J");
printf(CYAN_BOLD "======= Admin Login =======\n" RESET);
printf("Admin Password: ");
scanf("%s", adminPassword);

// Dummy admin check for demonstration
if (strcmp(adminPassword, "admin") == 0) {
printf(GREEN "Admin login successful!\n" RESET);
// Admin operations can be added here
} else {
printf(GOLD_BOLD "Invalid admin password.\n" RESET);
}
printf("Press Enter to continue...");
getchar(); // To consume the newline character left by scanf
getchar(); // Wait for Enter key
}

// Exit function
void exitProgram() {
printf("\033[H\033[J");
printf(GREEN "Thank you for using the bank system. Goodbye!\n" RESET);
printf("Press Enter to exit...");
getchar(); // To consume the newline character left by scanf
getchar(); // Wait for Enter key
}
