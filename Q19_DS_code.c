// Q 19. Write a program to first sort the elements stored in two arrays in ascending order and then merge them into a third array [without taking
//       global variables]. *11
#include<stdio.h>
void input(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
    {
        printf("Enter data of %d position:\n",i+1);
        scanf("%d",&arr[i]);
    }
}
void sortAscendingOrder(int arr[], int size)
{
    int temp;
    for(int i=0;i<=size-1;i++)
    {
        for(int j=0;j<=size-2-i;j++)
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
void display(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void mergeTwoSortedArray(int arr1[],int arr2[],int arr3[],int arr1_size,int arr2_size)
{
    int i = 0, j = 0, k = 0;
      while(i < arr1_size){
      arr3[k++] = arr1[i++];
    }
      while(j < arr2_size){
      arr3[k++] = arr2[j++];
      }
}
int main()
{
    int arr1_size,arr2_size,arr1[50],arr2[50],arr3[50];
    printf("Enter size of array first :\n");
    scanf("%d",&arr1_size);
    printf("Enter size of array second:\n");
    scanf("%d",&arr2_size);
    printf("Enter element of array first:\n");
    input(arr1,arr1_size);
    printf("Enter element of array second:\n");
    input(arr2,arr2_size);
    printf("Entered array first before sorting\n");
    display(arr1,arr1_size);
    printf("Entered array second before sorting:\n");
    display(arr2,arr2_size);
    sortAscendingOrder(arr1,arr1_size);
    sortAscendingOrder(arr2,arr2_size);
    printf("Entered array first after sorting in ascending order is:\n");
    display(arr1,arr1_size);
    printf("Entered array second after sorting in ascending order is:\n");
    display(arr2,arr2_size);
    mergeTwoSortedArray(arr1,arr2,arr3,arr1_size,arr2_size);
    printf("Array thired after merging array first and array second:\n");
    display(arr3,arr1_size+arr2_size);
    sortAscendingOrder(arr3,arr1_size+arr2_size);
    printf("Array thired after sorting in ascending order:\n");
    display(arr3,arr1_size+arr2_size);
    return 0;
}