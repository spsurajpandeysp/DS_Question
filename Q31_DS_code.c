/*  Q31. Write a menu driven program of a doubly linked list with functions: insertion at the beginning, deletion at the end, insertion between two 
         nodes, deletion of first node, deletion of last node, deletion of a node whose position is given, deletion of any node and display[without taking 
         global variables]. *23    
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
int traverse(struct node *head)
{
    struct node *ptr;
    ptr=head;
    int i=0;
    while(ptr!=NULL)
    {
        i++;
        ptr=ptr->next;
    }
    return i;
}
void insertionAtSpecificPosition(struct node **head_ref,struct node **tail_ref)
{
    int p,c;
    struct node *newNode,*ptr,*temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter position where you want to insert a node:\n");
    scanf("%d",&p);
    c=traverse(*head_ref);
    if(p<1 || p>c+1)
    {
        printf("Enter valid position:\n");
        return ;
    }
    else if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return ;
    }
    printf("Enter data you want to add:\n");
    scanf("%d",&newNode->data);
    newNode->next=newNode->prev=NULL;
    if(p==1)
    {
        if(*head_ref==NULL && *tail_ref==NULL)
        {
            *head_ref=*tail_ref=newNode;
        }
        else
        {
            newNode->next=*head_ref;
            (*head_ref)->prev=newNode;
            *head_ref=newNode;
        }
    }
    else if(p==c+1)
    {
        (*tail_ref)->next=newNode;
        newNode->prev=*tail_ref;
        *tail_ref=newNode;
    }
    else
    {
        ptr=*head_ref;
        for(int i=1;i<p-1;i++)
        {
            ptr=ptr->next;
        }
        ptr->next->prev=newNode;
        newNode->next=ptr->next;
        ptr->next=newNode;
        newNode->prev=ptr;
    }

}
void deletionAtSpecificPosition(struct node **head_ref,struct node **tail_ref)
{
    if(*head_ref==NULL && *tail_ref==NULL)
    {
        printf("Linked list is empty:\n");
        return ;
    }
    struct node *temp,*ptr;
    int p,c;
    c=traverse(*head_ref);
    printf("Enter position where you want to add node:\n");
    scanf("%d",&p);
    if(p<1 || p>c)
    {
        printf("Please enter valid position:\n");
        return ;
    }
    else if(p==1)
    {
        temp=*tail_ref;
        if(*head_ref==*tail_ref)
        {
            *head_ref=*tail_ref=NULL;
        }
        else
        {
            temp=*head_ref;
            *head_ref=(*head_ref)->next;
            (*head_ref)->prev=NULL;
        }
    }
    else if(p==c)
    {
        temp=*head_ref;
        if(*head_ref==*tail_ref)
        {
            *head_ref=*tail_ref=NULL;
        }
        else
        {
            *tail_ref=(*tail_ref)->prev;
            (*tail_ref)->next=NULL;
        }
    }
    else
    {
        ptr=*head_ref;
        for(int i=1;i<p-1;i++)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=ptr->next->next;
        ptr->next->prev=ptr;
    }
    free(temp);
}
void insertionAtBegin(struct node **head_ref,struct node **tail_ref)
{
    struct node *newNode,*head,*tail,*ptr;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return ;
    }
    printf("Enter element you want to add:\n");
    scanf("%d",&newNode->data);
    newNode->next=newNode->prev=NULL;
    if(*head_ref==NULL && *tail_ref==NULL)
    {
        *head_ref=*tail_ref=newNode;
        return ;
    }
    newNode->next=*head_ref;
    (*head_ref)->prev=newNode;
    *head_ref=newNode;

}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return ;
    }
    struct node *ptr;
    printf("Your element in linked list are:\n");
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void displayInReverseOrder(struct node *tail)
{
    if(tail==NULL)
    {
        printf("Linked list is empty:\n");
        return ;
    }
    printf("You element in reverse orde:\n");
    struct node *ptr;
    ptr=tail;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->prev;
    }
}
void insertionAtEnd(struct node **head_ref,struct node **tail_ref)
{
    struct node *newNode,ptr;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return ;
    }
    printf("Enter data you wannt to add:\n");
    scanf("%d",&newNode->data);
    newNode->next=newNode->prev=NULL;
    if(*head_ref==NULL && *tail_ref==NULL)
    {
        *head_ref=*tail_ref=newNode;
        return ;
    }
    newNode->prev=*tail_ref;
    (*tail_ref)->next=newNode;
    *tail_ref=newNode;
}
void deletionAtBegin(struct node **head_ref,struct node **tail_ref)
{
    struct node *temp,*ptr;
    if(*head_ref==NULL && *tail_ref==NULL)
    {
        printf("Linked list is empty:\n");
        return;
    }
    else if(*head_ref==*tail_ref)
    {
        temp=*head_ref;
        *head_ref=*tail_ref=NULL;
        free(temp);
        return ;
    }
    temp=*head_ref;
    *head_ref=(*head_ref)->next;
    (*head_ref)->prev=NULL;
    free(temp);
}
void deletionAtEnd(struct node **head_ref,struct node **tail_ref)
{
    struct node *temp,*ptr;
    if(*head_ref==NULL && *tail_ref==NULL)
    {
        printf("Linked list is empty:\n");
        return ;
    }
    else if(*head_ref==*tail_ref)
    {
        temp=*tail_ref;
        *head_ref=*tail_ref=NULL;
        free(temp);
        return ;
    }
    temp=*tail_ref;
    *tail_ref=(*tail_ref)->prev;
    (*tail_ref)->next=NULL;
    free(temp);
}
int main()
{
    struct node *head=NULL,*tail=NULL;
    int choice;
    while(1)
    {
        printf("Press 1. for insertion at begin:\n");
        printf("Press 2. for insertion at last:\n");
        printf("Press 3. for insertion at specific position:\n");
        printf("Press 4. for deletion at begin:\n");
        printf("Press 5. for deletion at end:\n");
        printf("Press 6. for deletion at specific position:\n");
        printf("Press 7. for deletion of any node and display:\n");
        printf("Press 8. for display:\n");
        printf("Press 9. for print reverse order:\n");
        printf("Press 1. for exit from this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertionAtBegin(&head,&tail);
                break;
            case 2:
                insertionAtEnd(&head,&tail);
                break;
            case 3:
                insertionAtSpecificPosition(&head,&tail);
                break;
            case 4:
                deletionAtBegin(&head,&tail);
                break;
            case 5:
                deletionAtEnd(&head,&tail);
                break;
            case 6:
                deletionAtSpecificPosition(&head,&tail);
                break;
            case 7:
                break;
            case 8:
                display(head);
                break;
            case 9:
                displayInReverseOrder(tail);
                break;
            case 10:
                printf("You successfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }
    }
    return 0;
}
