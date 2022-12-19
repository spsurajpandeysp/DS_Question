/* Q36. Write a program to add two polynomials.  */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;
};

void displayPolynomial(struct node *head)
{
    if(head==NULL)
    {
        printf("No polynomial in linkedlsit:\n");
        return ;
    }
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d^%d ",ptr->coeff,ptr->expo);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node *createPolynomial(struct node *head)
{
    struct node *newNode,*ptr;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("MEmory not allocated:\n");
        return NULL;
    }
    newNode->next=NULL;
    printf("Enter coefficient of polynomial:\n");
    scanf("%d",&newNode->coeff);
    printf("Enter degree of coefficient:\n");
    scanf("%d",&newNode->expo);
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
struct node *additionOfTwoPolynomial(struct node *first,struct node *second,struct node *addition)
{
    struct node *newNode,*ptr1,*ptr2,*ptr3;
    if(first==NULL && second ==NULL)
    {
        printf("Addition of two polynomial is not possible because polynomial is not entered by you:\n");
        return NULL;
    }
    ptr1=first;
    ptr2=second;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->next=NULL;
        if(ptr1->expo==ptr2->expo)
        {
            newNode->expo=ptr1->expo;
            newNode->coeff=ptr1->coeff+ptr2->coeff;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->expo>ptr2->expo)
        {
            newNode->expo=ptr1->expo;
            newNode->coeff=ptr1->coeff;
            ptr1=ptr1->next;
        }
        else if(ptr1->expo<ptr2->expo)
        {
            newNode->expo=ptr2->expo;
            newNode->coeff=ptr2->coeff;
            ptr2=ptr2->next;
        }
        if(addition==NULL)
        {
            ptr3=addition=newNode;

        }
        else
        {
            ptr3->next=newNode;
            ptr3=ptr3->next;
        }
    }
    while(ptr1!=NULL || ptr2!=NULL)
    {
        newNode= (struct node*)malloc(sizeof(struct node));
        newNode->next=NULL;
        if(ptr1!=NULL)
        {
            newNode->coeff=ptr1->coeff;
            newNode->expo=ptr1->expo;
            ptr1=ptr1->next;
        }
        else if(ptr2!=NULL)
        {
            newNode->coeff=ptr2->coeff;
            newNode->expo=ptr2->expo;
            ptr2=ptr2->next;
        }
        ptr3->next=newNode;
        ptr3=ptr3->next;
    }
    return addition;
}
int main()
{
    struct node *first=NULL,*second=NULL,*addition=NULL;
    int choice;
    while(1)
    {
        printf("Press 1. for create polynomial first:\n");
        printf("Press 2. for create polynomial second:\n");
        printf("Press 3. for display polynomail first:\n");
        printf("Press 4. for display polynomail second:\n");
        printf("Press 5. for add two polynomial:\n");
        printf("Press 6. for display addittion polynomial:\n");
        printf("Press 7. for exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                first=createPolynomial(first);
                break;
            case 2:
                second=createPolynomial(second);
                break;
            case 3:
                displayPolynomial(first);
                break;
            case 4:
                displayPolynomial(second);
                break;
            case 5:
                addition=additionOfTwoPolynomial(first,second,addition);
                break;
            case 6:
                displayPolynomial(addition);
                break;
            case 7:
                printf("You successfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valis choice:\n");
                break;
        }
    }
    return 0;
}