//  Q5. Write a program to read integers into an array and reverse those using pointers.
#include<stdio.h>
void reverse_array(int *ptr,int n)
{
	int temp;
	for(int i=0,j=n-1;j>i;i++,j--)
	{
		temp = *(ptr+i);
		*(ptr +i)= *(ptr+j);
		*(ptr+j)=temp;
	}
}
int main()
{
	int n,arr[20];
	printf("Entr range of array:\n");
	scanf("%d",&n);
	printf("Enter array element:\n");
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array after reversing:\n");
	reverse_array(arr,n);
	for(int i=0;i<=n-1;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}