// Q 29. Write a menu driven program of a linear linked list with functions: insertion at the beginning, deletion at the end, insertion between two
//       nodes, deletion of first node, deletion of last node, deletion of a node whose position is given, deletion of any node and display[without taking
//       global variables]. *21

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int linkedListTraversing(struct node *head)
{
    struct node *ptr;
    ptr=head;
    int i=0;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        i++;
    }
    return i;
}
struct node *createNode()
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    return newNode;
}
void displayLinkedList(struct node *head)
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Linked List is empty:\n");
        return ;
    }
    ptr=head;
    printf("Data in linked list are:\n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

}
struct node *insertionAtBegin(struct node *head)
{
    struct node*newNode,print;
    newNode=createNode();
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return newNode;
    }
    newNode->next=NULL;
    printf("Enter data you want to add in linked list:\n");
    scanf("%d",&newNode->data);
    newNode->next=head;
    return newNode;
}
struct node *insertionAtEnd(struct node *head)
{
    struct node *newNode,*ptr;
    newNode=createNode();
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return head;
    }
    printf("Enter data you want to add in lisnked list:\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    if(head==NULL)
    {
        return newNode;
    }
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    } 
    ptr->next=newNode;
    return head;
    
}
struct node *deletionAtBegin(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Linked List is empty:\n");
        return NULL;
    }
    temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node *deletionAtEnd(struct node *head)
{
    struct node *ptr,*temp;
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return head;
    }
    else if(head->next==NULL)
    {
        printf("%d element successfully deleted fron linked list:\n",head->data);
        free(head);
        return NULL;
    }
    ptr=head;
    while(ptr->next!=NULL)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    printf("%d element successfully deleted fron linked list:\n",ptr->data);
    temp->next=NULL;
    free(ptr);
    return head;
}
struct node *insertionAtSpecificPosition(struct node *head)
{
    struct node *newNode,*temp,*ptr;
    if(newNode==NULL)
    {
        printf("Mwmory not allocated:\n");
        return head;
    }
    int c,p;
    printf("Enter position where you want to add:\n");
    scanf("%d",&p);
    c=linkedListTraversing(head);
    if(p<=0 ||p>c+1)
    {
        printf("Enter valid position:\n");
        return head;
    }
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to add:\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    ptr=head;
    if(p==1)
    {
        newNode->next=head;
        return newNode;
    }
    for(int i=1;i<p-1;i++)
    {
        ptr=ptr->next;
    }
    if(p==c+1)
    {
        ptr->next=newNode;
        return head;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;
    return head;

}
struct node *deletionAtSpecificPosition(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return NULL;
    }
    int p,c;
    printf("Enter position whwre you want to delete node:\n");
    scanf("%d",&p);
    c=linkedListTraversing(head);
    if(p<=0 || p>c)
    {
        printf("Enter valid position:\n");
        return head;
    }
    struct node *temp,*ptr;
    if(p==1)
    {
        temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    ptr=head;
    for(int i=1;i<p-1;i++)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=ptr->next->next;
    free(temp);
    return head;
}
struct node *deletionAnyNodeAndDisplay(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return NULL;
    }
}
int main()
{
    struct node *head=NULL;
    int choice;
    while(1)
    {
        printf("Press 1. for insertion at begin:\n");
        printf("Press 2. for insertion at end:\n");
        printf("Press 3. for insertion at specific postion:\n");
        printf("Press 4. for deletion at begin:\n");
        printf("Press 5. for deletion at end:\n");
        printf("Press 6. for deletion at specific position:\n");
        printf("Press 7. for deletion of any node and display:\n");
        printf("Press 8. for display linked list:\n");
        printf("Press 9. for exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                head=insertionAtBegin(head);
                break;
            case 2:
                head=insertionAtEnd(head);
                break;
            case 3:
                head=insertionAtSpecificPosition(head);
                break;
            case 4:
                head=deletionAtBegin(head);
                break;
            case 5:
                head=deletionAtEnd(head);
                break;
            case 6:
                head=deletionAtSpecificPosition(head);
                break;
            case 7:
                head=deletionAnyNodeAndDisplay(head);
                break;
            case 8:
                displayLinkedList(head);
                break;
            case 9:
                printf("Successfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }
    }
    return 0;
}