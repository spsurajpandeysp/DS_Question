// Q14. Write a program to compute nthFibonacci number using binary recursion. *8 

#include<stdio.h>

int nthFibonacci(int n)
{
    if(n<=1)
    {
        return n;
    }
    return nthFibonacci(n-1) + nthFibonacci(n-2);

}

int main()
{
    int n;
    printf("Enter number of finding nthFibonacci number:\n");
    scanf("%d0,&n");
    int first=0;
    int second=1;

    printf("%d\n",nthFibonacci(n));

    return 0;
}