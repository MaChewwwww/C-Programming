#include <stdio.h>

int prime(int n1) {
    int is_prime = 1; 
    
    for(int loop1 = 2; loop1 < n1; loop1++) {
    	for(int loop2 = 2; loop2 < n1; loop2++) {
        	if(loop1 * loop2 == n1) {
        	is_prime = 0;
       		}
  	  }
    }
    
    return is_prime; // Return 1 if prime, 0 if not prime
}

int main() {
	
	
	int input = 1;
	while(input != 0){
    printf("\nEnter a number: ");
    scanf("%d", &input);
    if (input == 0)
    break;
    if(prime(input) == 1) {
        printf("\n%d is a prime number\n", input);
    } else {
        printf("\n%d is not a prime number\n", input);
    }
}

 printf("\nYou have entered \"0\". PROGRAM TERMINATED!\n");

    	

    return 0;
}


