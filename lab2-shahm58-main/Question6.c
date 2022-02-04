#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	
	int i,k = 0;
	for(i=0; i<size; i++){ //loop through the source array
		if(source[i]!=0){ //iterate through the loop to obtain non zero elements
			val[k] = source[i]; //add to new array if it is not zero
			pos[k] = i;
			k++;
		}
	}
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

	int i = 0;
	for (i=0; i<n; i++){
		source[pos[i]] = val[i]; //constructing orignal array
	}

    
	

}
