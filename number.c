#include<stdio.h>
int main()
{
	int i=0,sum=0;
	while(i<10)
		{
		i+=1;
		sum=i+sum;
		}
	printf("Sum of the numbers is %d",sum);
return(0);
}
