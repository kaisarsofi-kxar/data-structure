#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct linkedlist{
	
	int n;
	struct linkedlist *next;
}list;
void add(list **);
void display(list *);
void delete(list **);
int main()
{
	list *base=0;
	int choice;
	do
	{
		printf("\nEnter 1  for add: ");
		printf("\nEnter 2  for display: ");
		printf("\nEnter 3  for delete: ");
		printf("\nEnter 4  for exit: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					add(&base);
					break;
				}
			case 2:
				{
					display(base);
					break;
				}
			case 3:
				{
					delete(&base);
					break;	
				}
			case 4:
				{
					
					exit(0);
				}
			default:
				{
					printf("\n\t\t\t\tEntered wrong choice");
				}
		}
	}while(1);
}

void add(list **p )
{
	list *temp,*temp1;
	temp = (list *)malloc(sizeof(list));
	temp->next=0;
	printf("\n\t\t\t\tEnter value in list: ");
	scanf("%d",&temp->n);
	if(*p==0)
	{
		*p=temp;
		
	}
	else
	{
		temp1=*p;
		while(temp1->next != 0)
		{
			temp1=temp1->next;
		}
		
	temp1->next=temp;
	}
}
//to display values in list
void display(list *temp)
{ 
	printf("\n\t\t\t\tValues in list are: ");
	while(temp != 0)
	{
		printf("%d  ",temp->n);
		temp=temp->next;
	}
}
void delete(list **pt)
{
	list *temp,*temp1;
	if(*pt==0)
	{
		printf("\n\t\t\t\tList is empty");
	}
	if((*pt)->next==0)
	{
		temp=*pt;
		*pt=0;
		printf("\n\t\t\t\tfirst list is deleted");
		free(temp);                                           
		
	}
	else
	{
		temp1 = *pt;
		while(temp1->next != 0)
		{
			temp=temp1;
			temp1=temp1->next;
		}
		temp->next=temp1->next;
		free(temp1);
		printf("\n\t\t\t\tone list deleted");
	}
	
}
