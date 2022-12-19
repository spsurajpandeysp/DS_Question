// Q13. Write a program to find the maximum among array elements recursively. 

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>



void setData(int *arr,int n)
{
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void printData(int *arr, int n)
{
    for(int i=0;i<n-1;i++)
    {
        printf("%d\n",arr[i]);
    }
}

int maxElement(int list[], int position, int largest) 
    {
 
        if(position==0)
        {
            return largest;   
        }
        if (list[position] > largest)
        {
            largest = list[position];
        }
        maxElement(list, position - 1, largest);
 
    }

int main()
{
    int n,arr[100],max;
    printf("Enter how much element you want to insert:\n");
    scanf("%d",&n);

    printf("Enter array element:\n");
    setData(arr,n);

    max = arr[0];
    printf("Max element in this array is %d",maxElement(arr,n-1,max));

    return 0;
}