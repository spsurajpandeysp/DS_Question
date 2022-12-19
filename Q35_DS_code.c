// Q 35. Write a program of a sorted linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void creatingLinkedList()
{
    struct node *newNode,*temp,*ptr;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return ;
    }
    newNode->next=NULL;
    printf("Enter data of node you want to add:\n");
    scanf("%d",&newNode->data);
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }

}
void displayLinkedList()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return ;
    }
    ptr=head;
    printf("Entered element in linked list are:\n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

}
void sortAscendingOrder()
{
    struct node *temp,*ptr1,*ptr2;
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return ;
    }

}
void sortDescendingOrder()
{
    struct node *temp,*ptr1,*ptr2;
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return ;
    }
    ptr1=head;
    while(ptr1!=NULL)
    {
        ptr2=head;
        while(ptr2->next!=NULL)
        {
            if(ptr2->data<ptr2->next->data)
            {
                temp=ptr2;
                ptr2->next=ptr2->next->next;
                temp->next->next=ptr2;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("Press 1. for creation for a linked list:\n");
        printf("Press 2. for display int a linked list:\n");
        printf("Press 3. for sort linked list in acsending order:\n");
        printf("Press 4. for sort linked in descendinfg order:\n");
        printf("Press 5. for exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                creatingLinkedList();
                break;
            case 2:
                displayLinkedList();
                break;
            case 3:
                sortAscendingOrder();
                break;
            case 4:
                sortDescendingOrder();
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