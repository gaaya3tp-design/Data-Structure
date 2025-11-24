#include<stdio.h>
int main()
{
	int i,n,sum,avg;
	printf("Enter the number:");
	scanf("%d",&n);
	do
	{
		sum=sum+i;
		i++;
	}while(i<=n);
	avg=sum/n;
	printf("average of fisrt  n number is %d",avg);
return(0);
}
			
			
