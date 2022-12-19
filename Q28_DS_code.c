// Q28. Write a menu driven program of a circular queue using linked list having add, delete and display operations [without taking global 
//      variables]. *20

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *front,struct node *rear)
{
    if(rear==NULL && front==NULL)
    {
        printf("Queeu is empty:\n");
        return ;
    }
    struct node *ptr;
    ptr=front;
    do
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=front);
}
void enqueue(struct node **frontRef,struct node **rearRef)
{
    struct node *rear,*front,*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return ;
    }
    printf("Enter data you want to add in queue:\n");
    scanf("%d",&newNode->data);
    newNode->next=*frontRef;
    if(*rearRef==NULL && *frontRef==NULL)
    {
        *rearRef=newNode;
        *frontRef=newNode;
    }
    else
    {
        rear=*rearRef;
        rear->next=newNode;
        *rearRef=newNode;
    }
}
void dequeue(struct node **frontRef,struct node **rearRef)
{
    struct node *temp,*front,*rear;
    if(*rearRef==NULL && *frontRef==NULL)
    {
        printf("Queue is empty:\n");
        return ;
    }
    else if(*rearRef==*frontRef)
    {
        temp=*frontRef;
        *rearRef=NULL;
        *frontRef=NULL;
    }
    else
    {
        rear=*rearRef;
        temp=*frontRef;
        front=*frontRef;
        front=front->next;
        rear->next=front;
        *frontRef=front;
        *rearRef=rear;
    }
    free(temp);
}
int main()
{
    int choice;
    struct node *rear=NULL,*front=NULL;
    while(1)
    {
        printf("Press 1. for enqueue:\n");
        printf("PRess 2. for dequeue:\n");
        printf("Press 3. for display:\n");
        printf("Press 4. for exit this program:\n");
        printf("Entr your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue(&front,&rear);
                break;
            case 2:
                dequeue(&front,&rear);
                break;
            case 3:
                display(front,rear);
                break;
            case 4:
                printf("You successfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }

    }
    return 0;
}