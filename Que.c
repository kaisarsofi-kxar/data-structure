#include<stdio.h>
#include<conio.h>
void add();
int delete();
int que[5];
int f=-1,r=-1;
int main()
{
	int choice,ele;
	do
	{
		printf("\n\t\t\t\t\tEnter 1  for add: ");
		printf("\n\t\t\t\t\tEnter 2  for delete: ");
		printf("\n\t\t\t\t\tEnter 3  for exit: ");
		scanf("%d",&choice);
		if (choice==1)
		{
			add();
		}
		if(choice==2)
		{
			delete();		
		}
		if(choice==3)
		{
			break;
		}
		
	}while(1);
	
	}
	void add()
	{
		int ele;
		if((r==4&&f==-1) || (r==f&&f!=-1))
		{
			printf("\nQue is full");
		}
		else
		{
			printf("\nEnter element in que: ");
			scanf("%d",&ele);
			if(r==4&&f!=-1)
			r=-1;
			r++;
			que[r]=ele;
		}

	}
		int delete()
	{
		if(f==r||r==-1&&r==-1)
		{
			printf("\nQue is empty");
			f=-1;r=-1;
		}
		else
		{
			f++;
			printf("\nthe element in que is: %d",que[f]);
		}
	}

