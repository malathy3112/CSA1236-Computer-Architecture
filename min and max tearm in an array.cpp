#include<stdio.h>
int main() {
	int a[1000],i,n,min,max;
	printf("enter the size of an array :");
	scanf("%d",&n);
	printf("Enter the elements in an array:");
	for(i=0; i<n; i++) {
		scanf("%d",a[i]);
	}
	min=max=a[0];
	for(i=0; i<n; i++) {

		if(min>a[i])
			min=a[i];
		if(max<a[i])
			max=a[i];
	}
	printf("max value =%d",max);
	printf("Min value =%d",min);
	return 0;
}
