#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char student_id[10];
    char student_name[20];
    float score1;
    float score2;
    float score3;
} Student;

Student student;

int main() {
    FILE *dataFile;
    int numStudents, j;

    dataFile = fopen("student_info.txt", "w");
    if (dataFile == NULL) {
        printf("Error: Unable to create file.\n");
        exit(1);
    }

    printf("How many students are you entering? ");
    scanf("%d", &numStudents);

    float avgScores[numStudents];
    float quizAverages[3] = {0};
    float classAverage = 0;

    for (j = 0; j < numStudents; j++) {
        printf("Enter the name of the student: ");
        getchar();  // Consume the leftover newline character
        scanf("%[^\n]", student.student_name);
        printf("Enter the student ID: ");
        scanf("%s", student.student_id);

        // Validate score1 input
        do {
            printf("Enter score for Quiz 1 (0-100): ");
            scanf("%f", &student.score1);
            if (student.score1 < 0 || student.score1 > 100) {
                printf("Invalid input. Please enter a score between 0 and 100.\n");
            }
        } while (student.score1 < 0 || student.score1 > 100);

        // Validate score2 input
        do {
            printf("Enter score for Quiz 2 (0-100): ");
            scanf("%f", &student.score2);
            if (student.score2 < 0 || student.score2 > 100) {
                printf("Invalid input. Please enter a score between 0 and 100.\n");
            }
        } while (student.score2 < 0 || student.score2 > 100);

        // Validate score3 input
        do {
            printf("Enter score for Quiz 3 (0-100): ");
            scanf("%f", &student.score3);
            if (student.score3 < 0 || student.score3 > 100) {
                printf("Invalid input. Please enter a score between 0 and 100.\n");
            }
        } while (student.score3 < 0 || student.score3 > 100);

        avgScores[j] = (student.score1 + student.score2 + student.score3) / 3;
        classAverage += avgScores[j];
        quizAverages[0] += student.score1;
        quizAverages[1] += student.score2;
        quizAverages[2] += student.score3;

        fprintf(dataFile, "%s %s %.2f %.2f %.2f\n", student.student_name, student.student_id, student.score1, student.score2, student.score3);
    }

    quizAverages[0] /= numStudents;
    quizAverages[1] /= numStudents;
    quizAverages[2] /= numStudents;
    classAverage /= numStudents;

    fclose(dataFile);

    dataFile = fopen("student_info.txt", "r");
    if (dataFile == NULL) {
        printf("Error: Unable to open file for reading.\n");
        exit(1);
    }

    printf("\n\t\tList of Student Records\n");
    printf("Student ID\tName\t\tQuiz 1\t\tQuiz 2\t\tQuiz 3\t\tAverage\n");
    printf("------------------------------------------------------------------------------------\n");

    for (j = 0; j < numStudents; j++) {
        fscanf(dataFile, "%19s %9s %f %f %f", student.student_name, student.student_id, &student.score1, &student.score2, &student.score3);
        printf("%-10s %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n", student.student_id, student.student_name, student.score1, student.score2, student.score3, avgScores[j]);
    }

    printf("------------------------------------------------------------------------------------\n");
    printf("Quiz Averages:\t\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", quizAverages[0], quizAverages[1], quizAverages[2], classAverage);

    fclose(dataFile);

    return 0;
}

