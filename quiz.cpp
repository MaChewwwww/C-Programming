#include <stdio.h>

void c_value(int n, int tab[])
{
if (n==0) return;
if(tab[n-1] < 0) 
tab[n-1]=0;

c_value(n-1,tab);
}

main()
{
int tab[4] = {-6,9,-5,3};
int number = 0;
int i;
c_value(4, tab);
for(i=0;i<4;i++)
printf("%3d", tab[i]);
return 0;
}
