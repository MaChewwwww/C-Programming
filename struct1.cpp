#include <stdio.h>

struct datas {
    int student_num;
    char student_name[100];
    int quiz1;
    int quiz2;
    int quiz3;
};

struct datas data[5];

int main() {
    int stud_ave, quiz1_ave = 0, quiz2_ave = 0, quiz3_ave = 0;

    printf("\nPOLYTECHNIC UNIVERSITY OF THE PHILIPPINES\n\tQuezon City Branch\n");
    // Input student data
    for (int loop1 = 0; loop1 < 5; loop1++) {
        printf("\nEnter student number for student #%d: ", loop1 + 1);
        scanf("%d", &data[loop1].student_num);
        printf("Enter student name for student #%d: ", loop1 + 1);
        scanf(" %[^\n]", data[loop1].student_name);
        
        // Input quiz grades with validation
        printf("Enter grade for quiz #1 for student #%d: ", loop1 + 1);
        scanf("%d", &data[loop1].quiz1);
        while (data[loop1].quiz1 < 0 || data[loop1].quiz1 > 100) {
            printf("Invalid input! Grade must be between 0 and 100. Enter again: ");
            scanf("%d", &data[loop1].quiz1);
        }
        
        printf("Enter grade for quiz #2 for student #%d: ", loop1 + 1);
        scanf("%d", &data[loop1].quiz2);
        while (data[loop1].quiz2 < 0 || data[loop1].quiz2 > 100) {
            printf("Invalid input! Grade must be between 0 and 100. Enter again: ");
            scanf("%d", &data[loop1].quiz2);
        }
        
        printf("Enter grade for quiz #3 for student #%d: ", loop1 + 1);
        scanf("%d", &data[loop1].quiz3);
        while (data[loop1].quiz3 < 0 || data[loop1].quiz3 > 100) {
            printf("Invalid input! Grade must be between 0 and 100. Enter again: ");
            scanf("%d", &data[loop1].quiz3);
        }

        // Calculate totals for averages
        quiz1_ave += data[loop1].quiz1;
        quiz2_ave += data[loop1].quiz2;
        quiz3_ave += data[loop1].quiz3;
    }

    // Calculate averages
    stud_ave = (quiz1_ave + quiz2_ave + quiz3_ave) / (3 * 5);

    // Print student data in tabular format
    printf("\n+---------------+----------------------+--------+--------+--------+--------------+\n");
    printf("| Student Number| Student Name         | Quiz 1 | Quiz 2 | Quiz 3 | Grade Average|\n");
    printf("+---------------+----------------------+--------+--------+--------+--------------+\n");
    for (int loop1 = 0; loop1 < 5; loop1++) {
        stud_ave = (data[loop1].quiz1 + data[loop1].quiz2 + data[loop1].quiz3) / 3;
        printf("| %-13d | %-20s | %-6d | %-6d | %-6d | %-12d |\n", data[loop1].student_num, data[loop1].student_name,
               data[loop1].quiz1, data[loop1].quiz2, data[loop1].quiz3, stud_ave);
    }
    printf("+---------------+----------------------+--------+--------+--------+--------------+\n");
    printf("| Average :                            | %-6d | %-6d | %-6d | %-12d |\n", 
           quiz1_ave / 5, quiz2_ave / 5, quiz3_ave / 5, (quiz1_ave+quiz2_ave+quiz3_ave)/3);
    printf("+---------------+----------------------+--------+--------+--------+--------------+\n");

    return 0;
}

