#include<stdio.h>
void display_array(int array[],int siz)
{
	for(int i=0;i<siz;i++)
		printf("%d ",array[i]);
} 
void merge_array(int array1[],int array2[],int array3[],int siz1,int siz2)
{
	int i;
	for(i=0;i<siz1;i++)
	{
		array3[i]=array1[i];
	}
	for(int j=0;j<siz2;j++)
	{
		array3[i]=array2[j];
		i=i+1;
	}
}
int main()
{
	int array1[10],array2[10],array3[20],i,j,temp;
	int siz1,siz2,siz3;
	printf("Enter the array1 size:");
	scanf("%d",&siz1);
	if(siz1>10)
		printf("invalid number:");
	for(i=0;i<siz1;i++)
	{
		printf("enter the array1 elements:");
		scanf("%d",&array1[i]);
	}
	printf("Array elements are: ");
	display_array(array1,siz1);
	printf("\n");
	for(i=0;i<siz1;i++)
	{ 
		for(j=i+1;j<siz1;j++)
		{
			if(array1[i]>array1[j])
			{ 
				temp=array1[i];
				array1[i]=array1[j];
				array1[j]=temp;
			}
		}
	}
	printf("Sorted array elements are:");
	display_array(array1,siz1);
	printf("\n");
	printf("Enter the array2 size:");
	scanf("%d",&siz2);
	if(siz2>10)
		printf("Invalid number");
	for(j=0;j<siz1;j++)
	{
		printf("enter the array2 elements:");
		scanf("%d",&array2[j]);
	}
	printf("Array elements are: ");
	display_array(array2,siz2);
	printf("\n");
	for(i=0;i<siz2;i++)
	{
		for(j=i+1;j<siz2;j++)	
		{
			if(array2[i]>array2[j])
			{
				temp=array2[i];
				array2[i]=array2[j];
				array2[j]=temp;
			}
		}
	}
	printf("Sorted array elements are:");
	display_array(array2,siz2);
	printf("\n");
	printf("merged array elements are:");
	merge_array(array1,array2,array3,siz1,siz2);
	display_array(array3,siz1+siz2);
	siz3=siz1+siz2;
	for(i=0;i<siz3;i++)
	{
		for(j=i+1;j<siz3;j++)	
		{
			if(array3[i]>array3[j])
			{
				temp=array3[i];
				array3[i]=array3[j];
				array3[j]=temp;
			}
		}
	}
	printf("\n");
	printf("sorted array elements are:");
	merge_array(array1,array2,array3,siz1,siz2);
	display_array(array3,siz3);
	printf("\n");
	return(0);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
