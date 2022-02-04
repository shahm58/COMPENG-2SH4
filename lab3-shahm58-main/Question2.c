#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){

	student **class_list;
	int i,k;
	FILE*fp = fopen(filename,"r"); //opens the file with the name filename

	if (fp == NULL){
		printf("Could not open the file %s\n",filename);
		exit(1);
	}

	fscanf(fp,"%d",&k);
	*sizePtr = k; //updates the size pointer
	class_list = (student **)malloc(k * (sizeof(student *))); //Allocates the memory for the amount of students
	for (i = 0; i < k;i++){
		class_list[i] = (student*)malloc(sizeof(student)); //allocates memory for one student
		fscanf(fp,"%d %s %s", &class_list[i]->student_id,class_list[i]->first_name, class_list[i]->last_name); //reads the student id, first name, and last name
		class_list[i]->project1_grade = 0;
		class_list[i]->project2_grade = 0;
		class_list[i]->final_grade = 0;
	}
	fclose(fp);
	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size){

	for (int i=0; i < size; i++){ //loops through class list
		if (list[i]->student_id==idNo)
			return i; //if the ID is present
	}
	return -1; //if the ID is not present
}

void input_grades(char *filename, student **list, int size){
	FILE*fp = fopen(filename,"r"); //opens the file with the name filename
	int index,student_id, grade1, grade2;
	if (fp == NULL){
		printf("Could not open %s\n",filename);
		exit(1);
	}
	while (fscanf(fp, "%d",&student_id) == 1){ //loops through elements in file
		fscanf(fp,"%d %d", &grade1, &grade2); //reads the student id, grade 1, and grade 2
		index = find(student_id, list, size); //checks to see if id exists
		if(index != -1){
			list[index]->project1_grade= grade1; //updates
			list[index]->project2_grade= grade2; //updates
		}
	}
	fclose(fp);


}

void compute_final_course_grades(student **list, int size){
	

	for(int i = 0; i < size; i++){
		list[i]->final_grade=(list[i]->project1_grade+list[i]->project2_grade)/2.0;
	}

}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	FILE*fp = fopen(filename,"w"); //opens the file with the name filename
	int i;
	if (fp == NULL){
		printf("Error: Could not open the file %s\n",filename);
		return;
	}
	fprintf(fp,"%d \n",size);
	for (i=0; i < size; i++){ //increments through all the students
		fprintf(fp,"%d %.2f\n",list [i]->student_id,list[i]->final_grade);

	}
	fclose(fp);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	int i;
	int discovered=0;
	for (i=0;i<*sizePtr;i++){ //increments through all students
		if (list[i]->student_id==idNo){
			discovered=1;
			break;
		}
	}
	if (discovered){
		free(list[i]); //if the Id number is discovered
		for (i=i+1;i<*sizePtr;i++){
			list[i-1]=list[i];

		}
		(*sizePtr) = (*sizePtr)-1;
		printf("Student :%d has withdrawn\n",idNo); //output if it has been discovered
	}
	else{
		printf("Student: %d does not exist\n",idNo); //output on screen if it does not exist
	}
}

void destroy_list(student **list, int *sizePtr)
{
	int i;
	for (i=0;i<*sizePtr;i++){ //loops through list to free array
		free(list[i]);
	}
	free(list); //sets size pointer to 0
	*sizePtr=0; //frees outer array
}
