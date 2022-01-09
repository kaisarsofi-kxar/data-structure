/* program to
   add node at begin
   add node at last
   add node at middle
   add node at nth position
   delete node at begin
   delete node at last
   dellete node at middle
   delete node at nth position
   display values in list
   count total number of nodes*/
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
void add_at_middle(list **);
void delete_begin(list **);
void delete_last(list **);
void delete_at_middle(list **);
void delete_at_nth(list **);
void display(list *);
int count_nodes(list *);
list* create_node();
int main()
{
	list *base=0;
	int choice;
	do
	{
		printf("\nEnter 1  for add at begin: ");
		printf("\nEnter 2  for add at last");
		printf("\nEnter 3  for add at middle: ");
		printf("\nEnter 4  for add at nth position: ");
		printf("\nEnter 5  for delete at begin: ");
		printf("\nEnter 6  for delete at last: ");
		printf("\nEnter 7  for delete at middle: ");
		printf("\nEnter 8  for delete at nth: ");
		printf("\nEnter 9  for display: ");
		printf("\nEnter 10 for count nodes: ");
		printf("\nEnter 11 for exit: ");
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
					add_at_middle(&base);
					break;
				}
			case 4:
				{
					add_at_nth(&base);
					break;	
				}
			case 5:
				{
					delete_begin(&base);
					break;
				}
			case 6:
				{
					delete_last(&base);
					break;
				}
			case 7:
				{
					delete_at_middle(&base);
					break;
				}
			case 8:
				{
					delete_at_nth(&base);
					break;
				}
			case 9:
				{
					display(base);
					break;
				}
			case 10:
				{
					printf("\n\t\t\t\tTotal number of nodes are: %d",count_nodes(base));
					break;
				}
			case 11:
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
// create new node
list* create_node()
{
	list *new_node;
	new_node=(list *)malloc(sizeof(list));
	new_node->next=0;
	printf("\n\t\t\t\tEnter value in list: ");
	scanf("%d",&new_node->n);
	return new_node;
}
void add_begin(list **base )
{
	list *node,*temp;
	node =create_node();
	if(*base==0)
	{
		*base=node;
		printf("\n\t\t\t\tone list added at begin");
	}
	else
	{
		temp=*base;
		*base=node;
		node->next=temp;
		printf("\n\t\t\t\tone list added at begin");		
	}
}
void add_last(list **base)
{
	list *node,*temp;
	node =create_node();
	if(*base==0)
	{
		*base=node;
		printf("\n\t\t\t\tone list added at last");
	}
	else
	{
		temp=*base;
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		temp->next=node;
		printf("\n\t\t\t\tone list added at last");
	}
	
}
//to display values in list
void display(list *base)
{ 
	if(base == 0)
	{
		printf("\n\t\t\t\tThere is no list");
	}
	else
	{
		printf("\n\t\t\t\tValues in list are: ");
		while(base != 0)
		{
			printf("%d  ",base->n);
			base=base->next;
		}
	}
	
	
}
void delete_begin(list **base)
{
	list *temp;
	if(*base==0)
	{
		printf("\n\t\t\t\tThere is no list");
	}
	else
	{
		temp = *base;
		printf("\n\t\t\t\tThe deleted element is %d",(*base)->n);
		*base=(*base)->next;
		free(temp);
		printf("\n\t\t\t\tone list deleted at begin");
	}	
}

void delete_last(list **temp)
{
	list *temp1,*temp2;
	if(*temp == 0)
	{
		printf("\n\t\t\t\tThere is no list");
	}
	else if((*temp)->next == 0)
	{
	 	printf("\n\t\t\t\tdeleted element is %d",(*temp)->n);
		*temp=0;
		printf("\n\t\t\t\tlast list is deleted at last");	
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
int count_nodes(list *temp)
{
	int count=0;
	while(temp !=0)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
void add_at_nth(list **temp)
{
	int nodes=count_nodes(*temp),position;
	int i = 1;
	printf("\n\t\t\t\tThere are total %d node",nodes);
	printf("\n\t\t\t\tenter the position where you want to add new node: ");
	scanf("%d",&position);
	list* node =create_node();
	if(position ==1)
	{
		node->next=*temp;
		*temp=node;
		printf("\n\t\t\t\tnode added at position %d",position);
	}
	else if(position>nodes)
	{
		printf("\n\t\t\t\tYou have entered wrong position");
	}
	else
	{
		list *temp1=*temp;
		while(i<position-1)
		{
			temp1=temp1->next;
			i++;
		}
		node->next=temp1->next;
		temp1->next=node;
		printf("\n\t\t\t\tnode added at position %d",position);		
	}
}
void add_at_middle(list **temp)
{
	int nodes=count_nodes(*temp);
	int i = 1;
	list* new_node =create_node();
	if(nodes==0)
	{
		printf("\n\t\t\t\tThere are no nodes: ");
	}
	else
	{
		list *temp1=*temp;
		if (nodes%2==0) // for even nodes
		{
			while(i< (nodes/2))
			{
				temp1=temp1->next;
				i++;
			}
		}
		if(nodes%2==1)  //for odd nodes
		{
			while(i< (nodes+1)/2)
			{
				temp1=temp1->next;
				i++;
			}
		}
		new_node->next=temp1->next;
		temp1->next=new_node;
		printf("\n\t\t\t\tone node added at middle: ");
	}
}
void delete_at_middle(list **base)
{
	int nodes=count_nodes(*base);
	int i=1;
	list *temp=*base,*temp1;
	if(nodes==0)
	{
		printf("\n\t\t\t\tTher are no nodes: ");
	}
	else
	{
		if(nodes%2==0)
		{
			while(i<(nodes/2)-1)
			{
				temp=temp->next;
				i++;
			}	
		}
		if(nodes%2==1)
		{
			while(i<(nodes+1)/2-1)
			{
				temp=temp->next;
				i++;
			}
		}
		temp1=temp->next;
		printf("\n\t\t\t\telement in deleted node is: %d",temp1->n);
		temp->next=temp1->next;
		free(temp1);
		printf("\n\t\t\t\tNOde deleted at middle: ");			
	}		
}
void delete_at_nth(list **temp)
{
	int nodes=count_nodes(*temp);
	if(nodes==0)
	{
		printf("\n\t\t\t\tTher are no nodes: ");
		return;
	}
	list *temp1;
	int i=1,position;
	printf("\n\t\t\t\tThere are total %d node",nodes);
	printf("\n\t\t\t\tenter the position where you want to delete a node: ");
	scanf("%d",&position);
    if(position == 1)
	{
		temp1=*temp;
		*temp=temp1->next;
		printf("\n\t\t\t\tElement in deleted node is: %d",temp1->n);
		free(temp1);
		printf("\n\t\t\t\tnode deleted at position %d",position);
	}
	else if(position>nodes)
	{
		printf("\n\t\t\t\tYou have entered wrong position");	
	}
	else
	{
		temp1=*temp;
		while(i<position-1)
		{
			temp1=temp1->next;
			i++;
		}
		list *temp2=temp1->next;
		temp1->next=temp2->next;
		printf("\n\t\t\t\tElement in deleted node is: %d",temp2->n);
		free(temp2);
		printf("\n\t\t\t\tnode deleted at position %d",position);
		
	}
	
}

		
