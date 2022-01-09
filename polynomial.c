#include<stdio.h>
int main()
{   int i,j,k,d1=4,d2=4;
    int pol1[d1+1],pol2[d2+1];
    printf("\nEnter the coefficients of polynomial 1: \n ");
    for(i=0;i<d1+1;i++)
    {
    	scanf("%d",&pol1[i]);
	}
    printf("\nThe coefficients of polynomial 1: \n ");
    for (i=0;i<d1+1;i++)
    {
    	printf("%d ",pol1[i]);
	}
    printf("\nthe polynomial 1 is: \n");
    i=0;d1=4;
    if (i<=d1)
    { 
		while(i<=(d1+1))
    	{
			printf("%d x^%d ",pol1[i],d1);
    		printf("+");
			i++;
			d1--;
		}
	}
    while (d1>-1)//when i>d1
    {
       printf("%d x^%d ",pol1[i],d1);
       printf("+");
	   i++;
	   d1--;
    }
    printf("\nEnter the coefficients of polynomial 2:\n ");
    for(j=0;j<d2+1;j++)
    {
    	scanf("%d",&pol2[j]);	
	}
    printf("\nThe coefficients of polynomial 2: \n");
    for(j=0;j<d2+1;j++)
    {
    	printf("%d\t",pol2[j]);
	}
    printf("\nthe polynomial 2 is:\n");
    j=0;d2=4;
    if (j<=d2)
    {
		while(j<=(d2+1))
    	{
			printf("%d x^%d ",pol1[j],d2);
   			printf("+");
			j++;
			d2--;
		}
	}
	while (d2>-1)//when i>d1
    {
       	printf("%d x^%d ",pol1[j],d2);
    	printf("+");
		j++;
		d2--;

    }
    int d3;
    d1=4;
    d2=4;
    if(d1>d2)
    {
         d3=d1;
    }
    else
	{
        d3=d2;	
	}
    int pol3[d3+1];
    for (k=0;k<d3+1;k++)
    {
    	pol3[k]=pol1[k]+pol2[k];
	} 
    printf("\nThe coefficients of polynomial 3: \n");
    for(k=0;k<d3+1;k++)
    {
    	printf("%d\t",pol3[k]);
	}
    printf("\nthe polynomial 3 is:\n");
    k=0;//d=4;
    if (k<=d3)
    {
		while(k<=(d3+1))
    	{
			printf("%d x^%d ",pol3[k],d3);
    		printf("+");k++;d3--;
		}
	}
	while (d3>-1)//when i>d1
    {
       printf("%d x^%d ",pol3[k],d3);
    	printf("+");k++;d3--;
    }
}
