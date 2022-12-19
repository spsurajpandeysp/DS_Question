// Q3. Write a program to dynamically allocate the records of n employees using calloc(). Insert the records and print them. The structure will be as
//     follows:
//     struct emp{ char name[30]; int age; double salary; }; *2 

#include<stdio.h>
#include<stdlib.h>
struct emp
{
	char name[30];
	int age;
	int salary;
};
int main()
{
	int n;
	printf("Enter number of employee:\n");
	scanf("%d",&n);
	struct emp *ptr;
	ptr = (struct emp*)calloc(n,sizeof(struct emp));
	for(int i=0;i<=n-1;i++)
	{
		printf("Enter employee name:\n");
		fflush(stdin);
		gets((ptr+i)->name);
		printf("Enter employee age:\n");
		scanf("%d",&(ptr+i)->age);
		printf("Enter emloyee salary:\n");
		scanf("%d",&(ptr+i)->salary);
	}
	for(int i=0;i<=n-1;i++)
	{
		printf("Name of employee is: %s\n",(ptr+i)->name);
		printf("Age of employee is: %d\n",(ptr+i)->age);
		printf("Salary of employee is: %d\n",(ptr+i)->salary);
	}
	return 0;
}