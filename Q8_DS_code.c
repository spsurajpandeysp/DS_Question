// Q8. Write a program to find the factorial of any number using linear recursion.
 
#include<stdio.h>

int factNum(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    return n*factNum(n-1);
}
int main()
{
    int n;
    printf("Enter number for finding factorial:\n");
    scanf("%d",&n);

    printf("Factorial of %d is %d\n",n,factNum(n));
    return 0;
}