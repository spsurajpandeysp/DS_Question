// Q6. Write a program to calculate sum of upper triangular elements. 
#include<stdio.h>
int main()
{
	int c,r,arr[10][10],upperSum = 0;
	printf("Enter number of row in a matrix:\n");
	scanf("%d",&r);
	printf("Enter number of rows in a matrix:\n");
	scanf("%d",&c);
	printf("Enter matrix element:\n");
	for(int i=0;i<=r-1;i++)
	{
		for(int j=0;j<=c-1;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Matrix element are:\n");
	for(int i=0;i<=r-1;i++)
	{
		for(int j=0;j<=c-1;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	if(c==r)
	{
	    for(int i=0;i<=r-1;i++)
		{
			for(int j=0;j<=c-1;j++)
			{
				if(j>=i)
				{
					upperSum = upperSum  + arr[i][j];
				}
			}
		}	
		printf("The sum of upper triangular matrix is %d\n",upperSum);
	}
	else
	{
		printf("Sum of upper triangle is not possible:\n");
	}
}