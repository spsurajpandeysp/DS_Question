// Q37. Write a program to implement ascending priority queue with following functions i)insert ii)serve iii)display (use double pointer). *26
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int priority;
    int data;
    struct node *next;
};

void insertion(struct node **front,int priority,int element)
{
    struct node *newNode,*ptr,*temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return ;
    }
    newNode->priority=priority;
    newNode->data=element;
    if(*front==NULL || priority<(*front)->priority)
    {
        newNode->next=*front;
        *front = newNode;
    }
    else
    {
        ptr=*front;
        while(ptr->next!=NULL && priority>=ptr->next->priority)
        {
            ptr=ptr->next;
        }
        newNode->next=ptr->next;
        ptr->next = newNode;
    }
}

void display(struct node *front)
{
    if(front==NULL)
    {
        printf("Queue is empty:\n");
        return ;
    }
    struct node *ptr;
    ptr = front;
    printf("Data           Data priority:-\n");
    while(ptr!=NULL)
    {
        printf("  %d       ->     %d ",ptr->data,ptr->priority);
        ptr=ptr->next;
        printf("\n");
    }
}

void serve(struct node **front)
{
    if(*front==NULL)
    {
        printf("Queue is empty:\n");
        return ;
    }
    struct node *temp;
    temp = *front;
    *front=(*front)->next;
    free(temp);
}
int main()
{
    struct node*front=NULL;
    int choice,element,priority;
    while(1)
    {
        printf("Press 1. for insertion a priority queue:\n");
        printf("Press 2. for serve from priority queue:\n");
        printf("Press 3. for display:\n");
        printf("Press 4. exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element you want to add:\n");
                scanf("%d",&element);
                printf("Enter Priority of a element:\n");
                scanf("%d",&priority);
                insertion(&front,priority,element);
                break;
            case 2:
                serve(&front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("You successfully exit from this program:\n");
                return 0;
            default:
                printf("Enter valid chooce:\n");
                break;
        }
    }
    return 0;
}
