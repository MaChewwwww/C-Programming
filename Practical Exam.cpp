#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {

	// Declaration of variable to be used
	int loop;
    int score[5];
    float sum;
    float ave;
	
	//Loop for getting the input
    for(loop = 0; loop<5; loop++)
	{
		pf("Please Enter Score of student #%d:", loop+1);
		sf("%d",&score[loop]);
		sum = sum + score[loop];
		ave = sum / 5;
	}

   
   pf("\nScores are :");
 
   //loop for printing the scores
   for(loop = 0; loop<5; loop++)
   {  
   pf(" %d", score[loop]);
   if (loop<4)
   pf(",");
   }
   
   pf("\nAverage scores of the class : %.2f\n", ave);
   pf("\nStudents that are above average :\n");
   
   //loop for printing the students who scored aboved average
   for(loop = 0; loop<5; loop++)
   {  
   if(score[loop]>ave)
   pf("Student #%d got %d\n", loop+1, score[loop]);
   }
    
    return 0;
}



