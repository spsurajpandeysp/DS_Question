// Q39. Write a program to sort a given array using selection sort.
#include<stdio.h>
void inputData(int arr[],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void printData(int arr[],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void selectionSorting(int arr[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        int minIndex=i,temp;
        for(int j=i+1;j<=n-1;j++)
        {
            if(arr[minIndex]>arr[j])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            temp = arr[minIndex];
            arr[minIndex]=arr[i];
            arr[i]=temp;
        }
    }
}
int main()
{
    int arr[10],n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    printf("Enter element of an array:\n");
    inputData(arr,n);
    printf("Array before sorting:\n");
    printData(arr,n);
    selectionSorting(arr,n);
    printf("Array after sorting:\n");
    printData(arr,n);
    return 0;
}