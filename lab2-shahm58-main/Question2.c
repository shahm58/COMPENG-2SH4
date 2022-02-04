#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"

int is_diag_dom(int mat[][N2]) {

	//this is the flag that is returned to tell whether the mat is diagonally
	int isDiag = 0;
	int counter = 0;

	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise

	for (int i = 0; i < N2; i++) {
		double element_diag = 0;
		double sum_row = 0;
		for (int j = 0; j < N2; j++) { //beginning of for loop
			if (i == j) {
				element_diag = fabs(mat[i][j]);
			} else {
				sum_row = sum_row + fabs(mat[i][j]);
			}
		}

		if (element_diag > sum_row) {
			counter++;
		}
	}
	if (counter == N2) {
		isDiag = 1;
	}

	else {
		isDiag = 0;
	}

	return isDiag; //returns 1 if the matrix is diagonally dominant and 0 otherwise

}
