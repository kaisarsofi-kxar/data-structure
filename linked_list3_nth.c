#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct linkedlist{
	
	int n;
	struct linkedlist *next;
}list;
void add_begin(list **);
void add_last(list **);
void add_at_nth(list **);
void display(list *);
void delete_begin(list **);
void delete_last(list **);
//void delete_at_nth(list **);

int count=0;
int main()
{
	list *base=0;
	int choice;
	do
	{
		printf("\nEnter 1 for add at begin: ");
		printf("\nEnter 2 for add at last");
		printf("\nEnter 3 for add at nth place");
		printf("\nEnter 4 for add in the middle");
		printf("\nEnter 5 for display values in list: ");
		printf("\nEnter 6 for delete at begin: ");
		printf("\nEnter 7 for delete at last: ");
		printf("\nEnter 8 for delete at nth place: ");
		printf("\nEnter 9 for delete in middle: ");
		printf("\nEnter 0 for exit: ");
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
					display(base);
					break;
				}
			case 4:
				{
					add_at_nth(&base);
					break;
				}
			case 5:
				{
					//add_middle(&base);
					break;
				}
			case 6:
				{
					delete_begin(&base);
					break;	
				}
			case 7:
				{
					delete_last(&base);
					break;
				}
			case 8:
				{
					//delete_at_nth(&base);
					break;
				}
			case 9:
				{
					//delete_middle(&base);
					break;
				}
			case 0:
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

void add_begin(list **temp )
{
	count+=1;
	list *node,*temp1;
	node = (list *)malloc(sizeof(list));
	node->next=0;
	printf("\n\t\t\t\tEnter value in list: ");
	scanf("%d",&node->n);
	if(*temp==0)
	{
		*temp=node;
		printf("\n\t\t\t\tone list added");
	}
	else
	{
		temp1=*temp;
		*temp=node;
		node->next=temp1;
		printf("\n\t\t\t\tone list added at begin");
		
	}
}
void add_last(list **temp)
{
	count+=1;
	list *node,*temp1;
	node=(list *)malloc(sizeof(list));
	node->next=0;
	printf("\n\t\t\t\tEnter value in list: ");
	scanf("%d",&node->n);
	if(*temp==0)
	{
		*temp=node;
	}
	else
	{
		temp1=*temp;
		while(temp1->next!=0)
		{
			temp1=temp1->next;
		}
		temp1->next=node;
		printf("\n\t\t\t\tone list added at last");
	}
	
}
//to display values in list
void display(list *temp)
{ 
	if(temp == 0)
	{
		printf("\n\t\t\t\tThere is no list");
	}
	else
	{
		printf("\n\t\t\t\tValues in list are: ");
		while(temp != 0)
		{
			printf("%d  ",temp->n);
			temp=temp->next;
		}
	}
	
	
}
void delete_begin(list **temp)
{
	count-=1;
	list *temp1;
	if(*temp==0)
	{
		printf("\n\t\t\t\tThere is no list");
	}
	else
	{
		temp1 = *temp;
		printf("\n\t\t\t\tThe deleted element is %d",(*temp)->n);
		*temp=(*temp)->next;
		free(temp1);
		printf("\n\t\t\t\tone list deleted");
	}	
}

void delete_last(list **temp)
{
	count-=1;
	list *temp1,*temp2;
	if(*temp == 0)
	{
		printf("\n\t\t\t\tThere is no list");
	}
	else if((*temp)->next == 0)
	{
	 	printf("\n\t\t\t\tdeleted element is %d",(*temp)->n);
		*temp=0;
		printf("\n\t\t\t\tlast list is deleted");	
	}
	else
	{
		temp1=*temp;
		while(temp1->next!=0)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		printf("\n\t\t\t\tdeleted element is %d",temp1->n);
		temp2->next=temp1->next;
		free(temp1);
		printf("\n\t\t\t\tdeleted one list at last");
		
	}
}
void add_at_nth(list **temp)
{	int n=0,i;
	printf("\n\t\t\t\tThere are total %d lists",count);
	printf("\n\t\t\t\tEnter the place where you want to add list");
	scanf("%d",&n);
	if(n>count)
	{
		//add_last(**temp);
	}
	else
	{
		list *node,*temp1,*temp2;
		node=(list *)malloc(sizeof(list));
		node->next=0;
		printf("\n\t\t\t\tEnter value in list: ");
		scanf("%d",&node->n);
		if(*temp==0)
		{
			*temp=node;
		}
		else
		{
			temp1=*temp;
			for(i=1;i<n;i++)
			{
				if(i==n-1)
				{
					temp2=temp1;
				}
				temp1=temp1->next;
			}
			temp2->next=node;
			node->next=temp1;
			printf("\n\t\t\t\tone list added at %dth place",n);
		}
	}
}	
