#include<stdio.h>
void push();
int pop();
int stack[5];
int top=0,ele,flag=0;
int main()
{
	int element,choice;
	do
	{
		
		printf("\nEnter 1 to push element: ");
		printf("\nEnter 2 to POP element: ");
		printf("\nEnter 3 to EXIT: ");
		scanf("%d",&choice);
		if(choice==1)
		{
			push();
			flag=0;
		}
		
		if(choice==2)
		{
			element=pop();
			if(flag==0)
			printf("\n\t\t\t\tDeleted element is: %d",element);
			
				
		}
		if(choice==3)
		{
			break;
		}
		
	}while(1);
}
void push()
{
	if(top==5)
	{
		printf("\n\t\t\t\tStack is full: %d",top);
	}
	else
	{
		printf("\n\t\t\t\tEnter element in stack:");
		scanf("%d",&ele);
		stack[top]=ele;
		top++;
	}	
}

int pop()
{
	if(top==0)
	{
		printf("\n\t\t\t\tStack is empty:");
		flag=1;
	}
	else
	{
		top--;
		return stack[top];
	}
}
