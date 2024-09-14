#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char studentNumber[11];  // Increased by 1 to accommodate the null terminator
    char studentName[16];    // Increased by 1 to accommodate the null terminator
    char sex;
} Student;

int main() {
    FILE *originalFile, *maleFile, *femaleFile;
    int num;

    // Open the original file for writing
    originalFile = fopen("originalFile.txt", "w");
    if (originalFile == NULL) {
        printf("File cannot be created!");
        exit(1);
    }

    printf("How many records are to be recorded?: ");
    scanf("%d", &num);

    Student students[num]; // create multiple records of students

    // Get student records from the user
    for (int i = 0; i < num; i++) {
        printf("Enter student number: ");
        scanf("%s", students[i].studentNumber);
        printf("Enter student name: ");
        getchar(); // Consume the newline character left by the previous input
        scanf("%[^\n]", students[i].studentName);
        printf("Enter sex (\"M\" for male, \"F\" for female): ");
        scanf(" %c", &students[i].sex);
        students[i].sex = toupper(students[i].sex); // Ensure uppercase
        fprintf(originalFile, "%s %s %c\n", students[i].studentNumber, students[i].studentName, students[i].sex);
    }

    fclose(originalFile);

    // Reopen the original file for reading
    originalFile = fopen("originalFile.txt", "r");
    if (originalFile == NULL) {
        printf("File cannot be opened for reading!");
        exit(1);
    }

    printf("\n\tO R I G I N A L  L I S T\n\n");
    printf("Student Number\tStudent Name\tSex\n");
    printf("-----------------------------------------\n");

    Student temp;
    // Print the original list
    while (fscanf(originalFile, "%10s %15s %c\n", temp.studentNumber, temp.studentName, &temp.sex) != EOF) {
        printf("%-16s%-16s%c\n", temp.studentNumber, temp.studentName, temp.sex);
    }

    fclose(originalFile);

    // Create and write to the male students file
    maleFile = fopen("maleStudents.txt", "w");
    if (maleFile == NULL) {
        printf("File cannot be created!");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        if (students[i].sex == 'M') {
            fprintf(maleFile, "%s %s %c\n", students[i].studentNumber, students[i].studentName, students[i].sex);
        }
    }

    fclose(maleFile);

    // Reopen the male students file for reading
    maleFile = fopen("maleStudents.txt", "r");
    if (maleFile == NULL) {
        printf("File cannot be opened for reading!");
        exit(1);
    }

    printf("\n\tM A L E  S T U D E N T S\n\n");
    printf("Student Number\tStudent Name\tSex\n");
    printf("-----------------------------------------\n");

    Student tempMale;
    // Print the male students list
    while (fscanf(maleFile, "%10s %15s %c\n", tempMale.studentNumber, tempMale.studentName, &tempMale.sex) != EOF) {
        printf("%-16s%-16s%c\n", tempMale.studentNumber, tempMale.studentName, tempMale.sex);
    }

    fclose(maleFile);

    // Create and write to the female students file
    femaleFile = fopen("femaleStudents.txt", "w");
    if (femaleFile == NULL) {
        printf("File cannot be created!");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        if (students[i].sex == 'F') {
            fprintf(femaleFile, "%s %s %c\n", students[i].studentNumber, students[i].studentName, students[i].sex);
        }
    }

    fclose(femaleFile);

    // Reopen the female students file for reading
    femaleFile = fopen("femaleStudents.txt", "r");
    if (femaleFile == NULL) {
        printf("File cannot be opened for reading!");
        exit(1);
    }

    printf("\n\tF E M A L E  S T U D E N T S\n\n");
    printf("Student Number\tStudent Name\tSex\n");
    printf("-----------------------------------------\n");

    Student tempFemale;
    // Print the female students list
    while (fscanf(femaleFile, "%10s %15s %c\n", tempFemale.studentNumber, tempFemale.studentName, &tempFemale.sex) != EOF) {
        printf("%-16s%-16s%c\n", tempFemale.studentNumber, tempFemale.studentName, tempFemale.sex);
    }

    fclose(femaleFile);

    return 0;
}

