#include<stdio.h>

void main()
{
	int i,j,n,temp,a[30];
	
	printf("Enter the number of elements :");
	scanf("%d",&n);
	
	printf("Enter the elements :");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
		
	for(i=1; i<n; i++)
	{
		temp=a[i];
		j=i-1;
		
		while((temp<a[j]) && (j>=0))
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
	
	printf("Sorted list is as follows :");
	for(i=0; i<n; i++)
		printf("%d\n",a[i]);
		
}
