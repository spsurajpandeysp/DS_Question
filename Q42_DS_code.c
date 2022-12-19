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
int partition(int arr[],int lb,int ub)
{
    int temp;
    int start=lb+1;
    int end=ub;
    int pivot = arr[lb];
    do
    {
        while(arr[start]<pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {   
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }while(start<end);
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    return end;

}
void quickSort(int arr[],int lb,int ub)
{
    int partitionIndex;
    if(lb<ub)
    {
        partitionIndex = partition(arr,lb,ub);
        quickSort(arr,lb,partitionIndex-1);
        quickSort(arr,partitionIndex+1,ub);
    }
}
int main()
{
    int n,arr[100];
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter array element:\n");
    inputData(arr,n);
    printf("Array element before sorting:\n");
    printData(arr,n);
    quickSort(arr,0,n-1);
    printf("Array element after sorting:\n");
    printData(arr,n);
    return 0;
}