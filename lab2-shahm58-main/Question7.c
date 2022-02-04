#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
	int i = 0, j = 0, k = 0;


	while (i<k1 || j < k2){ //proceed with the statements under these conditions
		if (pos1[i] == pos2[j]){ // if pos1 and pos2 have the same pos
			pos3[k] = pos1[i];
			val3[k] = val1[i] + val2[j]; //add the two pos from array 1 and 2
			i++;
			j++;// i  and j are iterated

		}
		else if (pos1[i]<pos2[j] && i < k1){
			pos3[k] = pos1[i]; //add val and pos from array 1 to 3
			val3[k] = val1[i];
			i++;

		}
		else if (pos2[j] < pos1[i] && j < k2){
			pos3[k] = pos2[j]; //add val and pos from array 2 to 3
			val3[k] = val2[j];
			j++; //j is iterated
		}
		k++;
	}


}
