#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[10];
    char name[15];  // Increased size to accommodate names with spaces
    float quiz1;
    float quiz2;
    float quiz3;
} Student;

Student student;

int main() {
    FILE *file;
    int count, i;

    file = fopen("student_data.txt", "w");
    if (file == NULL) {
        printf("Error: Cannot create file.\n");
        exit(1);
    }

    printf("Enter the number of students: ");
    scanf("%d", &count);

    float studentAverages[count];
    float quizTotals[3] = {0};
    float totalAverage = 0;

    for (i = 0; i < count; i++) {
        printf("Enter student name: ");
        getchar();  // Consume the newline character left by the previous input
        scanf("%[^\n]", student.name);
        printf("Enter student ID: ");
        scanf("%s", student.id);

        // Validate Quiz 1 score input
        do {
            printf("Enter Quiz 1 score (0-100): ");
            scanf("%f", &student.quiz1);
            if (student.quiz1 < 0 || student.quiz1 > 100) {
                printf("Invalid input. Score must be between 0 and 100.\n");
            }
        } while (student.quiz1 < 0 || student.quiz1 > 100);

        // Validate Quiz 2 score input
        do {
            printf("Enter Quiz 2 score (0-100): ");
            scanf("%f", &student.quiz2);
            if (student.quiz2 < 0 || student.quiz2 > 100) {
                printf("Invalid input. Score must be between 0 and 100.\n");
            }
        } while (student.quiz2 < 0 || student.quiz2 > 100);

        // Validate Quiz 3 score input
        do {
            printf("Enter Quiz 3 score (0-100): ");
            scanf("%f", &student.quiz3);
            if (student.quiz3 < 0 || student.quiz3 > 100) {
                printf("Invalid input. Score must be between 0 and 100.\n");
            }
        } while (student.quiz3 < 0 || student.quiz3 > 100);

        studentAverages[i] = (student.quiz1 + student.quiz2 + student.quiz3) / 3;
        totalAverage += studentAverages[i];
        quizTotals[0] += student.quiz1;
        quizTotals[1] += student.quiz2;
        quizTotals[2] += student.quiz3;

        fprintf(file, "%s %s %.2f %.2f %.2f\n", student.name, student.id, student.quiz1, student.quiz2, student.quiz3);
    }

    quizTotals[0] /= count;
    quizTotals[1] /= count;
    quizTotals[2] /= count;
    totalAverage /= count;

    fclose(file);

    file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file for reading.\n");
        exit(1);
    }

    printf("\n\t\tStudent Records\n");
    printf("ID\t\tName\t\tQuiz1\t\tQuiz2\t\tQuiz3\t\tAverage\n");
    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        fscanf(file, "%49s %9s %f %f %f", student.name, student.id, &student.quiz1, &student.quiz2, &student.quiz3);
        printf("%-10s %-15s %-10.2f %-10.2f %-10.2f %-10.2f\n", student.id, student.name, student.quiz1, student.quiz2, student.quiz3, studentAverages[i]);
    }

    printf("--------------------------------------------------------------------------\n");
    printf("Averages:\t\t\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", quizTotals[0], quizTotals[1], quizTotals[2], totalAverage);

    fclose(file);

    return 0;
}

