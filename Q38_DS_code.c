//  Q38. Write a program to sort a given array using bubble sort.
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
void bubbleSorting(int arr[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<=n-2-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
}
int main()
{
    int n,arr[10];
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    printf("Enter element of an array:\n");
    inputData(arr,n);
    printf("Element before sortiong:\n");
    printData(arr,n);
    bubbleSorting(arr,n);
    printf("Element after sorting:\n");
    printData(arr,n);
    return 0;
}