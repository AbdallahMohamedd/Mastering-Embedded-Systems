/*
 ============================================================================
 Name        : sum_of_matrix.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	////////////first matrix/////////////////
	float matrix1[50][50];
	int rows1, columns1;
	printf("Enter the number of rows for first matrix: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&rows1);
	printf("Enter the number of columns for first matrix: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&columns1);
	////////////first matrix/////////////////
	float matrix2[50][50];
	int rows2, columns2;
	printf("Enter the number of rows for second matrix: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&rows2);
	printf("Enter the number of columns for second matrix: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&columns2);
	/////////////////check////////////////////
	if(rows1!=rows2 || columns1!=columns2)
	{
		printf("sorry can NOT sum this matrix");
		return 1;
	}
	////////////get the matrix1///////////
	printf("Enter the element of first matrix \n");
	fflush(stdin);  fflush(stdout);
	for(int i=0;i<rows1;i++)
	{
		for(int k=0;k<columns1;k++)
		{
			scanf("%f",&matrix1[i][k]);
		}
	}
	////////////get the matrix2///////////
	printf("Enter the element of second matrix \n");
	fflush(stdin);  fflush(stdout);
	for(int i=0;i<rows2;i++)
	{
		for(int k=0;k<columns2;k++)
		{
			scanf("%f",&matrix2[i][k]);
		}
	}

	//////////print the matrix1/////////
	printf("the first matrix is \n");
	for(int i=0;i<rows1;i++)
	{
		for(int k=0;k<columns1;k++)
		{
			printf("%2.2f   ",matrix1[i][k]);
		}
		printf("\n");
	}
	//////////print the matrix2/////////
	printf("the second matrix is \n");
	for(int i=0;i<rows2;i++)
	{
		for(int k=0;k<columns2;k++)
		{
			printf("%2.2f   ",matrix2[i][k]);
		}
		printf("\n");
	}
	//////////sum matrix/////////
	float sum[rows1][columns1];
	printf("sum of matrix is \n");
	for(int i=0;i<rows1;i++)
	{
		for(int k=0;k<columns1;k++)
		{
			sum[i][k]=matrix1[i][k]+matrix2[i][k];
			printf("%2.2f   ",sum[i][k]);
		}
		printf("\n");
	}
	////////////////end//////////////////
}
