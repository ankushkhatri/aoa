#include<stdio.h>
#include<math.h>

int board[20],count;


int place(int row, int column)
{
	int i;
	for(i=1; i<=row-1; i++)
	{
		if(board[i] == column)  
			return 0;
		else if(abs(board[i]-column)==abs(i-row))
			return 0;
	}
	return 1;
}


void print(int n)
{
	int i,j;
	printf("Solution = %d\n",count);
	count=count+1;
	
	for(i=1; i<=n; i++)
		printf("\t%d",i);
		
	for(i=1; i<=n; i++)
	{
		printf("\n%d",i);
		for(j=1; j<=n; j++)
		{
			if(board[i] == j)
				printf("\tQ");
			else
				printf("\t-");
		}
	}
	printf("\n");
}

void queen(int row, int n)
{
	int column;
	for(column=1; column<=n; column++)
	{
		if (place(row,column))
		{
			board[row]=column;
			if(row == n)
				print(n);
			else
				queen(row+1, n);
		}
	}
}


void main()
{
	int n;
	void queen(int row, int n);
	
	printf("Enter the number of Queeens :");
	scanf("%d",&n);
	queen(1,n);
	
}

