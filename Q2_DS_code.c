//  Q2. Write a program to enter n numbers and print them using malloc() [Example of dynamic array]. *1 
#include<stdio.h>
#include<stdlib.h>
void display(int *arr,int n)
{
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\n",arr[i]);
    }
}
int main()
{
    int n,*arr;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter element you want to add:\n");
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("You array element is:\n");
    display(arr,n);
    return 0;


}