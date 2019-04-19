#include<stdio.h>

int a[10],min=0,max=0,n,i;


void minmax(int i, int j)
{
	int min1,max1,mid;
	
	if(i==j)
		min = max = a[i];
		
	else if(i==j-1)
	{
		if(a[i]<a[j])
		{
			min = a[i];
			max = a[j];
		}
		else
		{
			min = a[j];
			max = a[i];
		}
	}
	
	else
	{
		mid = (i+j)/2;
		minmax(i,mid);
		
		max1 = max;
		min1 = min;
		minmax(mid+1,j);
		
		if(max < max1)
			max = max1;
		if(min > min1)
			min = min1;
	}
}

void main()
{
	printf("Enter the number of elements :");
	scanf("%d",&n);
	
	printf("Enter the elements :");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
		
	minmax(0,n-1);
	
	for(i=0; i<n; i++)
		printf("%d\t",a[i]);
	
	printf("\nMaximum is %d \n",max);
	printf("Minimum is %d \n",min);

}

		
	
