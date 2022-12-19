//  Q33. Write a program to create a linked list P, then write a ‘C’ function named split to create two linked lists Q & R from P
//       so that Q contains all elements in odd positions of P and R contains the remaining elements. Finally print both linked 
//       lists i.e. Q and R. *24
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *P=NULL, *Q=NULL, *R=NULL;
void insertionInLinkedList()
{
    struct node *newNode,*ptr;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return ;
    }
    printf("Enter element you want to add:\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    if(P==NULL)
    {
        P=newNode;
    }
    else
    {
        ptr=P;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked List is empty:\n");
        return ;
    }
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void splitLinkedList()
{
    if(P==NULL)
    {
        printf("Linked list is empty:\n");
        return ;
    }
    struct node *newNode,*temp,*ptr1,*ptr2,*ptr3;
    int i=0;
    Q=NULL;
    R=NULL;
    ptr1=P;
    while(ptr1!=NULL)
    {
        newNode=(struct node *)malloc(sizeof(struct node));
        if(newNode==NULL)
        {
            printf("Memory not allocatde:\n");
            return ;
        }
        newNode->data=ptr1->data;
        newNode->next=NULL;
        if(i%2!=0)
        {
            if(Q==NULL)
            {
                Q=newNode;
            }
            else
            {
                ptr2=Q;
                while(ptr2->next!=NULL)
                {
                    ptr2=ptr2->next;
                }
                ptr2->next=newNode;
            } 
        }
        else
        {
            if(R==NULL)
            {
                R=newNode;
            }
            else
            {
                ptr3=R;
                while(ptr3->next!=NULL)
                {
                    ptr3=ptr3->next;
                }
                ptr3->next=newNode;
            }
        }
        i++;
        ptr1=ptr1->next;
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("Press 1. for input P linked list:\n");
        printf("Press 2. for split the linked lsit:\n");
        printf("Press 3. for dispaly P linked lsit:\n");
        printf("Press 4. for dispaly Q linked lsit:\n");
        printf("Press 5. for dispaly R linked lsit:\n");
        printf("Press 6. for exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertionInLinkedList();
                break;
            case 2:
                splitLinkedList();
                break;
            case 3:
                printf("Element of P linke list:\n");
                display(P);
                break;
            case 4:
                printf("Element of Q linked list:\n");
                display(Q);
                break;
            case 5:
                printf("Element of R linked list:\n");
                display(R);
                break;
            case 6:
                printf("you successfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }
    }
    return 0;
}