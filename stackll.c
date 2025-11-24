#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int count=0;
struct stack
{
	int data;
	struct stack *link;
};
struct stack *TOP = NULL;
void push(int item)
{
	struct stack *newnode;
	newnode=(struct stack *)malloc(sizeof(struct stack));
	newnode->data=item;
	newnode->link=NULL;
	if (TOP == NULL)
	{
		TOP = newnode;
		printf("%d pushed successfully\n",item);
	}
	else
	{
		if (count < MAX_SIZE)
		{
			newnode->link = TOP;
			TOP = newnode;
			count = count + 1;
			printf("%d pushed successfully\n",item);
		}
		else
			printf("STACK IS FULL\n");
	}
}
void pop()
{
	struct stack *ptr;
	if(TOP == NULL)
	{
		printf("Empty STACK. Deletion not possible");
	}
	else
	{
		ptr = TOP;
		TOP = TOP -> link;
		printf("Deleted element is %d\n",ptr->data);
		free(ptr);
	}
}
void display()
{	
	struct stack *ptr;
	ptr=TOP;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}
int main()
{
	int choice, item;
	do
	{
		printf("\n=== STACK MENU ===\n | 1. Push | 2. Pop | 3. Display | 4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) 
		{
			case 1: printf("Enter element to push: ");
				scanf("%d", &item);
				push(item);
				break;
			case 2: pop();
		        	break;
			case 3: printf("STACK elements are:");
				display();
		        	break;
			case 4: printf("Exiting...\n");
		        	break;
			default: printf("Invalid choice! Please try again.\n");
		}
	}while( choice !=4 );
    	return 0;
}
