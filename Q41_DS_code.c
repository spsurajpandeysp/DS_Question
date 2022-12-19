/*   Q41. Write a program to sort a given array using merge sort. *27   */
#include<stdio.h>

void inputData(int *arr,int n)
{
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void printData(int *arr,int n)
{
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void merge(int arr[],int lb,int mid,int ub)
{
    int arr2[100];
    int i,j,k;
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            arr2[k]=arr[i];
            i++;
        }
        else
        {
            arr2[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        arr2[k]=arr[i];
        i++;k++;
    }
    while(j<=ub)
    {
        arr2[k]=arr[j];
        j++;k++;
    }
    for(int i=0;i<=k-1;i++)
    {
        arr[i]=arr2[i];
    }
}
void mergeSort(int arr[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid =(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
 int main()
 {
    int n,arr[10];
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter array element:\n");
    inputData(arr,n);
    printf("Array before sortion:\n");
    printData(arr,n);
    mergeSort(arr,0,n-1);
    printf("Array element after sorting:\n");
    printData(arr,n);
    return 0;
 }