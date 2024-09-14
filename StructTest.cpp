#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Global Variables

//Global Structures
struct Students {
	int uid;
	char fname[40];
	char lname[40];
	//char birthday;
    char additional_subjects[12][50];
    char additional_schedule[12][30];
};


struct Section {
    char section_name[50];
    char schedule[12][30];
    struct Students stud[60];
};


struct Semester {
    struct Section sect[2];
    char sem_name[50];
    char current_subjects[12][50];
};

struct Max_Year {
    char current_year[50];
    struct Semester sem[2];
};

struct Program {
    char course[50];
    struct Max_Year year[4]; 
};

struct Curriculum {
    struct Program program[8]; 
};

struct Curriculum data;

//Functions to be used
void CourseList();
void CourseSubjects();
void EditCurriculum(int n);


int main() {
	
    int choice;
    
    // Dummy Data
    strcpy(data.program[0].course, "BSIT");
    strcpy(data.program[1].course, "Computer Science");
    strcpy(data.program[2].course, "Information Technology");
    strcpy(data.program[3].course, "Electronics Engineering");
    strcpy(data.program[4].course, "Mechanical Engineering");
    strcpy(data.program[5].course, "Civil Engineering");
    strcpy(data.program[6].course, "Architecture");
    strcpy(data.program[7].course, "Business Administration");
    
    strcpy(data.program[0].year[0].sem[0].current_subjects[0], "Math");
    strcpy(data.program[0].year[0].sem[0].current_subjects[1], "Science");
    strcpy(data.program[0].year[0].sem[0].current_subjects[2], "English");
    strcpy(data.program[0].year[0].sem[0].current_subjects[3], "Filipino");
    
    for (int loop1 = 0; loop1 < 8; loop1++) {
	   
    	for (int loop2 = 0; loop2 < 4; loop2++) { // Loop over 4 years
    	
        	for (int loop3 = 0; loop3 < 2; loop3++) {
    			strcpy(data.program[loop1].year[loop2].sem[0].sem_name, "First Semester");
    			strcpy(data.program[loop1].year[loop2].sem[1].sem_name, "Second Semester");
    		}
    	}
	}


    // Initialize dummy data for years
    for (int loop1 = 0; loop1 < 8; loop1++) {
        for (int loop2 = 0; loop2 < 4; loop2++) {
            // Initialize each year
            switch(loop2) {
                case 0:
                    strcpy(data.program[loop1].year[loop2].current_year, "First Year");
                    break;
                case 1:
                    strcpy(data.program[loop1].year[loop2].current_year, "Second Year");
                    break;
                case 2:
                    strcpy(data.program[loop1].year[loop2].current_year, "Third Year");
                    break;
                case 3:
                    strcpy(data.program[loop1].year[loop2].current_year, "Fourth Year");
                    break;
            }
            
            //Initialize dummy data for subjects
            //for (int loop3 = 0; loop3 < 12; loop3++) {
                //strcpy(data.program[loop1].year[loop2].sem[loop3].current_subjects[loop3], "Subject")
            //}
        }
    }
    
    printf("\nWelcome to Program Management System\n");
    printf("\n1. List and Select a Curriculum\n");
    printf("2. Edit the Curriculum\n");
    
    printf("\nEnter a number for your desired action : ");
    scanf("%d", &choice);
    
    // please put in a loop later on
    if (choice == 1){
        CourseList();
        char choice2;
        printf("\n\n(Y/N) Would you like to view the full programs, years, and subjects? ");
    	scanf("%s", &choice2);
    	if (choice == 'Y' || 'y') //channge this pls choice is int annd this is string
    	CourseSubjects();
    	else if (choice == 'N' || 'n')
    	return 0;
    	// to be continue
    }
    else if (choice == 2) {
        system("cls");
        CourseList();
        int editchoice;
        printf("\n\nSelect a program that you would like to Edit : ");
        scanf("%d", &editchoice);
        EditCurriculum(editchoice);
    }
    else  
    return 0;
}


void CourseList(){
	
    printf("\nThe list of all available Program in PUPQC");
    for(int loop = 0; loop < 8; loop++) {	
        printf("\n%d. %s", loop+1, data.program[loop].course);
    }
}

void CourseSubjects(){
    printf("\nThe list of all available Programs in PUPQC");

    for (int loop1 = 0; loop1 < 8; loop1++) {
    printf("\n%d. %s\n", loop1+1, data.program[loop1].course);
    
    	for (int loop2 = 0; loop2 < 4; loop2++) { // Loop over 4 years
        printf("\n%s:", data.program[loop1].year[loop2].current_year);

        	for (int loop3 = 0; loop3 < 4; loop3++) {
        		if (strcmp(data.program[loop1].year[loop2].sem[loop3].sem_name, "") != 0)
        			printf("\n%s -", data.program[loop1].year[loop2].sem[loop3].sem_name);
				for (int loop4 = 0; loop4 < 12; loop4++) { // Loop over subjects
   					if (strcmp(data.program[loop1].year[loop2].sem[loop3].current_subjects[loop4], "") != 0) {
        				printf(" %s", data.program[loop1].year[loop2].sem[loop3].current_subjects[loop4]);
       						if (loop4 < 11 ) 
           						printf(",");
    				}
				}
			}
        printf("\n");
    	}
    printf("\n");
	}
}

void EditCurriculum(int n1){
		
		n1--;
		system("cls");
        printf("\n%s Curriculum\n", data.program[n1].course);
        for(int loop2 = 0; loop2 < 4; loop2++) { // Loop over 4 years
            printf("%d. %s:", loop2+1, data.program[n1].year[loop2].current_year);
            
            for (int loop3 = 0; loop3 < 4; loop3++) {
        		if (strcmp(data.program[n1].year[loop2].sem[loop3].sem_name, "") != 0)
        			printf("\n%s -", data.program[n1].year[loop2].sem[loop3].sem_name);
        			
				for(int loop4 = 0; loop4 < 12; loop4++) { // Loop over subjects
            		if (strcmp(data.program[n1].year[loop2].sem[loop3].current_subjects[loop4], "") != 0) {
                		printf(" %s", data.program[n1].year[loop2].sem[loop3].current_subjects[loop4]);
                		if(loop3 < 11) 
        					printf(",");
        			}
        		}
        	}
        printf("\n\n");
        }
        
        int n2, n3, n4;
		int search = 0;
		char orig_subject[50], new_subject[50];
        printf("\nSelect a number for the year that you want to Edit : ");
        scanf("%d", &n2);
        printf("Select a number for semester that you would like to edit : ");
        scanf("%d", &n3);
        
        n2--;
        n3--;
        
        system("cls");
        printf("\n");
        printf("%s %s Subjects :", data.program[n1].course, data.program[n1].year[n2].current_year);
        printf("\n%s", data.program[n1].year[n2].sem[n3].sem_name);
        				
        	for (int loop = 0; loop < 12; loop++) {
   				if (strcmp(data.program[n1].year[n2].sem[n3].current_subjects[loop], "") != 0) {
        		printf("\n- %s",  data.program[n1].year[n2].sem[n3].current_subjects[loop]);	
    			}
			}
		
    	printf("\n");
    	printf("\n1. Change the name subject");
    	printf("\n2. Delete a subject");
    	printf("\n3. Add a subject");
    	printf("\n\nSelect a number for your next action : ");
        scanf("%d", &n4);
        
        if (n4 == 1){
        	printf("\nWarning : Case-Sensive!");
    		printf("\nPlease enter the exact name of the subject that you would like to rename : ");
    		scanf("%s", &orig_subject);
    		for (int loop = 0; loop < 12; loop++) {
   					if (strcmp(data.program[n1].year[n2].sem[n3].current_subjects[loop], orig_subject) == 0){
   						search=1;
        				break;
					   }
					else
					search=0;
        	}
		
			if (search == 1){
				printf("\nYou have selected the subject \"%s\".", orig_subject);
				printf("\nPlease enter the new name for the subject : ");
				scanf("%s", new_subject);
						
				int search2;
				for (int loop = 0; loop < 12; loop++) {
   					if (strcmp(data.program[n1].year[n2].sem[n3].current_subjects[loop], new_subject) == 0){
   						search2=1;
        				break;
					   }
					else
					search2=0;
        		}
        		
        		if (search2 == 1)
        			printf("\nInvalid Warning!!!\nThe name \"%s\" is not allowed because a subject with that name already exists in the database.", new_subject);
        		else{
        			printf("\nChange %s to %s", orig_subject, new_subject);	
					printf("\nPress \"Y\" to Confirm and \"N\" to Cancel : ");
					char confirm[1];
					scanf("%s", &confirm);
			
					if (strcmp(confirm, "Y") == 0 || strcmp(confirm, "y") == 0)
						printf("\nSubject name has been successfully updated!");
					else
						printf("\nChanging the name of the subject has been CANCELLED...");
				}
				
			}
			else
			printf("\nThe subject named \"%s\" is not in the database!", orig_subject);
		} // end of if
		else if (n4 == 2){
			int search3 = 0;
			printf("\nWarning : Case-Sensive!");
    		printf("\nPlease enter the exact name of the subject that you would like to delete : ");
    		scanf("%s", &orig_subject);
    		for (int loop = 0; loop < 12; loop++) {
   					if (strcmp(data.program[n1].year[n2].sem[n3].current_subjects[loop], orig_subject) == 0){
   						search3=1;
        				break;
					   }
					else
					search3=0;
        	}
        	if (search3 == 1){
				printf("\nDo you really want to delete \"%s\"?", orig_subject);
				printf("\nPress \"Y\" to Confirm and \"N\" to Cancel : ");
				char confirm[1];
				scanf("%s", &confirm);
				if (strcmp(confirm, "Y") == 0 || strcmp(confirm, "y") == 0)
					printf("\n\"%s\" has beenn successfully deleted!", orig_subject);
				else
					printf("\nDeleting process has been cancelled...");
			}
			else
			printf("\nThe subject named \"%s\" is not in the database!", orig_subject);
		}
		else if (n4 == 3){
			int search4 = 0;
			printf("\nWarning : Case-Sensive!");
    		printf("\nPlease enter the exact name of the subject that you would like to add : ");
    		scanf("%s", &new_subject);
    		for (int loop = 0; loop < 12; loop++) {
    			if (strcmp(data.program[n1].year[n2].sem[n3].current_subjects[loop], new_subject) == 0){
   					search4 = 2;
        			break;
				}
   				else if (strcmp(data.program[n1].year[n2].sem[n3].current_subjects[loop], "") == 0){
   					search4=1;
        			break;
				}	
				else
					search4=0;
        	}
        	
        	if (search4== 1){
        		printf("\nDo you really want to add \"%s\"?", new_subject);
				printf("\nPress \"Y\" to Confirm and \"N\" to Cancel : ");
				char confirm[1];
				scanf("%s", &confirm);
				if (strcmp(confirm, "Y") == 0 || strcmp(confirm, "y") == 0)
					printf("\n\"%s\" has beenn successfully added!", new_subject);
				else
					printf("\Adding process has been cancelled...");	
			}
			else if (search4 == 2){
				printf("\nInvalid Warning!!!\nThe name \"%s\" is not allowed because a subject with that name already exists in the database.", new_subject);	
			}
			else
				printf("\nCannnot add more subjects! No more slots are available. ");
		}
		
      
}


