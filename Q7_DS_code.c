//Q 7. Write a program to multiply two 3x3 matrices. *4 
#include<stdio.h>
int main()
{
	int arr1[40][40],arr2[40][40],arr3[40][40],r1,r2,c1,c2;
	printf("Enter row  of first matrix:\n");
	scanf("%d",&r1);
	printf("Enter column of first matrix:\n");
	scanf("%d",&c1);
	printf("Enter row of first matrix:\n");
	scanf("%d",&r2);
	printf("Enter column of second matrix:\n");
	scanf("%d",&c2);
	printf("Enter element of first matrix:\n");
	for(int i=0;i<=r1-1;i++)
	{
		for(int j=0;j<=c1-1;j++)
		{
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("Enter element of second matrix:\n");
	for(int i=0;i<=r2-1;i++)
	{
		for(int j=0;j<=c2-1;j++)
		{
			scanf("%d",&arr2[i][j]);
		}
	}
	printf("First matrix is :\n");
	for(int i=0;i<=r1-1;i++)
	{
		for(int j=0;j<=c1-1;j++)
		{
			printf("%d ",arr1[i][j]);
		}
		printf("\n");
	}
	printf("Second matrix is:\n");
	for(int i=0;i<=r2-1;i++)
	{
		for(int j=0;j<=c2-1;j++)
		{
			printf("%d ",arr2[i][j]);
		}
		printf("\n");
	}
	if(r2==c1)
	{	
	    for(int i=0;i<=r1-1;i++)
	    {
	    	for(int j=0;j<=c2-1;j++)
	    	{
	    		int sum = 0;
	    		for(int k=0;k<=c1-1;k++)
	    		{
	    			sum = sum + arr1[i][k]*arr2[k][j];
				}
				arr3[i][j]=sum;
			}
		}
	}
	else
	{
		printf("Multiplication is not possible:\n");
	}
	printf("Multiplication of a matrix is:\n");
	for(int i=0;i<=r2-1;i++)
	{
		for(int j=0;j<=c2-1;j++)
		{
			printf("%d ",arr3[i][j]);
		}
		printf("\n");
	}
	return 0;
}