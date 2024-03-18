#include<stdio.h>
int main()
{
	int a[100],n,c=0,i;
	printf("Enter the size of an array:\n");
	scanf("%d",&n);
	//input of an element 
	printf("Enter the elements in an array:");
	for(i=0;i<n;i++)
{
		scanf("%d",&a[i]);
			}
			// to print the negative numbers 
			for (i=0;i<n;i++)
			{
				if(a[i]<0)
				c++;
			}
			printf("the negative numbers are: %d",c);
	return 0;
}
