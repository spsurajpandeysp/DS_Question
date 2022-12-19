// Q17. Write a program to delete an element from an array. 

#include<stdio.h>
void input(int arr[],int n)
{
    for(int i=0;i<=n;i++)
    {
        printf("Enter array element: %d\n",i+1);
        scanf("%d",&arr[i]);
    }
}
void display(int arr[],int n)
{
    printf("Entered element in array are:\n");
    for(int i=0;i<=n;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void deletionAtBegin(int arr[],int n)
{
    int element = arr[0];
    for(int i=0;i<=n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    printf("%d Element successfully deleted from begin:\n",element);
}
void deletionAtEnd(int arr[],int n)
{
    int element = arr[n];
    printf("%d Element successfully deleted from end:\n",element);
}
void deletionAtSpecificPosition(int arr[],int n,int p)
{
    int element = arr[p-1];
    for(int i=p-1;i<=n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    printf("%d Element successfully deleted form %d position:\n",element,p);
}

int main()
{
    int arr[50],p, n=-1;
    int choice;
    while(1)
    {
        printf("Press 1. for create array:\n");
        printf("Press 2. for deletion at begin:\n");
        printf("Press 3. for deletion at end:\n");
        printf("Press 4. deletion at specific position:\n");
        printf("Press 5. for display:\n");
        printf("Press 6. for exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter how much element you want to add in array:\n");
                scanf("%d",&n);
                n=n-1;
                input(arr,n);
                break;
            case 2:
                if(n==-1)
                {
                    printf("Array is empty:\n");
                }
                else
                {
                    deletionAtBegin(arr,n);
                    n--;
                }
                break;
            case 3:
                if(n==-1)
                {
                    printf("Array is empty:\n");
                }
                else
                {
                    deletionAtEnd(arr,n);
                    n--;
                }
                break;
            case 4:
                if(n==-1)
                {
                    printf("Array is empty:\n");
                }
                else
                {
                    printf("Enter position where you want to delete element:\n");
                    scanf("%d",&p);
                    if(p>0 && p<=n+1)
                    {
                        deletionAtSpecificPosition(arr,n,p);
                        n--;
                    }
                    else
                    {
                        printf("Enter valid position between %d to %d:\n");
                    }
                }
                break;
            case 5:
                if(n==-1)
                {
                    printf("Array is empty:\n");
                }
                else
                {
                    display(arr,n);
                }
                break;
            case 6:
                printf("Successfully exit from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }
        
    }
    return 0;
}