#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int max = 0, loop = 0, check = 0;
	
	printf("Enter number of words to save : ");
	scanf("%d", &max);	
	if (max == 0 || max <= 0)
	{
	printf("\nPROGRAM TERMINATED!!!\nPlease enter a DIGIT\n");
	return 0;
	}
		
	char words[max][50]; 
	char search[20];	
	char test;
	for(loop=0;loop<max;loop++)
	{
		printf("Enter a word (%d) : ", loop+1);
		scanf("%19s", &words[loop]);
	}
	
	do
	{
	printf("\nEnter a word that you would like to search : ");
	scanf("%19s", &search);	
	
	int found = 0;
	for(loop=0;loop<max;loop++)
	{
		if(strcmp(search,words[loop]) == 0)
		{
		printf("\"%s\" is in the database", search);
		found = 1;
		break;
		}
	}
	printf("\nLength of selected word : %d ", (int)strlen(search));
    char searchcopy[20];
    printf("\nCopy of selected word : %s ", strcpy(searchcopy,search));
    printf("\nReverse of selected word : %s ", strrev(search));
    printf("\nConcatenation of selected word and copied word : %s ", strcat(searchcopy, search));
	
	if (found == 0)
	printf("\"%s\" is not the database", search);
	
	printf("\n\nWould you like to search for another word? (Y/N) : ");
	scanf("%s", &test);
	
	if (test == 'Y' || test == 'y')
	check = 0;
	else if (test == 'N' || test == 'n')
	check = 1;
	else
	{
	printf("\n\nPROGRAM TERMINATED!!!\nYou did not enter Y or N\n\n.");
	break;	
	}
	
	
    }    
    while(check == 0);
    
    return 0;
}
