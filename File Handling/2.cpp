#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char id[11];  // Increased by 1 to accommodate the null terminator
    char name[16];    // Increased by 1 to accommodate the null terminator
    char gender;
} StudentRecord;

int main() {
    FILE *inputFile, *maleOutput, *femaleOutput;
    int recordCount;

    // Open the file for writing
    inputFile = fopen("student_records.txt", "w");
    if (inputFile == NULL) {
        printf("Error: Unable to create the file!\n");
        exit(1);
    }

    printf("Enter the number of student records to be recorded: ");
    scanf("%d", &recordCount);

    StudentRecord records[recordCount]; // create multiple records of students

    // Get student records from the user
    for (int i = 0; i < recordCount; i++) {
        printf("Enter student ID: ");
        scanf("%s", records[i].id);
        printf("Enter student name: ");
        getchar(); // Consume the newline character left by the previous input
        scanf("%[^\n]", records[i].name);
        printf("Enter gender (M for male, F for female): ");
        scanf(" %c", &records[i].gender);
        records[i].gender = toupper(records[i].gender); // Ensure uppercase
        fprintf(inputFile, "%s %s %c\n", records[i].id, records[i].name, records[i].gender);
    }

    fclose(inputFile);

    // Reopen the file for reading
    inputFile = fopen("student_records.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open the file for reading!\n");
        exit(1);
    }

    printf("\n\tO R I G I N A L  R E C O R D S\n\n");
    printf("ID\t\tName\t\t\tGender\n");
    printf("------------------------------------------------\n");

    StudentRecord tempRecord;
    // Print the original list
    while (fscanf(inputFile, "%10s %15s %c\n", tempRecord.id, tempRecord.name, &tempRecord.gender) != EOF) {
        printf("%-10s\t%-20s\t%c\n", tempRecord.id, tempRecord.name, tempRecord.gender);
    }

    fclose(inputFile);

    // Create and write to the male students file
    maleOutput = fopen("male_records.txt", "w");
    if (maleOutput == NULL) {
        printf("Error: Unable to create the file!\n");
        exit(1);
    }

    for (int i = 0; i < recordCount; i++) {
        if (records[i].gender == 'M') {
            fprintf(maleOutput, "%s %s %c\n", records[i].id, records[i].name, records[i].gender);
        }
    }

    fclose(maleOutput);

    // Reopen the male students file for reading
    maleOutput = fopen("male_records.txt", "r");
    if (maleOutput == NULL) {
        printf("Error: Unable to open the file for reading!\n");
        exit(1);
    }

    printf("\n\tM A L E  R E C O R D S\n\n");
    printf("ID\t\tName\t\t\tGender\n");
    printf("------------------------------------------------\n");

    StudentRecord maleRecord;
    // Print the male students list
    while (fscanf(maleOutput, "%10s %15s %c\n", maleRecord.id, maleRecord.name, &maleRecord.gender) != EOF) {
        printf("%-10s\t%-20s\t%c\n", maleRecord.id, maleRecord.name, maleRecord.gender);
    }

    fclose(maleOutput);

    // Create and write to the female students file
    femaleOutput = fopen("female_records.txt", "w");
    if (femaleOutput == NULL) {
        printf("Error: Unable to create the file!\n");
        exit(1);
    }

    for (int i = 0; i < recordCount; i++) {
        if (records[i].gender == 'F') {
            fprintf(femaleOutput, "%s %s %c\n", records[i].id, records[i].name, records[i].gender);
        }
    }

    fclose(femaleOutput);

    // Reopen the female students file for reading
    femaleOutput = fopen("female_records.txt", "r");
    if (femaleOutput == NULL) {
        printf("Error: Unable to open the file for reading!\n");
        exit(1);
    }

    printf("\n\tF E M A L E  R E C O R D S\n\n");
    printf("ID\t\tName\t\t\tGender\n");
    printf("------------------------------------------------\n");

    StudentRecord femaleRecord;
    // Print the female students list
    while (fscanf(femaleOutput, "%10s %15s %c\n", femaleRecord.id, femaleRecord.name, &femaleRecord.gender) != EOF) {
        printf("%-10s\t%-20s\t%c\n", femaleRecord.id, femaleRecord.name, femaleRecord.gender);
    }

    fclose(femaleOutput);

    return 0;
}

