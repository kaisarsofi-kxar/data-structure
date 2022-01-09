#include<stdio.h>
#include<stdlib.h>
typedef struct circularDoubleLinkedList 
{
	struct circularDoubleLinkedList *prev;
	int n;
	struct circularDoubleLinkedList *next;
}list;
void add_begin(list **);
void display(list *);
int main()
{
	list *base=0;
	int choice;
	do
	{
		printf("\nEnter 1 for add: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					add_begin(&base);
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
		}
	}while(1);
}
void add_begin(list **temp)
{
	list *node,*temp1,*first_node;
	node=(list*)malloc(sizeof(list));
	node->next=0;
	node->prev=0;
	printf("\n\t\t\t\tEnter the element in node: ");
	scanf("%d",&node->n);
	if((*temp) == 0)
	{
		first_node=node;
		node->next=node;
		node->prev =node;
		*temp=node;
	}
	else
	{ 
	    first_node->next=node;
	   	node->next=*temp;
	   	node->prev=first_node;
	   	(*temp)->prev=node;  	
	   	*temp=node;
    }
}
void display(list *temp)
{
	list *temp1=temp;
	printf("\nabc %d  %d %d",temp1,temp->next,temp->prev);
	do
	{
		printf("\nElement is %d",temp->n);
		temp=temp->next;
		printf("\nabc %d  %d %d %d",temp1,temp,temp->next,temp->prev);
		
	}while(temp->next == temp);
	
	
	
	
}
