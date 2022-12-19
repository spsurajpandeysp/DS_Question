// Q40. Write a program to sort a given array using insertion sort.
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
void insertionSorting(int arr[],int n)
{
    int key,j;
    for(int i=1;i<=n-1;i++)
    {
        key = arr[i];
        j=i-1;
        while(j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;       
    }
}
int main()
{
    int n,arr[10];
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter array element:\n");
    inputData(arr,n);
    printf("Array element before sorting:\n");
    printData(arr,n);
    insertionSorting(arr,n);
    printf("Array element after sortiong:\n");
    printData(arr,n);
    return 0;
}