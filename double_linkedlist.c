/* double linked list    1 add node at begin 2 add node at last 3 add node at middle 4 add node at nth 5 delete begin 6 delete last 7 delete middle 8 delete nth
   10 display elements 11 display max element 12count nodes */
#include<stdio.h>
#include<stdlib.h>
typedef struct doubleLinkedList 
{
	struct doubleLinkedList *prev;
	int n;
	struct doubleLinkedList *next;
}list;
void add_begin (list **);
void add_last(list **);
void add_middle(list **);
void add_at_nth_position(list **);
void delete_begin(list **);
void delete_last(list **);
void delete_at_middle(list **);
void delete_at_nth_position(list **);
void display(list *);
void display_max(list *);
int count_nodes(list *);
list *create_node();
int main()
{
	list *base=0;
	int choice,node_count;
	do 
	{
		printf("\nEnter 1  for add at begin: ");
		printf("\nEnter 2  for add at last");
		printf("\nEnter 3  for add at middle: ");
		printf("\nEnter 4  for add at nth position: ");
		printf("\nEnter 5  for delete at begin: ");
		printf("\nEnter 6  for delete at last: ");
		printf("\nEnter 7  for delete at middle: ");
		printf("\nEnter 8  for delete at nth position: ");
		printf("\nEnter 9  for display elements: ");
		printf("\nEnter 10 for display max element: ");
		printf("\nEnter 11 for count number of nodes: ");
		printf("\nEnter 12 for exit: ");
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
					add_middle(&base);
					break;
				}
			case 4:
				{
					add_at_nth_position(&base);
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
					delete_at_nth_position(&base);
					break;
				}
			case 9:
				{
					display(base);
					break;
				}
			case 10:
				{
					display_max(base);
					break;
				}
			case 11:
				{
					node_count=count_nodes(base);
				    printf("\n\t\t\t\tNumber of nodes are: %d",node_count);
					break;
				}
		 	case 12:
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
list* create_node()
{
   list* new_node=(list *)malloc(sizeof(list));
		new_node->prev=0;
		new_node->next=0;
		printf("\n\t\t\t\tEnter the element in node: ");
		scanf("%d",&new_node->n);
		return new_node;
}
void add_begin(list **temp)
{
	list *node,*temp1;
	
	node = create_node();
	if(*temp == 0)
	{
		*temp=node;
	}
	else
	{
		temp1=*temp;
		node->next = temp1;
		temp1->prev=node;
		*temp=node;
	}
	printf("\n\t\t\t\tnode is created at begin");
}
void add_last(list **temp)
{
	list *node,*temp1,*temp2;
	node = create_node();
	if(*temp == 0)
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
		temp2=temp1;
		temp1->next=node;
		node->prev=temp2;
	}
	printf("\n\t\t\t\tnode is created at last");
}
void display(list *temp)
{
	printf("\n\t\t\t\telements in list are: ");
	while(temp != 0 )
	{
		printf("%d  ",temp->n);
		temp=temp->next;
	}
}
void display_max(list *temp)
{
	int max=temp->n;
	while (temp !=0)
	{
		if(max<temp->n)
		{
			max=temp->n;
		}
		temp=temp->next;
	}
	printf("\n\t\t\t\tMaximum value in the list is: %d",max);
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
void add_middle(list **temp)
{
	int nodes=count_nodes(*temp);
	int i=1;
	list *new_node,*temp1,*temp2;
	if(nodes==0)
	{
		printf("\n\t\t\t\tThere is no node present: ");
	}
	else 
	{
		new_node=create_node();
		temp1=*temp;
		if(nodes%2 == 0)
		{
			while ( i < (nodes/2) ) // for even nodes
			{
				temp1=temp1->next;
				i++;
			}
		}
		if(nodes%2==1)  //for odd nodes
		{
			while( i <((nodes+1)/2))
			{
				temp1=temp1->next;
				i++;
			}
		}
		temp2=temp1->next;
		temp1->next=new_node;
		new_node->prev=temp1;
		new_node->next=temp2;
		printf("\n\t\t\t\tnode is created at middle");			
	}	
}
void add_at_nth_position(list **temp)
{
	int nodes = count_nodes(*temp);
	int position,i=1;
	list *new_node,*temp1,*temp2;
	printf("\n\t\t\t\tThere are total %d nodes:",nodes);
	printf("\n\t\t\t\tEnter the position where you want to insert a new node: ");
	scanf("%d",&position);
	if(nodes==0 && position ==1)
	{
		*temp=create_node();
		
	}
   	else if( nodes>0 &&position == 1)
	{
		new_node=create_node();
		temp1=*temp;
		*temp=new_node;
		new_node->next=temp1;
		temp1->prev=new_node;	
	}
    else if (position >nodes)
	{
		printf("\n\t\t\t\tYou have enter wrong position");
	}
	else
	{
		new_node=create_node();
		temp1=*temp;
		while (i <position-1)
		{
			temp1=temp1->next;
			i++;
		}
		temp2=temp1->next;
		temp1->next=new_node;
		new_node->prev=temp1;
		new_node->next=temp2;		
	}
	printf("\n\t\t\t\tnode is created at position %d",position);
}
void delete_begin(list **temp)
{
	int nodes = count_nodes(*temp);
	if(nodes == 0)
	{
		printf("\n\t\t\t\tThere is no node present");
		return;
	}
	list *temp1;
	temp1=*temp;
	*temp =(*temp)->next;
	(*temp)->prev = temp1->prev;
	printf("\n\t\t\t\telement in deleted node is %d",temp1->n);
	free(temp1);
	printf("\n\t\t\t\tnode is deleted at begin");
	
}
void delete_last(list **temp)
{
	int nodes = count_nodes(*temp);
	if(nodes == 0)
	{
		printf("\n\t\t\t\tThere is no node present");
		return;
	}
	list *temp1,*temp2;
	temp1=*temp;
	while(temp1->next != 0)
	{
		temp1=temp1->next;
	}
	temp2=temp1->prev;
	printf("\n\t\t\t\telement in deleted node is %d",temp1->n);
	temp2->next=temp1->next;
	free(temp1);
	printf("\n\t\t\t\tnode is deleted at last");	
}
void delete_at_middle(list **temp)
{
	int nodes = count_nodes(*temp);
	list *temp1,*temp2,*temp3;
	int i=1;
	temp1=*temp;
	if (nodes==0)
	{
		printf("\n\t\t\t\tThere is no node");	
	}
	else 
	{
		if(nodes%2==0)
		{
			while( i< (nodes/2))
			{
				temp1=temp1->next;
				i++;
			}
		}
		if(nodes%2 ==1)
		{
			while (i< ((nodes+1)/2))
			{
				temp1=temp1->next;
				i++;
			}
		}
		temp2=temp1->next;
		temp3=temp1->prev;
		printf("\n\t\t\t\telement in deleted node is %d",temp1->n);
		free(temp1);
		printf("\n\t\t\t\tNode deleted at middle");
		temp3->next=temp2;
		temp2->prev=temp3;	
	}		
}
void delete_at_nth_position(list **temp)
{
	int nodes = count_nodes(*temp);
	if(nodes == 0)
	{
		printf("\n\t\t\t\tThere is no node present");
		return;
	}
	int position,i=1;
	list *temp1,*temp2,*temp3;
	printf("\n\t\t\t\tThere are total %d nodes:",nodes);
	printf("\n\t\t\t\tEnter the position where you want to delete a node: ");
	scanf("%d",&position);
	if (position ==1)
	{
		temp1=*temp;
		printf("\n\t\t\t\telement in deleted node is %d",temp1->n);
	   	*temp=(*temp)->next;
	   	(*temp)->prev=temp1->prev;
		free(temp1);
		printf("\n\t\t\t\tNode deleted at position %d",position);
	}
	else if (position >nodes)
	{
		printf("\n\t\t\t\tYou have enter wrong position");
	}
	else
	{
		temp1=*temp;
		while (i<position)
		{
			temp1=temp1->next;
			i++;
		}
		temp2=temp1->next;
		temp3=temp1->prev;
		printf("\n\t\t\t\telement in deleted node is %d",temp1->n);
		free(temp1);
		printf("\n\t\t\t\tNode deleted at position %d",position);
		temp3->next=temp2;
		temp2->prev=temp3;	
	}
}
