#include<stdio.h>
#include<stdlib.h>
int main ()
{
	// loop variables
	int i;
	// highest power
	int h_pow,pow_r,temp;
	printf("\n\t\tNote: if any term is missing in polynomial coeffient of that term is 0 and u have to enter that 0: ");
	printf("\nEnter the heighest power of  polynomials: ");
	scanf("%d",&h_pow);
	//array for ist polynomial
	int* pol1=(int*)malloc(h_pow*sizeof(int));
	//array for 2nd polynomial
	int* pol2=(int*)malloc(h_pow*sizeof(int));
	//  pow of result plolynomial
	pow_r=h_pow;
	//array for result polynomial
	int* result=(int*)malloc(pow_r*sizeof(int));
	// coefficients of polynomial 1
	printf("\nEnter the coefficient of ist polynomial:\n ");
	for(i=0;i<=h_pow;i++)
	{
		scanf("%d",&pol1[i]);
	}
	// coeficients of polynomial 2
	printf("\nEnter the coefficient of 2nd polynomial:\n ");
	for(i=0;i<=h_pow;i++)
	{
		scanf("%d",&pol2[i]);
	}
	// adding two polynomials
	for(i=0;i<=pow_r;i++)
	{
		result[i]=pol1[i]+pol2[i];
	}
	// printing the polynomial 1
	printf("\n\t\t\tThe ist polynomial is: ");
	temp=h_pow;
	for(i=0;i<=h_pow;i++)
	{
		if(i<h_pow &&pol1[i]!=0)
		{
			printf("%dX^%d ",pol1[i],temp);
		}
		if(i==h_pow &&pol1[i]!=0)
		{
			printf("%d ",pol1[i]);
		}
		if(i<h_pow &&pol1[i]!=0)
		{
			printf("+ ");
		}
		temp--;	
	}
		// printing the polynomial 2
	printf("\n\t\t\tThe 2nd polynomial is: ");
	temp=h_pow;
	for(i=0;i<=h_pow;i++)
	{
		if(i<h_pow &&pol2[i]!=0)
		{
			printf("%dX^%d ",pol2[i],temp);
		}
		if(i==h_pow &&pol2[i]!=0)
		{
			printf("%d ",pol2[i]);
		}
		if(i<h_pow &&pol2[i]!=0)
		{
			printf("+ ");
		}
		temp--;	
	}
		// printing the result polynomial
	printf("\n\t\t\tThe result  polynomial is: ");
	temp=pow_r;
	for(i=0;i<=pow_r;i++)
	{
		if(i<pow_r &&result[i]!=0)
		{
			printf("%dX^%d ",result[i],temp);
		}
		if(i==pow_r &&result[i]!=0)
		{
			printf("%d ",result[i]);
		}
		if(i<pow_r &&result[i]!=0)
		{
			printf("+ ");
		}
		temp--;	
	}
	
	
	
	
	
}
