/*
 ============================================================================
 Name        : Store_Student_degree.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main()
{
	int n_student;
	printf("Enter number of student ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n_student);
	////////////////////////////////////
	float degree [n_student];
	for (int i=1;i<=n_student;i++)
	{
		printf("Enter student %d degree ",i);
		fflush(stdin); fflush(stdout);
		scanf("%f",&degree[i]);
	}
	for (int i=1;i<=n_student;i++)
	{
		printf("student %d degree is %f\n",i,degree[i]);
	}
}
