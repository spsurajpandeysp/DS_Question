// Q 16. Write a program to insert an element at a given position in an array. 

#include<stdio.h>
int main()
{
    int arr[50],n=-1,p,e;
    printf("Enter number of element in a arrya:\n");
    scanf("%d",&n);
    printf("Enter array element:\n");
    // for input
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
    // for output
    printf("Array element before inserting element:\n");
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("Enter position where you want to insert an element:\n");
    scanf("%d",&p);
    printf("Enter element you want to insert at specifc position:\n");
    scanf("%d",&e);
    // insertion at specific position
    for(int i=n;i>=p-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[p-1]=e;
    // for output
    printf("Array element after insertion:\n");
    for(int i=0;i<=n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}