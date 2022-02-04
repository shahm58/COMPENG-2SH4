#include "../lab1-shahm58/Questions.h"

int Q1_for() {
	int sum, i;

	// calculate your sum below..this has to use for loop

	sum = 0;
	for (i = 30; i <= 1000; i++) { // sets the range to be between 30 and 1000
		if (i % 4 == 0) { // if the remainder of the number divided by 4 is 0, continue
			sum += i;
		}
	}

	// here, we return the calcualted sum:
	return sum;
}
int Q1_while() {
	int sum = 0;
	int i = 30; // sets initial condition to 30
	// calculate your sum below..this has to use while loop
	while (i <= 1000) { // sets the max range to be less than or equal to 1000
		if (i % 4 == 0) { // if the remainder of the number divided by 4 is 0, continue
			sum += i;
		}

		i++;
	}

	// here, we return the calcualted sum:
	return sum;
}
int Q1_do() {
	int sum = 0;
	int i = 30; //sets initial condition to 30

	// calculate your sum below..this has to use do-while loop
	do {
		if (i % 4 == 0) { //if the remainder of the number divided by 4 is 0, continue
			sum += i;
		}
		i++;
	} while (i <= 1000); //sets the condition that i must be less than or equal to 1000

	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input) {

	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit = 0;

	// Do your coding below to check
	if ((Q2_input >= 10000 && Q2_input < 100000) //the input must be greater than or equal to 10000 and less than 100000
	|| (Q2_input <= -10000 && Q2_input > -100000)) { //repeats the above line for negative conditions
		IsFiveDigit = 1;
	}

	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input) {

	/* Question 3: 
	 Write a program that takes a student's Q3_input as an input, which is a floating point value,
	 and returns:
	 4 if the Q3_input is in the range 90-100,
	 3 if it is in the range 80-89,
	 2 if it is in the range 70-79,
	 1 if it is in the range 60-69 and
	 0 if the Q3_input is between 0 and 59.
	 If the Q3_input is not in the range 0-100, the program shouldreturn -1
	 */
	// this is the varaible that holds the out value to return
	float GPA;

	// Do your coding below to calculate the GPA variable value

	if (Q3_input >= 90 && Q3_input <= 100) { //sets the gpa range 4 greater or equal to 90 and less than equal to 100
		GPA = 4;
	}

	else if (Q3_input >= 80 && Q3_input < 90) { //sets the gpa range 4 greater or equal to 80 and less than 90
		GPA = 3;
	}

	else if (Q3_input >= 70 && Q3_input < 80) { //sets the gpa range 4 greater or equal to 70 and less than 80
		GPA = 2;
	}

	else if (Q3_input >= 60 && Q3_input < 70) { //sets the gpa range 4 greater or equal to 60 and less than 70
		GPA = 1;
	}

	else if (Q3_input >= 0 && Q3_input < 60) { //sets the gpa range 4 greater or equal to 0 and less than 60
		GPA = 0;
	}

	else {
		GPA = -1; //if the input is in between none of the above ranges, the gpa is -1
	}

	// finally, we return the GPA
	return GPA;
}
//===============================================================================================
double Q4(int Q4_input) {

	// this is the varaible that holds the pi value to return
	double pi = 0, n = 1;

	// Do your coding below to calculate the pi value
	for (int i = 1; i <= Q4_input; i++) { //sets the initial condition of i and the condition that i must be less than or equal to the input
		if (i % 2 == 1) { //if i divided by 2 returns a remainder of 1, continue
			pi = pi + (4 / n);
		}

		else { //if the if statement cannot continue, it will come to this
			pi = pi - (4 / n);
		}
		n = n + 2;
	}

	// finally, we return the pi value
	return pi;
}
//===============================================================================================
int Q5() {

	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles = 0;

	/* Do your coding below
	 Use a triple-nested for loop that simply tries all possibilities
	 and update the total number of triples if needed
	 */

	for (int hypotenuse = 1; hypotenuse <= 400; hypotenuse++) { //
		for (int side_2 = 1; side_2 <= 400; side_2++) { //hypotenuse must be greater than side 1 and side 2
			for (int side_1 = 1; side_1 <= side_2; side_1++) {
				if ((hypotenuse * hypotenuse) // checks if hypotenuse squared meets the following conditions (as per pythagorean theorem)
				== (side_1 * side_1 + side_2 * side_2)) { // side 1 squared + side 2 squared
					totNumTribles++;
				}
			}
		}
	}

	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]) {

	//counts is teh variable that should hold the total number of found perfect numbers
	//you should update it within your code and return it at the end
	int counts = 0;
	/*
	 *
	 *perfect is an array that you need to add into it any perfect number you find
	 *which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
	 *you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will
	 *autmoatically reflect in the main calling function.
	 */

	for (int check = 2; check <= Q6_input; check++) { //sets the initial condition to 2, conditions that the input is greater or equal to the initial condition
		int tot = 0;
		for (int factor = 1; factor < check; factor++) { //every number from 1-input is checked to see if its a potential number
			if (check % factor == 0) { //if the number has no remainder, continue
				tot = tot + factor;
			}
		}
		if (check == tot) { //if the number meets the total, the number is a perfect number
			perfect[counts] = check; // store the number in an array
			counts += 1;
			continue;
		} else {
			continue;
		}
	}

	return counts;

}
//===============================================================================================
int Q7a(int Q7_input) {

	//this is the variable that holds the reversed int.
	int reversedInt = 0;

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	for (int i = 1; i <= 7; i++) {
		reversedInt = (Q7_input % 10) + (reversedInt * 10); //append the last number to the integer given
		Q7_input = (Q7_input / 10); //remove the last digiit to update the input
	}

	return reversedInt;

}
int Q7b(int Q7b_input) {

	//this is the variable that holds the reversed int.
	int reversedInt = 0;

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	int i;
	for (i = 0; Q7b_input >= 1; i++) {
		reversedInt *= 10; // append the last number to the new reversed intigger
		reversedInt += (Q7b_input % 10);

		Q7b_input /= 10; // updates the input to remove the last digit
	}

	return reversedInt;

}
