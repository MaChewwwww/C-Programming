#include<stdio.h>
#include<conio.h>

int main()
{
	
	int number=1;
	int maxnumber;
    int sum =0;
    
    printf("\nPlease Enter the the maximum number :");
    scanf("%d", &maxnumber);
    printf("\n\nThe natural numbers are : ");
    
    for (number=1; number<=maxnumber; number++)
    { 
    printf("%d ",number);
    sum = sum + number;
    }
    printf("\n\nThe sum of all numbers is : %d", sum); 
    getch(); 
	return 0;
}


