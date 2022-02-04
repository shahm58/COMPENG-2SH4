#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	char *z = NULL; 	//this is the pointer holding the string to return
	int len_str1 = strlen(str1); //finds length of first string
	int len_str2 = strlen(str2); //finds length of second string
	int k = len_str1 + len_str2 + 1; //variable to allocate memory through malloc()
	

	/*write your implementation here*/
	if (len_str1 == 0){
		k = len_str2 + 1; //change amount of memory if first string is empty
	}
	else if (len_str2 == 0){
		k = len_str1 + 1; //change amount of memory if second string is empty
	}

	z = malloc(k*sizeof(char)); //allocates memory with use of malloc()

	for (int i = 0; i < len_str1; i++){ //cycles through string 1 and adds it to a new variable of z
		*(z+i) = str1[i];
	}

	for (int i = len_str1; i < (len_str1 + len_str2); i++){ //cycles through string 2 and adds it to a new variable of z
		int j = i - len_str1;
		*(z+i) = str2[j];
	}

	/* finally, return the string*/
	return z;
	
}

