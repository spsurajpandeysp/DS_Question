// Q 18. Write a menu driven program having following functionalities: input an array, output, insert an element, delete an element, sort array in 
//       ascending order, sort an array in descending order [without taking global variables]. *10
#include<stdio.h>
void input(int arr[50],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        printf("Enter element you want to insert in array:\n");
        scanf("%d",&arr[i]);
    }
}
void output(int arr[50],int n)
{

    for(int i=0;i<=n-1;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void insertionInArray(int arr[50],int n,int e,int p)
{
    for(int i=n-1;i>=p-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[p-1]=e;
}
void deletionInArray(int arr[50],int n,int p)
{
    for(int i=p-1;i<=n-2;i++)
    {
        arr[i]=arr[i+1];
    }
    printf("Element is successfully deleted:\n");
}
void sortInAscendingOrder(int arr[50],int n)
{
    int temp;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-2-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void sortInDescendingOrder(int arr[50],int n)
{
    int temp;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-2-i;j++)
        {
            if(arr[j]<arr[j+1])
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
    int choice,arr[50],n=-1,e,p;
    while(1)
    {
        printf("*-------------*--------------*-------------*------------*\n");
        printf("Press 1. for input in array:\n");
        printf("Press 2. for output in array:\n");
        printf("Press 3. for insertion in a array:\n");
        printf("Press 4. delete element from array:\n");
        printf("Press 5. for sort array in ascending order:\n");
        printf("Press 6. for sort array in descending order:\n");
        printf("Press 7. for exit this program:\n");
        printf("Enter you choice:\n");
        scanf("%d",&choice); 
        switch(choice)
        {
            case 1:
                printf("Enter how much element in array:\n");
                scanf("%d",&n);
                input(arr,n);
                break;
            case 2:
                if(n==0)
                {
                    printf("No element in array:\n");
                }
                else
                {
                    printf("Entered element in your array are:\n");
                    output(arr,n);
                }
                break;
            case 3:
                printf("Enter position where you want to insert a element:\n");
                scanf("%d",&p);
                if(p>0 && p<=n+1)
                {
                    printf("Enter element you want to insert:");
                    scanf("%d",&e);
                    insertionInArray(arr,n,e,p);
                    n++;
                }
                else
                {
                    printf("Enter valid choice:\n");
                }
                
                break;
            case 4:
                if(n<0)
                {
                    printf("No element in array:\n");
                }
                else
                {
                    printf("Enter position where tou want to delete:\n");
                    scanf("%d",&p);
                    if(p>0 && p<=n)
                    {
                        deletionInArray(arr,n,p);
                        n--;
                    }
                    else
                    {
                        printf("Enter valid position:\n");
                    }
                    break;
                }
                case 5:
                    if(n<0)
                    {
                        printf("No element in array:\n");
                    }
                    else
                    {
                        sortInAscendingOrder(arr,n);
                    }
                    break;
                case 6:
                    if(n<0)
                    {
                        printf("No element in array:\n");
                    }
                    else
                    {
                        sortInDescendingOrder(arr,n);
                    }
                    break;
                case 7:
                    printf("You successfully exit from this program:\n");
                    return 0;
                default:
                    printf("Enter valid choice:\n");
                    break;
        } 

    }
    return 0;
}