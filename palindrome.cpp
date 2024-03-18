#include<stdio.h>
int main()
{
	int a,n,temp,sum=0;
	printf("Enter the value:");
	scanf("%d",&n);
temp=n;
while(n>0)
{
	a=n%10;
	sum=sum*10+a;
	n=n/10;
}
	if(sum==temp)
	{
		printf("Palindrome");
	}
	else{
		printf("Not a palindrome");
	}
	return 0;
}
