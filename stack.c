#include<stdio.h>
#define max_size 10
int s[max_size],top=-1;
void push(int item)
{
	if(top>=max_size-1)
		printf("Stack is full");
	else
	{
		printf("Enter the element to push:");
		scanf("%d",&item);
		top=top+1;
	}	s[top]=item;
}
void pop()
{
	if(top== -1)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("Pop element is %d \n",s[top]);
		top=top-1;
	}
}	
void display()
{
	int i;
	for(i=top;i>-1;i--)
		printf("%d \n",s[i]);	
}
int main()
{
	int choice,item;
	do
	{
		printf("\n1.push \n2.pop \n3.Display \n4.Exit \n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push(item);
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			default:printf("Your choice is Invalid ");
				break;
		}
	}while(choice!=4);
return(0);
}
