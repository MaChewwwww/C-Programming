#include <stdio.h>

struct student {
    char id[10];
    char name[15];
    float quiz_scores[3];
};

struct student students[5];

int main() {
    float total_grades_average = 0;
    float quiz_averages[3] = {0};
    float student_averages[5];

    // Input from user
    for (int i = 0; i < 5; i++) {
        printf("\n--------Student #%d Information--------\n\n", i + 1);
        printf("Enter student ID: ");
        scanf("%s", &students[i].id);
        printf("Enter student name: ");
        scanf("%s", &students[i].name);
        
        printf("\nNote: Grades range from 0.00 to 100.00\n\n");
        for (int j = 0; j < 3; j++) {
            printf("Enter quiz #%d score: ", j + 1);
            scanf("%f", &students[i].quiz_scores[j]);
            // Calculate student average
            student_averages[i] += students[i].quiz_scores[j];
        }
        
        // Calculate student average
        student_averages[i] /= 3;
        total_grades_average += student_averages[i];
    }
    
    // Calculate average scores per quiz
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 5; i++) {
            // Sum up scores for each quiz
            quiz_averages[j] += students[i].quiz_scores[j];
        }
        // Calculate average score per quiz
        quiz_averages[j] /= 5;
    }
    
    // Print output
    printf("\n\t\t\tPOLYTECHNIC UNIVERSITY OF THE PHILIPPINES\n");
    printf("\t\t\t\t   QUEZON CITY BRANCH\n\n");
    printf("\t\t\t\t\t    BSIT 1-1\n\n");
    printf("STUDENT\t\t\tSTUDENT\t\t\tQUIZ#1\t\tQUIZ#2\t\tQUIZ#3\t\tGRADE\n");
    printf("NUMBER\t\t\tNAME\t\t\t\t\t\t\t\tAVERAGE\n\n\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%s\t\t\t%s\t\t", students[i].id, students[i].name);
        for (int j = 0; j < 3; j++) {
            printf("%0.2f\t\t", students[i].quiz_scores[j]);
        }
        printf("%.02f\n", student_averages[i]);
    }
    
    printf("-------------------------------------------------------------------------------------\n");
    printf("AVERAGE:\t\t\t\t");
    
    for (int i = 0; i < 3; i++) {
        printf("%0.2f\t\t", quiz_averages[i]);
    }
    
    printf("%0.2f\n", total_grades_average);
    
    return 0;
}


