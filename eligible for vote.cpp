#include<stdio.h>
int main()
{
	int a;
	printf("Enter the number:");
	scanf("%d",&a);
	if(a>=18)
	{
		printf("Eligible for vote");
	}
		else if (a<18){
			printf("Not eligible");
			printf(" \n The remainding age for votings is %d",18-a);
		}
		return 0;
	}
	
