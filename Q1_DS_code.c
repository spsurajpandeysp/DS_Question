// Q1. Write a program to store n elements in an array, and then check how many elements are palindrome numbers in that array. 
#include<stdio.h>

int palindrome(int element)
{
    int reverse=0,n,r;
    n=element;

    while(n>0)
    {
        r = n%10;
        reverse = r +(reverse*10);
        n=n/10;
    }
    return reverse;
}

void inputData(int *arr, int n)
{
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void printData(int *arr, int n)
{
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    int n,arr[100],reverse,count=0;
    printf("Enter how much element you want to insert in array:\n");
    scanf("%d",&n);

    printf("Enter element you want to insert in array:\n");
    inputData(arr,n);

    printf("Array element are:\n");
    printData(arr,n);

    for(int i=0;i<=n-1;i++)
    {
        reverse = palindrome(arr[i]);
        if(reverse==arr[i])
        {
            count++;
        }
    }
    printf("%d element are palindrom:\n",count);
    return 0;
}