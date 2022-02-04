#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]) {
	int i=0, k=0, size=0, value = 0;
	for (i = 0; word[i] != '\0'; i++) { //retrieve size of array
		size++;

	}
	for (k = 0; k <= size; k++) { //each has a corresponding value
		value = word[k];
		if (value <= 122 && value >= 97) { //if the letter is lowercase
			freq[value - 97] += 1;
		} else if (value <= 90 && value >= 65) { //if the letter is uppercase
			freq[value - 65] += 1;
		}
	}

}
