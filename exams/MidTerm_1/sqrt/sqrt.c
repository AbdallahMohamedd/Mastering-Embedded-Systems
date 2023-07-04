#include<stdio.h>
float square_root(int n);
int main()
{
	int number;
	printf("Enter number: ");
	scanf("%d",&number);
	printf("Square root of number: %.3f",square_root(number));
}
float square_root(int number)
{
	float res,temp=0; 
	res=number/2;         
	while(res!=temp)
	{
		temp=res;
		res=(number/temp + temp)/2;
	}
	return res;
}