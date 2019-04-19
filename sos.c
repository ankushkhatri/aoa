#include<stdio.h>

int x[10]={0},m,w[10],n,solutions,r=0,i;


void display(int x[], int k)
{
	printf("\n Solutions \n");
	for(i=0; i<=k; i++)
		printf("%d",x[i]);
	
	if(k<n)
	{
		for(i=k+1; i<n; i++)
			printf("0");
	}
	printf("\n");
	
}


void sos(int s, int r, int k)    //s=>total sum, r=>remaining
{
	x[k]=1;
	
	if(s+w[k] == m)
		display(x,k);
	else if(s + w[k] + w[k+1] <= m)
		sos(s+w[k], r-w[k], k+1);
	
	if((s+r-w[k] >= m) && (s+w[k+1] <= m))
	{
		x[k] = 0;
		sos(s, r-w[k], k+1);
	}
}

void main()
{
	printf("Enter the total sum :");
	scanf("%d",&m);
	printf("Enter the no of elements :");
	scanf("%d",&n);
	printf("Enter the elements :");
	for(i=0; i<n; i++)
	{
		scanf("%d",&w[i]);
		r+=w[i];
	}
	sos(0, r, 0);
	
}

	
