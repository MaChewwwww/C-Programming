#include <stdio.h>
#include <string.h>

int main() {
    int Max, loop, AMax = 0;

    printf("Enter number of students: ");
    scanf("%d", &Max);

    char name[Max][20], AA[Max][30], BCDEF[Max][30];
    int score[Max];

    for (loop = 0; loop < Max; loop++) {
        printf("\nEnter name of student (%d): ", loop + 1);
        scanf("%19s", name[loop]);
        printf("Enter score of %s: ", name[loop]);
        scanf("%d", &score[loop]);

        if (score[loop] >= 90) {
            char A[20] = " - Excellent";
            strcat(name[loop], A);
            strcpy(AA[AMax], name[loop]);
            AMax++;
        }
    }

    printf("\nList of all students:\n");
    for (loop = 0; loop < Max; loop++) {
        printf("%s\n", name[loop]);
    }

    printf("\nStudents who scored Grade A:\n");
    for (loop = 0; loop < AMax; loop++) {
        printf("%s\n", AA[loop]);
    }

    return 0;
}
