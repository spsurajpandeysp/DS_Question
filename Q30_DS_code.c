// Q30. Write a menu driven program of a circular linked list with functions: insertion at the beginning, deletion at the end, insertion between two
//      nodes, deletion of first node, deletion of last node, deletion of a node whose position is given, deletion of any node and display. *22

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int traversal(struct node *head)
{
    struct node *ptr;
    int i=0;
    if(head==NULL)
    {
        return i;
    }
    ptr=head;
    do
    {
        i++;
        ptr=ptr->next;
    } while (ptr!=head);
    return i;
}
struct node *deletionAtSpecificPosition(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return NULL;
    }
    int p,c;
    struct node *temp,*ptr;
    printf("Enter position where you want to delete a node:\n");
    scanf("%d",&p);
    c=traversal(head);
    if(p<0 || p >c)
    {
        printf("Enter valid position:\n");
        return head;
    }
    ptr=head;
    if(p==1)
    {
        temp=head;
        if(c==1)
        {
            temp=head;
            return NULL;
            free(temp);
        }
        else
        {
            
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            head=head->next;
            ptr->next=head;
            free(temp);
            return head;
        }
    }
    for(int i=1;i<p-1;i++)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=ptr->next->next;
    free(temp);
    return head;
}
struct node *insertionAtBegin(struct node *head)
{
    struct node *newNode,*ptr;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return head;
    }
    printf("Enter data you want to add:\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    if(head==NULL)
    {
        newNode->next=newNode;
    }
    else
    {
        ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
        newNode->next=head;   
    }
    return newNode;
}
struct node *insertionAtEnd(struct node *head)
{
    struct node *newNode,*ptr;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return head;
    }
    printf("Enter data you want to add:\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        head->next=newNode;
        return head;
    }
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    newNode->next=head;
    return head;
}
struct node *insertionAtSpecificPosition(struct node *head)
{
    int p,c;
    printf("Enter position where you want to insert a node:\n");
    scanf("%d",&p);
    c=traversal(head);
    struct node *newNode,*ptr,*temp;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(p<1 || p>c+1)
    {
        printf("Enter valid position:\n");
        return head;
    }
    else if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return head;
    }
    printf("Enter data you want to add:\n");
    scanf("%d",&newNode->data);
    ptr=head;
    for(int i=1;i<p-1;i++)
	{
		ptr=ptr->next;
	}
	if(p==1)
	{
        ptr=head;
        if(head==NULL)
        {
            newNode->next=newNode;
            return newNode;
        }
		while(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		newNode->next=head;
		ptr->next=newNode;
        return newNode;			
	}
	else
	{
	    newNode->next=ptr->next;
		ptr->next=newNode;
        return head;
	}
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return ;
    }
    struct node *ptr;
    ptr=head;
    printf("Data in linked list are:\n");
    do
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    
}
struct node *deletionAtBegin(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return head;
    }
    else if(head==head->next)
    {
        free(head);
        return NULL;
    }
    struct node*ptr,*temp;
    temp=head;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    head=head->next;
    ptr->next=head;
    free(temp);
    return head;
}
struct node *deletionAtEnd(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked list is empty:\n");
        return head;
    }
    else if(head==head->next)
    {
        free(head);
        return NULL;
    }
    struct node *ptr,*temp;
    ptr=head;
    while(ptr->next!=head)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next = head;
    free(ptr);
    return head;
    

}
int main()
{
    struct node *head=NULL;
    int c;
    int choice;
    while(1)
    {
        printf("Press 1. for insertion at begin:\n");
        printf("Press 2. for insertion at end:\n");
        printf("Press 3. for insertion at specific position:\n");
        printf("Press 4. for deletion of first node:\n");
        printf("Press 5. for deletion of last node:\n");
        printf("Press 6. for deletion at specific position:\n");
        printf("Press 7. for delete of any node and display:\n");
        printf("Press 8. for display a linked list:\n");
        printf("Press 9. for exit this program:\n");
        printf("Enter yiur choice:\n");
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
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("You successfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }
    }
    return 0;
}