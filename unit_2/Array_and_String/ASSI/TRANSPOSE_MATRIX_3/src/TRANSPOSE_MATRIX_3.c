/*
 ============================================================================
 Name        : transpose_matrix.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
int main(void)
{
	int matrix[50][50];
	int rows, columns;
	printf("Enter the number of rows: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&rows);
	printf("Enter the number of columns: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&columns);
	////////////get the matrix///////////
	printf("Enter the elementS\n");
	for(int i=0;i<rows;i++)
	{
		for(int k=0;k<columns;k++)
		{
			printf("Enter the element a%d%d: ",i,k);
			fflush(stdin);  fflush(stdout);
			scanf("%d",&matrix[i][k]);
		}
	}
	//////////print the matrix/////////
	printf("the matrix is \n");
	for(int i=0;i<rows;i++)
	{
		for(int k=0;k<columns;k++)
		{
			printf("%d ",matrix[i][k]);
		}
		printf("\n");
	}
	//////////transpose the matrix/////////
	printf("transpose of matrix is \n");
	for(int i=0;i<columns;i++)
	{
		for(int k=0;k<rows;k++)
		{
			printf("%d ",matrix[k][i]);
		}
		printf("\n");
	}
	////////////////end//////////////////
}
