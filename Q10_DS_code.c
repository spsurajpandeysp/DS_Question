// Q10. Program to find sum of n natural numbers using tail recursion. 

#include<stdio.h>
int naturalNumberSum(int n)
{
    if(n==0)
    {
        return n;
    }
    printf("\n");
    return n+naturalNumberSum(n-1);
}
int main()
{
    int n; 
    printf("Enter any number for finding sum of n namtural number:\n");
    scanf("%d",&n);
    printf("The sum of n natural number is: %d\n",naturalNumberSum(n));
    return 0;
}