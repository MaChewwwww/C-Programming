#include <stdio.h>
#include <conio.h>

int i,j;

int main()
{

for (i=1; i<=3; i++)
{
	for (j=1; j<=5; j++)
	if ((i==3)||(i==2) && (j>=2) && (j<=4)||(i==1) && (j==3))
	printf("*");
	else
	printf(" ");
	printf("\n");
}
	getch();
	return 0;
}
