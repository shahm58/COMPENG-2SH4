#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"

void add_vectors(double vector1[], double vector2[], double vector3[], int size) {
	/*vector3 should store the sum of vector1 and vector2.
	 You may assume that all three arrays have the size equal to n
	 */
	//write your code below
	int i = 0;
	for (i = 0; i < size; i++) {
		vector3[i] = vector1[i] + vector2[i]; //calculate sum of two vectors of the size thats given
	}

}

double scalar_prod(double vector1[], double vector2[], int size) {
	double prod = 0; // this is the variable holding the scalar product of the two vectors


	//write your code below to calculate the prod value
	int i = 0;
	for (i = 0; i < size; i++) {
		prod += vector1[i] * vector2[i]; //calculates scalar product of two vectors of given size
	}

	return prod;	// return the result

}

double norm2(double vector1[], int size) {
	//this is the variable holding the L2 norm of the passed vector
	double L2;

	//write your code here
	for (int i=0; i<size; i++){
	// you should call function scalar_prod().
		L2 = sqrt(scalar_prod(vector1, vector1, size));
	}
	//finally, return the L2 norm 
	return L2;
}
