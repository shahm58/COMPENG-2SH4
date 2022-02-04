#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){
	int i = 0;
	int string_size = 0; //size of string

	for (i=0; source[i]!='\0';i++){ //uses for loop to find length of string
		string_size++;
	}

	if(string_size > n){ //copies string if the space in array is larger or equal to length of the string
		for (i=0; i<n-1; i++){
			destination[i] = source[i];
		}
	}

	else if (string_size == n || string_size <n){ //copies string if the length of the string is larger than the space available in the array
		for(i=0; i<string_size; i++){
			destination[i]=source[i];
		}
	}
    
}
