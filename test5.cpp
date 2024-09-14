#include <stdio.h>
#include <conio.h>
int x[11],y[10],i;

main()

{

i=0;
while (i<=10)
{
	x[i] = i+1;
	i++;
}

for (i=0; i<10; i++)
y[i] = x[i] + x[i+y[i]];

for (i=0; i<10; i++)
printf("%3d",y[i]);

printf("\n");


}
