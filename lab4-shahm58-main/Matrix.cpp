#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix() {
	rowsNum = 3;
	colsNum = 3;
	matrixData = NULL;
	matrixData = (int**) malloc(rowsNum * sizeof(int*));

	// Allocate rows for fake "2D array":
	for (int i = 0; i < rowsNum; ++i) {
		matrixData[i] = (int*) malloc(colsNum * sizeof(int));
	}

	for (int i = 0; rowsNum > i; ++i)
		for (int j = 0; j < colsNum; ++j)
			matrixData[i][j] = 0;
}
Matrix::Matrix(int row, int col) {

	/*
	 * constructs a row-by-col matrix with
	 * all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	 * 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	 */

	rowsNum = row;
	colsNum = col;
	matrixData = NULL;

	//if the input for row and input is negative then set the value to 3
	if (rowsNum <= 0 && colsNum <= 0) {
		rowsNum = 3;
		colsNum = 3;
	} else if (rowsNum <= 0) {
		rowsNum = 3;
	} else if (colsNum <= 0) {
		colsNum = 3;
	}

	matrixData = (int**) malloc(rowsNum * sizeof(int*)); //allocate memory

	for (int i = 0; i < rowsNum; ++i) {
		matrixData[i] = (int*) malloc(colsNum * sizeof(int)); //allocate
	}

	for (int i = 0; i < rowsNum; i++) {
		for (int j = 0; j < colsNum; j++) {
			matrixData[i][j] = 0; //the elements in the array are set to 0
		}
	}

}

Matrix::Matrix(int row, int col, int **table) {

	/*
	 * constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	 * element in each position as array table.
	 */
	rowsNum = row;
	colsNum = col;
	matrixData = NULL;
	matrixData = (int**) malloc(rowsNum * sizeof(int*)); //allocate memory

	for (int i = 0; i < rowsNum; ++i) {
		matrixData[i] = (int*) malloc(colsNum * sizeof(int)); //allocate memory
	}

	for (int i = 0; i < rowsNum; ++i) {
		for (int j = 0; j < colsNum; ++j) {

			//increment pointer to point to each respective element from 2d table array
			matrixData[i][j] = *(*(table + i) + j); //assign to this matrix
		}
	}

}

int Matrix::getElement(int i, int j) {

	//return element on row i and col j

	int result = 0;

	if ((i >= rowsNum || i < 0) || (j < 0 || j >= colsNum)) { //checks if number is outside the indices

		throw std::out_of_range("Invalid indexes."); //return error
		return -1;
	} else { //
		result = matrixData[i][j]; //assign from matrix to variable "result"
		return result; //return result

	}

}

bool Matrix::setElement(int x, int i, int j) {

	if ((i >= rowsNum || i < 0) || (j < 0 || j >= colsNum)) { //error handling
		return false; //if row or column value is out of bounds then return false
	} else {
		matrixData[i][j] = x; //set the element to value of x
		return true;

	}

}

Matrix Matrix::copy() {

	//this code creates a deep copy of this matrix

	Matrix copy = Matrix(rowsNum, colsNum); //makes two of the same matrix

	for (int i = 0; i < rowsNum; i++) {
		for (int j = 0; j < colsNum; j++) {
			/*
			 *call getElement function to return the elements from this matrix and
			 *call setElement for object copy
			 *to assign the returned values from this matrix to the object "copy"
			 */
			copy.setElement(getElement(i, j), i, j);

		}
	}

	return copy;

}

void Matrix::addTo(Matrix m) {

	int result = 0;

	if ((m.rowsNum != rowsNum) || (m.colsNum != colsNum)) { //checks if matrices don't have the same dimensions return error
		throw std::invalid_argument("Invalid operation");
	} else {
		for (int i = 0; i < rowsNum; i++) {
			for (int j = 0; j < colsNum; j++) {

				/*getElement -> returns the elements from this matrix
				 * m.getElement -> returns the elements from Matrix m
				 */

				result = (getElement(i, j) + m.getElement(i, j)); //add elements together, previous and new one
				setElement(result, i, j); //updates new elements

			}
		}
	}

}

Matrix Matrix::subMatrix(int i, int j) {

	//this method returns a new matrix object with the assigned row and col values from this matrix
	//creates a submatrix

	Matrix subM = Matrix(i + 1, j + 1); //new matrix subM with size of row and col

	if ((i >= rowsNum || i < 0) || (j < 0 || j >= colsNum)) {
		throw std::out_of_range("Submatrix not defined"); //error message
	} else {

		for (int k = 0; k < i + 1; k++) {
			for (int l = 0; l < j + 1; l++) {

				/*TO CREATE SUBMATRIX:
				 * getElement -> returns the elements from this matrix
				 * subM.setElement -> assigns the returned elements from this matrix
				 * to the Matrix object subM
				 */

				subM.setElement(getElement(k, l), k, l);

			}
		}

	}

	return subM; //return object
}

int Matrix::getsizeofrows() {

	/* update below return */
	return -1;
}

int Matrix::getsizeofcols() {

	/* update below return */
	return -1;
}

bool Matrix::isUpperTr() {

	for (int i = 1; i < rowsNum; i++) {
		for (int j = 0; j < i; j++) {
			if (matrixData[i][j] != 0) {
				return false; //if array is not upper triangular has to be zeros, return false
			}

		}
	}

	return true; //if upper triangular, return true
}

string Matrix::toString() {

	//this method returns a string representing a matrix
	string output;

	for (int i = 0; i < rowsNum; ++i) {
		for (int j = 0; j < colsNum; ++j) {
			//converts to string and separates elements by 1 space,
			output += to_string(matrixData[i][j]) + " ";
		}
		output += "\n"; //row contains new line
	}

	//return output;
	return output;
}
