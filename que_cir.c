#include<stdio.h>
#include<conio.h>
void add(int);
void delete();
int que[5],f=-1,r=-1,flag=0,top=0;
int main()
{
	int choice,ele,output;
	do
	{
		printf("\nEnter 1 to add number: ");
		printf("\nEnter 2 to delete number: ");
		printf("\nEnter 3 to exit: ");
		scanf("%d",&choice);
		
		if(choice==1) //for adding an element
		{
			if(r!=4)
			{
				printf("\n\t\t\t\t\tEnter the number: ");
				scanf("%d",&ele);
				add(ele);
			}
			else if(r==4)
			{
				printf("\n\t\t\t\tQue is full");
			}
		}
		
		if(choice==2) //for deleteing an element
		{
			delete();
		}
		
		if (choice==3)
		{
			break;
		}
		
 	}while(1);
}

void add(int a)
{
	top++;
	r++;
	que[r]=a;
}

void delete()
{
	if(f==r||top<=0)
	{
		printf("\n\t\t\t\tQue is empty");
		r=-1;
	}
	else
	{
		top--;
		f++;
		printf("\n\t\t\t\tDeleted element is: %d",que[f]);
	}
}
