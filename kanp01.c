#include<stdio.h>


int max(int x,int y)
{
	return (x>y) ? x : y;
}

int knapsack(int capacity,int weight[],int val[],int n)
{
	int i,j;
	int k[n+1][capacity+1];
	
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=capacity; j++)
		{
			if(i==0 || j==0)
				k[i][j]=0;
				
			else if(weight[i-1] <= j)
				k[i][j] = max(val[i-1] + k[i-1][j-weight[i-1]], k[i-1][j]);
				
			else
				k[i][j] = k[i-1][j];
		}
	}
	return k[n][capacity];
}


void main()
{
	int i,n,val[20],weight[20],capacity;
	
	printf("Enter the number of items :");
	scanf("%d",&n);
	
	printf("Enter the weight and value of knapsack :\n");
	for(i=0; i<n; i++)
		scanf("%d%d",&weight[i],&val[i]);

	printf("Enter the capacity of knapsack :");
	scanf("%d",&capacity);
	
	printf("%d", knapsack(capacity, weight, val, n));	
	
}
			
