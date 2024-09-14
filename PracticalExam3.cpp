#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

int main()
{
		
	int Max,loop,AMax=0;	
	
	printf("Enter number of students : ");
	scanf("%d", &Max);
	printf("\n");
	
	char name[Max][50], AA[Max][50], BCDEF[Max][30];
	int score[Max];
	
	for(loop=0;loop<Max;loop++)
	{
		printf("Enter name of student (%d) : ", loop+1);
		scanf(" %[^\n]", &name[loop]);
		printf("Enter score of %s : ", name[loop]);
		scanf("%d", &score[loop]);
		printf("\n");
		
		if (score[loop]>=95)
		{			
			char A[20] = " - Amazing";
			strcat(name[loop], A);
			strcpy(AA[AMax], name[loop]);
			AMax++;
		}
		else if (score[loop] >=90 && score[loop] <= 94 )
		{			
			char A[20] = " - Excellent";
			strcat(name[loop], A);
		}
		else if (score[loop] >=85 && score[loop] <= 89 )
		{			
			char A[20] = " - Great";
			strcat(name[loop], A);
		}
		else if (score[loop] >=80 && score[loop] <= 84 )
		{			
			char A[20] = " - Good";
			strcat(name[loop], A);
		}
		else if (score[loop] >=75 && score[loop] <= 79 )
		{			
			char A[20] = " - Passed";
			strcat(name[loop], A);
		}
		else if (score[loop] <= 74 )
		{			
			char A[20] = " - Failed";
			strcat(name[loop], A);
		}
	}
	
	printf("\n**List of all students**");
	for (loop = 0; loop < Max; loop++) {
        printf("\n%s", name[loop]);
    }	
	
	printf("\n\n**(Students who score Grade A**\n");	
	for(loop=0;loop<AMax;loop++)
	{
		printf("%s\n", AA[loop]);
	}

}
