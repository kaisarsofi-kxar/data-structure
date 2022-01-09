#include<stdio.h>
#include<stdlib.h>
typedef struct circularLinkedList
{
	int n;
	struct circularLinkedList *next;
}list;
void add_begin(list **);
void add_last(list **);
void add_nth(list **);
void display(list *);
int count_nodes(list *);
int main()
{
	list *base =0;
	int choice;
	do 
	{
		printf("\nEnter 1 for add at begin: ");
		printf("\nEnter 2 for add at last: ");
		printf("\nEnter 3 for add at nth place: ");
		printf("\nEnter 4 for display values in list: ");
		printf("\nEnter 5 for exit: ");
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
					add_last(&base);
					break;
				}
			case 3:
				{
					printf("\n\t\t\t\tTotal number of nodes are: %d",count_nodes(base));
					break;
				}
			case 4:
				{
					display(base);
					break;
				}
			case 5:
				{
					exit(0);
				}
			
		}
	}while(1);
}
void add_begin(list **base )
{
    list * node;
	node = (list *)malloc(sizeof(list));
	node->next=0;
	printf("\n\t\t\t\tEnter value in list: ");
	scanf("%d",&node->n);
	if(*base==0)
	{
	
		*base=node;
		node->next=node;
		printf("\n\t\t\t\tone list added");
	}
	else
	{ list * trav= *base;list * temp =*base;;
	 *base =node;
	 node->next =trav;
	 trav=trav->next;
	 while (trav->next!=temp)
	 {
	 	trav=trav->next;
	 	
	 }
      trav->next = *base;
	}
}
void add_last(list **temp)
{
	list *node,*temp1;
	node = (list *)malloc(sizeof(list));
	node->next=0;
	printf("\n\t\t\t\tEnter value in list: ");
	scanf("%d",&node->n);
	if(*temp==0)
	{
		*temp= node;
		node->next=node;
		printf("\n\t\t\t\tone list added");
	}
	else
	{
		temp1=*temp;
		while(temp1->next !=(*temp))
		{
			temp1=temp1->next;
		}
		temp1->next=node;
		node->next=*temp;
	}
}

void display (list *temp)
{

	if(temp==0)
	{
		printf("\n\t\t\t\tthere is no node: ");
	}
	else
	{
	    list *temp1=temp;
		printf("\n\t\t\t\tValues in list are: ");
		while(temp1->next != temp)
		{
			printf("%d  ",temp1->n);
			temp1 = temp1->next;
		}
		printf("%d",temp1->n);
	}
}
int count_nodes(list *base)
{
	int count=0;

	if(base ==0)
	{
		return count;
	}
	else
	{
		list *temp=base;
		while(temp->next !=base)
		{
			count++;
			temp=temp->next;
		}
		count++;
		return count;	
	}

}
