#include <stdio.h>

struct Student {
    int student_num;
    char student_name[100];
    int quiz1;
    int quiz2;
    int quiz3;
};

int main() {
    struct Student students[5];
    int num_students = 0;

    while (num_students < 5) {
        printf("\nEnter student number for student #%d: ", num_students + 1);
        scanf("%d", &students[num_students].student_num);

        printf("Enter student name for student #%d: ", num_students + 1);
        scanf(" %[^\n]", students[num_students].student_name);

        printf("Enter grade for quiz #1 for student #%d: ", num_students + 1);
        scanf("%d", &students[num_students].quiz1);
        while (students[num_students].quiz1 < 0 || students[num_students].quiz1 > 100) {
            printf("Invalid input! Grade must be between 0 and 100. Enter again: ");
            scanf("%d", &students[num_students].quiz1);
        }

        printf("Enter grade for quiz #2 for student #%d: ", num_students + 1);
        scanf("%d", &students[num_students].quiz2);
        while (students[num_students].quiz2 < 0 || students[num_students].quiz2 > 100) {
            printf("Invalid input! Grade must be between 0 and 100. Enter again: ");
            scanf("%d", &students[num_students].quiz2);
        }

        printf("Enter grade for quiz #3 for student #%d: ", num_students + 1);
        scanf("%d", &students[num_students].quiz3);
        while (students[num_students].quiz3 < 0 || students[num_students].quiz3 > 100) {
            printf("Invalid input! Grade must be between 0 and 100. Enter again: ");
            scanf("%d", &students[num_students].quiz3);
        }

        num_students++;
    }

    printf("\n+---------------+----------------------+--------+--------+--------+--------------+\n");
    printf("| Student Number| Student Name         | Quiz 1 | Quiz 2 | Quiz 3 | Grade Average|\n");
    printf("+---------------+----------------------+--------+--------+--------+--------------+\n");

    int quiz1_total = 0, quiz2_total = 0, quiz3_total = 0;
    for (int i = 0; i < 5; i++) {
        printf("| %-13d | %-20s | %-6d | %-6d | %-6d | %-12.2f |\n", students[i].student_num, students[i].student_name,
               students[i].quiz1, students[i].quiz2, students[i].quiz3,
               (float)(students[i].quiz1 + students[i].quiz2 + students[i].quiz3) / 3);
        
        quiz1_total += students[i].quiz1;
        quiz2_total += students[i].quiz2;
        quiz3_total += students[i].quiz3;
    }
    printf("+---------------+----------------------+--------+--------+--------+--------------+\n");

    float quiz1_average = (float)quiz1_total / 5;
    float quiz2_average = (float)quiz2_total / 5;
    float quiz3_average = (float)quiz3_total / 5;
    float overall_average = (quiz1_total + quiz2_total + quiz3_total) / 15.0;

    printf("| Average :                            | %-6.2f | %-6.2f | %-6.2f | %-12.2f |\n", 
           quiz1_average, quiz2_average, quiz3_average, overall_average);
    printf("+---------------+----------------------+--------+--------+--------+--------------+\n");

    return 0;
}


