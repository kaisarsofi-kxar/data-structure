#include<stdio.h>
#include<stdlib.h>
typedef struct circularLinkedList
{
	int n;
	struct circularLinkedList *next;
}list;
void add(list **);
void display(list *);
int main()
{
	list *base =0;
	int choice;
	do 
	{
		printf("\nEnter 1 for add at begin: ");
		printf("\nEnter 2 for display: ");
		printf("\nEnter 3 for exit: ");
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
					exit(0);
				}
			default:
				{
					printf("\nyou have entered wrong choice");
				}
			
		}
}while(1);
}
void add(list **temp)
{
	list *node,*temp1;
	node = (list *)malloc(sizeof(list));
	node->next=0;
	printf("\n\t\t\t\tEnter value in list: ");
	scanf("%d",&node->n);
	if(*temp==0)
	{
		*temp=node;
		temp1=node;
		node->next=node;
		printf("\n\t\t\t\tone list added");
	}
	else
	{
		temp1->next=node;
		node->next=*temp;
		temp1=node;	
	}
}
void display(list *temp)
{
	list *temp1=temp;
	
		printf("\n\t\t\t\tvalues in list are: ");
		while(temp1->next!=temp)
		{
			printf("%d  ",temp1->n);
			temp1=temp1->next;
		}
		printf("%d",temp1->n);
	
}
