#include<stdio.h>

int i,j,k,dist[10][10],n;
void floyd()
{
	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void main()
{
		
	printf("Enter the number of vertices :");
	scanf("%d",&n);
	
	printf("Enter the graph\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("dist[%d][%d]: ",i,j);
			scanf("%d",&dist[i][j]);
		}
	}
	
	floyd();
	printf("The shortest distance is \n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d\t",dist[i][j]);
			
		}
		printf("\n");
	}
	
}
	
