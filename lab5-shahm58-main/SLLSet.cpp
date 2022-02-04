#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet() {
	size = 0;
	head = NULL;
}

SLLSet::SLLSet(int sortedArray[], int arrSize) {

	size = arrSize;
	head = NULL;

	for (int i = size - 1; i >= 0; i--) { //moving left in the linked list
		SLLNode *node = new SLLNode(); //creating a node that has value 0 and next is null
		node->value = sortedArray[i]; //value is each item in the sorted array
		node->next = head; //the next value is the head
		head = node; //setting left most node as the head value
	}

}
int SLLSet::getSize() {

	return size; //return size of this set
}
SLLSet SLLSet::copy() {

	SLLNode *copyNode = new SLLNode(head->value, NULL); //setting variable copyNode to a new linked list
	SLLSet *copy = new SLLSet(); //creates a new set called copy
	SLLNode *temp = head; //sets variable temp as the node head

	temp = temp->next; //the node head leads to the next node
	copy->size = size; //copies the size to be the same as current set
	copy->head = copyNode; //copies the head to be the same as the current head

	while (temp != NULL) { //while the node head is not equal to NULL, which is after the node tail
		copyNode->next = new SLLNode(temp->value, NULL); //the next value will be the next value from temp
		temp = temp->next;
		copyNode = copyNode->next;

	}

	return *copy; //return the copied set
}
bool SLLSet::isIn(int v) {

	SLLNode *temp = head; //sets variable temp as the node head
	while (temp != NULL) { //while the node head is not NULL
		if (temp->value == v) { //if the head value is the same as v return true
			return true;
		}
		temp = temp->next; //continue through the next node head after the if statement
	}

	return false; //if head value does not exist then return false
}
void SLLSet::add(int v) {

	SLLNode *temp = head; //sets variable temp as the node head

	if (isIn(v) == false) { //if the head value in the previous function does not exist

		if (head == NULL) { //if the head value is NULL, meaning it is after the tail
			head = new SLLNode(v, NULL); //replace the NULL value with variable v input

		} else if (head->value > v) { //otherwise, if the head value is bigger than the v input value

			head = new SLLNode(v, head); //replace the head value with the variable v input


		} else { //in the middle

			while (temp->next != NULL) { //if the next value of the head is not NULL
				if (temp->next->value > v && temp->value < v) { //if next value is not greater than the v input value AND it is not less
					temp->next = new SLLNode(v, temp->next);
				}
				temp = temp->next; //replace temp with the next value each time it loops
			}

			//insert at the ending
			if (v > temp->value) {
				temp->next = new SLLNode(v, NULL);
			}
		}
		size++; //increase the size by 1
	}

}

void SLLSet::remove(int v) {
	SLLNode *node = head; //let variable node equal the node head

	if (isIn(v) == true) { //if the v input variable exists

		while (node && node->next) { //while the node head and the next value
			if (node->next->value == v) { //if the next nodes value is equal to the variable v input value
				node->next = node->next->next; //the next nodes value will be the next next node
			} else {
				node = node->next; //else the node value is the next node value
			}
		}

		if (head->value == v) //if the head value is equal to v
			head = head->next; //the head value will be the next head

		size--; //decrease the size of the set by  1
	}

}
SLLSet SLLSet::setUnion(SLLSet s) {

	SLLSet *unionLL = new SLLSet(); //create a new set with variable name unionLL

	if (s.head == NULL) {// if the input set head is equal to NULL
		*unionLL = copy(); //copy the set and return it
		return (*unionLL);
	}

	if (head == NULL) { //if the head is equal to NULL
		*unionLL = s.copy(); //copy the input set and return it
		return (*unionLL);
	}

	*unionLL = copy();

	while (s.head != NULL) { //iterate through the input set linked list
		(*unionLL).add(s.head->value); //add input set values to uniionLL
		size++; //increase the size by 1
		s.head = s.head->next; //the input set head will be the next head
	}

	return (*unionLL); //return the new linked list set
}
SLLSet SLLSet::intersection(SLLSet s) {

	if (s.head == NULL || head == NULL) { //if the input set or the head are equal to NULL
		SLLSet *intersecting = new SLLSet(); //create a new set with variable name intersecting and return it
		return *intersecting;
	}

	SLLSet *intersecting = new SLLSet();
	int counter = 0;

	while (s.head != NULL) { //while the input set head does not equal NULL

		if (isIn(s.head->value) == true) { //if the input s head value existence equals true

			(*intersecting).add(s.head->value); //add the input s head value into the intersecting set
			counter++; //increment by 1
		}

		s.head = s.head->next; //iterate
	}

	(*intersecting).size = counter; //if the size of the set equals the increment then return the set

	return *intersecting;

}
SLLSet SLLSet::difference(SLLSet s) {

	if (head == NULL) { //if the head equals NULL
		SLLSet different= SLLSet(); //create a new set with variable different and return it
		return different;
	}

	if (s.head == NULL) { //if the input set head equals NULL
		SLLSet different= copy(); //create a copy and return it
		return different;
	}

	SLLSet *different= new SLLSet();
	int counter = 0;

	SLLNode *temp = head; //let variable temp be the node head

	while (temp != NULL) { //while the node head does not equal NULL

		if (s.isIn(temp->value) == false) { //if the input set value existence is false
			(*different).add(temp->value); //add the temp node values to the different set
			counter++; //increment
		}

		temp = temp->next; //the temp node will be the next one each time
	}

	(*different).size = counter;

	return *different;

}
SLLSet SLLSet::setUnion(SLLSet sArray[], int size) {

	SLLSet *unionL = new SLLSet(); //create a new set with variable unionL

	for (int i = 0; i < size; i++) { //start at 0, stop when it is less than the size, and increment by 1 each time
		*unionL = (*unionL).setUnion(sArray[i]);

	}

	return *(unionL);
}
string SLLSet::toString() {
	string output;
	while (head != NULL) {
		output += to_string(head->value) + ", ";
		head = head->next;

	}

	if (!output.empty()) {
		output.resize(output.size() - 2);
	}

	return output;
}
