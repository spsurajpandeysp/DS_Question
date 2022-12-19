// Q23. Write a menu driven program of an input restricted queue. *15 
#include<stdio.h>
#define size 5
int queue[size];
int rear=-1;
int front=-1;
void display()
{
    if(rear==-1 || front ==-1)
    {
        printf("Queue is empty:\n");
        return ;
    }
    printf("Entered data in queue is:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
}
void enqueue()
{
    if(rear==size-1)
    {
        printf("Queue is full:\n");
        return ;
    }
    else if(front==-1 && rear == -1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear++;
    }
    printf("Enter data you want to add:\n");
    scanf("%d",&queue[rear]);
}
void dequeueAtFront()
{
    if(rear==-1 && front == -1)
    {
        printf("Queue is empty:\n");
        return ;
    }
    printf("%d element successfully deleted from front end:\n",queue[front]);
    if(front==rear)
    {
        rear=-1;
        front=-1;
    }
    else
    {
        front++;
    }
}
void dequeueAtRear()
{
    if(rear==-1 && front == -1)
    {
        printf("Queue is empty:\n");
        return ;
    }
    printf("%d Element successfully deleted from rear end:\n",queue[rear]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        rear--;
    }
}
int main()
{
    int choice;
    while(1)
    {
       printf("Press 1. for enqueue:\n");
       printf("Press 3. for dequeue for front:\n");
       printf("Press 3. for dequeue fo rear:\n");
       printf("Press 4. for diaplay:\n");
       printf("press 5. for exit this program:\n"); 
       printf("Enter your choice:\n");
       scanf("%d",&choice);
       switch(choice)
       {
            case 1:
                enqueue();
                break;
            case 2:
                dequeueAtFront();
                break;
            case 3:
                dequeueAtRear();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("You successfully exit from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
       }
    }
    return 0;
}