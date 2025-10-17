#include<stdio.h>
#define max_size 10
int queue[max_size],front=-1,rear=-1;
void enqueue(int item)
{
	if(rear>=max_size-1)
	{
		printf("Queue is full\n");
	}
	if(front == -1)
		front=0;
		printf("Enter the element to insert:");
		scanf("%d",&item);
		rear=rear+1;
		queue[rear]=item;
}
void dequeue()
{
	if(front==1)
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("Deleted element is %d \n",queue[front]);
		front=front+1;
	}
	if(front>rear)
		front=rear=-1;
}	
void display()
{
	for(int i;=front;i<=rear;i++)
		printf("%d ",queue[i]);	
	printf("\n");
}
int main()
{
	int n,item;
	do
	{
		printf("\n1.insert \n2.delete \n3.Display \n4.Exit \n Enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:enqueue(item);
				break;
			case 2:dequeue();
				break;
			case 3:printf("queue elements are:\n")
				display();
				break;
			default:printf(" If Your choice Invalid ");
				break;
		}
	}while(choice!=4);
return(0);
}
