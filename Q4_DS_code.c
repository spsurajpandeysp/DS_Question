// Q4. Write a menu driven program to input a 2-D array, output it, add all its elements, add only the diagonal elements, count the number of odd
//     elements and find the largest among the elements stored. *3
#include<stdio.h>
#include<stdlib.h>
int r,c,arr[100][100];
void input()
{
	printf("Enter number of rows:\n");
	scanf("%d",&r);
	printf("Enter number of column:\n");
	scanf("%d",&c);
	for(int i=0;i<=r-1;i++)
	{
		for(int j=0;j<=c-1;j++)
		{
			printf("Enter element value row[%d], column[%d]: \n",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
}
void display()
{
	printf("Matrix is:\n");
	for(int i=0;i<=r-1;i++)
	{
		for(int j=0;j<=c-1;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
void add_element()
{
	int sum=0;
	for(int i=0;i<=r-1;i++)
	{
		for(int j=0;j<=c-1;j++)
		{
			sum=sum+arr[i][j];
		}
	}
	printf("Sum of all the element is: %d",sum);
}
void add_diagonal()
{
	if(c==r)
	{
		int dsum=0;
		for(int i=0,j=0;i<=r,j<=c-1;j++,i++)
		{
			dsum=dsum+arr[i][j];
		}
		printf("Diagonal sum is: %d\n",dsum);
	}
	else
	{
		printf("Diagonal sum is not posible: \n");
	}
}
void count_odd()
{
	int s=0;
	for(int i=0;i<=r-1;i++)
	{
		for(int j=0;j<=c-1;j++)
		{
			if((arr[i][j]%2)!=0)
			{
				s++;
			}
		}
		
	}
	printf("total number of odd element are: %d\n",s);
}
void largest_element()
{
	int max = arr[0][0];
	for(int i=0;i<=r-1;i++)
	{
		for(int j=0;j<=c-1;j++)
		{
			if(arr[i][j]>max)
			{
				max=arr[i][j];
			}
		}
	}
	printf("Largest element is: %d\n",max);
}
int main()
{
	int choice=1;
	while(choice)
	{
		printf("*-------------*----------------*-----------------*\n");
		printf("Press 1. for input: \n");
		printf("Press 2. for display: \n");
		printf("Press 3. for add all its element: \n");
		printf("Press 4. for add only diagonal element: \n");
		printf("Press 5. for count number of odd element: \n");
		printf("Press 6. for find largest element: \n");
		printf("Press 0. for exit this program: \n");
		printf("Enter your choice: \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				input();
				break;
			case 2:
				display();
				break;
			case 3:
				add_element();
				break;
			case 4:
				add_diagonal();
				break;
			case 5:
				count_odd();
				break;
			case 6:
				largest_element();
				break;	
		}
		
	}
}