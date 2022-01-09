#include<stdio.h>
#include<conio.h>
int factorial(int);


int main()
{
	int a;
	printf("Enter any number: \n");
	scanf("%d",&a);
	factorial(a);
	printf("\nThe factorial of number is %d",factorial(a));
	
	
 
}


int factorial(int x)
{
	
	int i,f=1;

 for(i=x;i>=1;i--)
 {
 	f=f*i;
 }
 return f;


	
}
