#include<stdio.h>
int arr[5]={1,2,3,4,5},top=-1;
void delete()
{
	int i,temp;
	for(i=0;i<5;i++)
	{
		temp=arr[i];
		arr[i]=arr[i+1]	;
		top++;
	}
	for(i=0;i<top;i++)
	{
		printf("%d",arr[i]);
	}
}
int main()
{
	delete();
}
