// Q 24. Write a menu driven program of an output restricted queue. *16

#include<stdio.h>
void display(int queue[],int front,int rear)
{
    if(front == -1 && rear ==-1)
    {
        printf("Queue is empty:\n");
        return ;
    }
    printf("The data in queue is:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
}
void dequeue(int queue[],int *front_ref,int *rear_ref)
{
    if(*front_ref==-1 && *rear_ref == -1)
    {
        printf("Queue is empty:\n");
        return ;
    }
    printf("%d element successfully deleted from queue:\n",queue[*front_ref]);
    if(*front_ref==*rear_ref)
    {
        *front_ref=-1;
        *rear_ref=-1;
    }
    else
    {
        *front_ref=*front_ref+1;
    }
}
void enqueueAtFront(int queue[],int *front_ref,int *rear_ref,int size)
{
    if(*front_ref == 0 && *rear_ref == size-1)
    {
        printf("Queue is full:\n");
        return ;
    }
    else if(*front_ref == 0 && *rear_ref != size-1)
    {
        printf("Enqueue qperation at front is not possible:\n");
        return ;
    }
    else if(*front_ref ==-1 && *rear_ref ==-1)
    {
        *front_ref=size-1;
        *rear_ref=size-1;
    }
    else
    {
        *front_ref=*front_ref-1;
    }
    printf("Enter data you want to add at front:\n");
    scanf("%d",&queue[*front_ref]);
}
void enqueueAtRear(int queue[],int *front_ref,int *rear_ref,int size)
{
    if(*front_ref==0 && *rear_ref == size-1)
    {
        printf("Queue is full:\n");
        return ;
    }
    else if(*rear_ref == size-1 && *front_ref != 0)
    {
        printf("Enqueue operation not possible at rear:\n");
        return ;
    }
    else if(*rear_ref == -1 && *front_ref == -1)
    {
        *rear_ref=0;
        *front_ref=0;
    }
    else
    {
        *rear_ref=*rear_ref+1;
    }
    printf("Enter data you want add at rear end in queue:\n");
    scanf("%d",&queue[*rear_ref]);
}
int main()
{
    int size,rear=-1,front=-1;
    printf("Enter size of Queue:\n");
    scanf("%d",&size);
    int queue[size],choice;
    while(1)
    {
        printf("Press 1. for enqueue at front:\n");
        printf("Press 2. for enqueue at end:\n");
        printf("Press 3. for dequeue:\n");
        printf("Press 4. for display:\n");
        printf("Press 5. for exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueueAtFront(queue,&front,&rear,size);
                break;
            case 2:
                enqueueAtRear(queue,&front,&rear,size);
                break;
            case 3:
                dequeue(queue,&front,&rear);
                break;
            case 4:
                display(queue,front,rear);
                break;
            case 5:
                printf("Successfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valis choice:\n");
                break;
        }
    }
    return 0;
}