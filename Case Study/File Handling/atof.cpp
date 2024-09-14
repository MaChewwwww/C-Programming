#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   double val; // Using double for higher precision
   char str[20];
   
   // Including the decimal part in the string
   strcpy(str, "98993489.25");
   val = atof(str);
   printf("String value = %s, Float value = %.2f\n", str, val);  // 2 decimal places
   printf("String value = %s, Float value = %.3f\n", str, val);  // 3 decimal places
   printf("String value = %s, Float value = %.4f\n", str, val);  // 4 decimal places

   strcpy(str, "tutorialspoint.com");
   val = atof(str);
   printf("String value = %s, Float value = %.2f\n", str, val);  // 2 decimal places

   return(0);
}

