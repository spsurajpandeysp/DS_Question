// Q9. Write a program to find the factorial of any number using tail recursion. *5
#include<stdio.h>
int factorial(int n)
{
    if(n==1)
    {
        return n;
    }   
    return n * factorial(n-1);
}
int main()
{
    int number;
    printf("Enter number for finding factorial:\n");
    scanf("%d",&number);
    int fact;
    printf("Factorial of entered number: %d",factorial(number));
    return 0;
}