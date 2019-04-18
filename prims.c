#include<stdio.h>
#include<stdlib.h>


int getMin(int MST[], int key[], int V)
{
	int min = INT_MAX,minIndex;
	for(int i=0; i<V; i++)
	{
		if(MST[i] == -1 && key[i] < min)
		{
			min = key[i];
			minIndex = i;
		}
	}
	return minIndex;
}



int prim(int G[][10], int V, int E, int src)
{
	int parent[10],key[10],MST[10],cost=0,start;
	
	for(int i=0; i<V; i++)
	{
		MST[i] = -1;
		key[i]=INT_MAX;
	}
	key[src] = 0;
	parent[src] = -1;
	
	for(int count=0; count<V-1; count++)
	{
		start = getMin(MST, key, V);
		MST[start]= 1;
		
		for(int end=0; end<V; end++)
		{
			if( G[start][end] != 0 && MST[end] == -1 && G[start][end] < key[end] )
			{
				key[end] = G[start][end];
				cost = cost + key[end];
				parent[end] = start;
			}
		}
	}
	primMST(parent, V, G);
	return cost;
}

void primMST(int parent[], int V, int G[][10])
{
	printf("Edge \tWeight\n");
	for(int i=0; i<V; i++)
	{
		if(parent[i] == -1)
			continue;
			
		printf("%d - %d \t%d\n",parent[i],i,G[i][parent[i]]);
	}
}



void main()
{
	int V,G[10][10],i,j,E;
	int start,end,weight,src;
	
	printf("Enter the no of vertices and edges :");
	scanf("%d%d",&V,&E);
	
	for(i=0; i<V; i++)
		for(j=0; j<V; j++)
			G[i][j] = 0;
			
	for(i=0; i<E; i++)
	{
		printf("Enter the starting vertex and end vertex and weight of the edge :");
		scanf("%d%d%d",&start,&end,&weight);
		G[start][end] = weight;
		G[end][start] = weight;
	}
	
	printf("Enter the source vertex :");
	scanf("%d",&src);
	int cost = prim(G, V, E, src);
	printf("cost = %d\n",cost);	
}

