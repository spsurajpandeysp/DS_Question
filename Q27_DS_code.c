// Q27. Write a menu driven program of a queue using linked list having add, delete and display operations [without taking global variables]. *19
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void enqueue(struct node **front_ref,struct node **rear_ref)
{
    struct node *newNode,*ptr,*rear;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return ;
    }
    printf("Enter data you want to add:\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    if(*front_ref==NULL)
    {
        *rear_ref=newNode;
        *front_ref=newNode;
        return ;
    }
    rear=*rear_ref;
    rear->next=newNode;
    *rear_ref=newNode;
}
void display(struct node *front,struct node *rear)
{
    struct node *ptr;
    if(front ==NULL)
    {
        printf("Queue is empty:\n");
        return ;
    }
    ptr=front;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

}
void dequeue(struct node **front_ref,struct node **rear_ref)
{
    if(*front_ref == NULL)
    {
        printf("Queue if empty:\n");
        return ;
    }
    struct node*temp;
    temp=*front_ref;
    *front_ref=temp->next;
    if(*front_ref==NULL)
    {
        *rear_ref=NULL;
    }
    free(temp);
    

}
int main()
{
    struct node *rear=NULL,*front=NULL;
    int choice;
    while(1)
    {
        printf("Press 1. for enqueue:\n");
        printf("Press 2. for dequeue:\n");
        printf("Press 3. for display:\n");
        printf("Press 4. for exit this program:\n");
        printf("Enter your choice:\n");
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
                printf("Successfully exit from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }

    }
    return 0;
}