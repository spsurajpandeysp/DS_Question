// Q21. Write a menu driven program of a queue using array having add, delete and display operations [without taking global variables]. *13 
#include<stdio.h>
void display(int queue[],int front,int rear)
{
    if(front==-1 && rear ==-1)
    {
        printf("Queue is empty:\n");
        return ;
    }
    printf("Element in queue are:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
}
void enqueue(int queue[],int *front_ref,int *rear_ref,int size)
{
    if(*rear_ref==size-1)
    {
        printf("Queue is full:\n");
        return ;
    }
    int rear=*rear_ref;
    int front=*front_ref;
    if(front==-1 && rear ==-1)
    {
        *front_ref=0;
    }
    *rear_ref=*rear_ref+1;
    printf("Enter data you want to add in queue:\n");
    scanf("%d",&queue[*rear_ref]);

    return ;
}
void dequeue(int queue[],int *front_ref,int *rear_ref)
{
    if(*front_ref ==-1 && *rear_ref==-1)
    {
        printf("Queue is empty:\n");
        return ;
    }
    printf("%d is successfully dequeue:\n",queue[*front_ref]);
    if(*rear_ref == *front_ref)
    {
        *rear_ref=-1;
        *front_ref=-1;
    }
    else
    {
        *front_ref=*front_ref+1;
    }
}
int main()
{
    int choice,size,rear=-1,front=-1;
    printf("Enter size of queue:\n");
    scanf("%d",&size);
    int queue[size];
    while(1)
    {
        printf("Press 1, for enqueue:\n");
        printf("Press 2. for dequeue:\n");
        printf("Press 3. for display:\n");
        printf("Press 4. exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue(queue,&front,&rear,size);
                break;
            case 2:
                dequeue(queue,&front,&rear);
                break;
            case 3:
                display(queue,front,rear);
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