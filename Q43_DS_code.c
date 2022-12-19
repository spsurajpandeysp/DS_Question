// Q 43. Write a program to implement binary search. *29
#include<stdio.h>
int main()
{
    int arr[50],n,mid,s,temp,flag=-1;
    printf("Enter how much element in array:\n");
    scanf("%d",&n);
    printf("Enter array element:\n");
    //Tanking input from user
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
    // program for output
    printf("Entered element before sorted are:\n");
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\n",arr[i]);
    }
    // program for sorting array
    for(int i=0;i<=n-1;i++)
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
    // program for output
    printf("Entered element after sorting are:\n");
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\n",arr[i]);
    }
    //Implement binary search
    printf("Enter element you want to search:\n");
    scanf("%d",&s);
    int ub=n-1;
    int lb=n-1;
    while(ub>=lb)
    {
        mid = (ub+lb)/2;
        if(arr[mid]==s)
        {
            flag = mid;
            break;
        }
        else if(arr[mid]>s)
        {
            lb=mid+1;
        }
        else if(arr[mid]<s)
        {
            ub=mid-1;
        }
    }
    if(flag==-1)
    {
        printf("Element not found:\n");
    }
    else
    {
        printf("Element found at position: %d\n",flag+1);
    }
    return 0;
}