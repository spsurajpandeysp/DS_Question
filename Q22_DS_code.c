// Q22. Write a menu driven program of a circular queue using array having add, delete and display operations [without taking global variables]. *14

#include<stdio.h>
void display(int queue[],int front,int rear,int size)
{
    if(front==-1 && rear == -1)
    {
        printf("Queue is empty:\n");
        return ;
    }
    else if(rear<front)
    {
        for(int i=front;i<=size-1;i++)
        {
            printf("%d\n",queue[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
void enqueue(int queue[],int *front_ref,int *rear_ref,int size)
{
    if(*front_ref == 0 && *rear_ref == size-1 || *rear_ref==*front_ref-1)
    {
        printf("Queue is full:\n");
        return ;
    }
    else if(*front_ref==-1 && *rear_ref==-1)
    {
        *front_ref=0;
        *rear_ref=0;
    }
    else if(*rear_ref==size-1 && *front_ref !=0)
    {
        *rear_ref=0;
    }
    else
    {
        *rear_ref=*rear_ref+1;
    }
    printf("Enter data you want to add in circular queue:\n");
    scanf("%d",&queue[*rear_ref]);
}
void dequeue(int queue[],int *front_ref,int *rear_ref,int size)
{
    if(*front_ref==-1 && *rear_ref == -1)
    {
        printf("Queue is empty:\n");
        return;
    }
    else if(*front_ref==*rear_ref)
    {
        *front_ref=-1;
        *rear_ref=-1;
        return ;
    }
    else if(*front_ref==size-1 && *rear_ref<*front_ref)
    {
        *front_ref=0;
    }
    else
    {
        *front_ref=*front_ref+1;
    }
    
}
int main()
{
    int choice,rear=-1,front=-1,size;
    printf("Enter size of circular queue:\n");
    scanf("%d",&size);
    int queue[size];
    while(1)
    {
        printf("Press 1. for enqueue:\n");
        printf("Press 2. for dequeue :\n");
        printf("Press 3. display:\n");
        printf("Press 4. for exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue(queue,&front,&rear,size);
                break;
            case 2:
                printf("%d,%d\n",front,rear);
                dequeue(queue,&front,&rear,size);
                break;
            case 3:
                display(queue,front,rear,size);
                break;
            case 4:
                printf("You successfully exit from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }
    }
    return 0;
}