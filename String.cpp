#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	
	char input1[50], input2[50];;
	
	printf("Enter a String (1) : ");
	scanf("%50s", &input1);
	
	printf("\n%s length = %d", input1, strlen(input1));
	printf("\n%s reverse = %s", input1, strrev(input1));
	strrev(input1);
	printf("\nEnter a String (2) : ");
	scanf("%50s", &input2);
	
	if (strcmp(input1,input2)==0)
	printf("\nBoth string is the same");
	else
	printf("\nThe two string is different");
	
	printf("\nConcatenated version = %s", strcat(input1, input2));
	printf("\nCopied String = %s", strcpy(input1, input2));
	
	return 0;
	
}
