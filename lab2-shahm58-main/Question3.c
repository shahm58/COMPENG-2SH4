#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat[][N3], int arr[]) {
	int counter = 0;
	int i, k = 0;
	int row;

	for (i = 0; i < N3; i++) { //for loop for for top half that is above the diagonal
		row = i;
		for (k = 0; k <= i; k++) {
			arr[counter] = mat[row][k];
			counter++;
			row--;
		}
	}
	for (i = 1; i < N3; i++) { //for loop for the bottom half that is below the diagonal
		row = N3 - 1; //the last row in the matrix
		for (k = i; k < N3; k++) {
			arr[counter] = mat[row][k];
			counter++;
			row--;
		}
	}

}
