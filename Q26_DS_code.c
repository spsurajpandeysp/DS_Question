// 26. Write a menu driven program of a stack using linked list having the push, pop and display operations[without taking global variables]. *18

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *push(struct node *top)
{
    struct node *newNode,*ptr,*temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        return top;
    }
    newNode->next=NULL;
    printf("Enter data you want to add:\n");
    scanf("%d",&newNode->data);
    newNode->next=top;
    top=newNode;
}
void display(struct node *top)
{
    if(top==NULL)
    {
        printf("Stack is underflow:\n");
        return ;
    }
    struct node *ptr;
    ptr=top;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

}
struct node *pop(struct node *top)
{
    if(top==NULL)
    {
        printf("Stack is underflow:\n");
        return top;
    }
    struct node *temp;
    temp=top;
    top=top->next;
    free(temp);
    return top;
}
int main()
{
    struct node *top=NULL;
    int choice;
    while(1)
    {
        printf("Press 1. for push:\n");
        printf("Press 3. for pop:\n");
        printf("Press 3. for display:\n");
        printf("Press 4. for exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                top=push(top);
                break;
            case 2:
                top=pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("You succesfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }
    }
    return 0;
}