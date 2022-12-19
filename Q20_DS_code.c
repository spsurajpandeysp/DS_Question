// Q20. Write a menu driven program of a stack using array having the push, pop and display operations[without taking global variables]. *12
#include<stdio.h>
int push(int stack[],int top,int size)
{
    if(top==size-1)
    {
        printf("Stack is overflow:\n");
        return top;
    }
    top++;
    printf("Enter element you want to push:\n");
    scanf("%d",&stack[top]);
    return top;
}
void display(int stack[],int top)
{
    if(top==-1)
    {
        printf("Stack is underflow:\n");
        return ;
    }
    printf("Element are in stack:\n");
    for(int i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
}
int pop(int stack[],int top)
{
    if(top==-1)
    {
        printf("Stack is underflow:\n");
        return top;
    }
    printf("This element successfully pop: %d\n",stack[top]);
    top--;
    return top;
}
int main()
{
    int size;
    printf("Enter size of stack:\n");
    scanf("%d",&size);
    int choice,stack[size],top=-1;
    while(1)
    {
        printf("Press 1. for push operation:\n");
        printf("Press 2. for pop operation:\n");
        printf("Press 3. for display:\n");
        printf("Press 4. for exit this proram:\n");
        printf("Enter yiur choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                top=push(stack,top,size);
                break;
            case 2:
                top=pop(stack,top);
                break;
            case 3:
                display(stack,top);
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