#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *header = NULL;
 
void insertAtFront(int item)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
	
	if(header == NULL)
	{
		header = newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;
	}
}

void insertAtEnd(int item)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
	
	if(header == NULL)
	{
		header = newnode;
	}
	else
	{
		struct node *ptr;
		ptr=header;
		while(ptr->link != NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=newnode;
	}
}

void insertAtAny(int key,int item)
{
	struct node *ptr, *ptr1;
	ptr = header;
	while(ptr!=NULL && ptr->data != key)
	{
		ptr1=ptr;
		ptr=ptr->link;
	}
	if(ptr == NULL)
	{
		printf("key Not found,Insertion not possible");
	}
	else
	{
		struct node *newnode;
	        newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = item;
		newnode->link = ptr;
		ptr1->link = newnode;
		printf("inserted %d after %d successfully\n",item ,key);                                                                     
	}
		
}

void deleteAtFirst()
{
	struct node *ptr;
	if(header == NULL)
	{
		printf("Empty List.Deletion not possible");
	}
	else
	{
		ptr = header;
		header = header->link;
		free(ptr);
	}
}

void deleteAtEnd()
{
	struct node *ptr, *ptr1;
	ptr = header;
	if(header == NULL)
	{
		printf("Empty List.Deletion not possible");
	}
	else
	{
		while(ptr->link != NULL)
		{
			ptr1 = ptr;
			ptr = ptr->link;
		}
		printf("Deleted element is: %d\n",ptr->data);
		ptr1->link = NULL;
		free(ptr);
	}
}
 
void deleteAtAny(int key)
{
	struct node *ptr,*ptr1;
	ptr=header;
	ptr1 = NULL;
	while(ptr!=NULL && ptr->data != key)
	{
	
		ptr1 = ptr;
		ptr = ptr->link;
	}
	if(ptr == NULL)
	{
		printf("key is not found,Deletion not possible");
	}
	else
	{
		printf("Deleted element is: %d \n", ptr->data);
		if(ptr1 != NULL)
			ptr1->link=ptr->link;
		else
			header = ptr->link;
		free(ptr);
	}
}
void searchElement(int key)
{
    struct node *ptr;
    ptr = header;
    int position = 1;
 

    if (header == NULL)
    {
        printf("List is empty. Search not possible.\n");
        return;
    }

    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        ptr = ptr->link;
        position++;
    }

        printf("Element %d not found in the list.\n", key);
}
 	
void traversaList()
{
	struct node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}

int main()
{
	insertAtFront(10);
	insertAtFront(20);
	insertAtFront(30);
	insertAtFront(40);
	printf("list after insertAtFront : \n");
	traversaList();
	
	printf("list after insertAtEnd : \n");
	insertAtEnd(50);
	traversaList();
	
	printf("list after insertAtAny : \n");
	insertAtAny(20,35);
	traversaList();
	
	deleteAtFirst();
	printf("The list after deleteAtFirst:\n");
	traversaList();
	
	printf("The list after deleteAtEnd:\n");
	deleteAtEnd();
	traversaList();
	
	deleteAtAny(20);
	printf("The list after deleteAtAny:\n");
	traversaList();
	
	printf("\nSearcing the list:\n");
	searchElement(10);
	searchElement(88);
	
	return(0);
}
