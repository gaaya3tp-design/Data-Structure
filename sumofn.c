#include<stdio.h>
int main()
{
	int array[50];
	int i,n,sum=0;
	printf("Enter the Numbers:");
	scanf("%d",&n);
	if(n>50||n<1)
	{
		printf("invalid number of elements");
	}
	printf("Enter %d no:",n);	
	for(i=0;i<n;i++)
	{ 
		scanf("%d",&array[i]);
		sum=sum+array[i];
	}
	printf("sum of the %d numbers is:%d",n,sum);
	return(0);
}
