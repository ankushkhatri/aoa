#include<stdio.h>
#include<string.h>
int i,j,m,n,c[100][100],b[100][100];
char x[100],y[100];

void print_lcs(int i, int j)
{
	if(i==0 || j==0)
		return;
		
	if(b[i][j] == 1)
	{
		print_lcs(i-1, j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j] == 0)
	{
		print_lcs(i-1, j);
	}
	else
	{
		print_lcs(i, j-1);
	}
}


void lcs()
{
	m=strlen(x);
	n=strlen(y);
	
	for(i=0; i<=m; i++)
		c[i][0] = 0;
	for(j=0; j<=n; j++)
		c[0][i] = 0;
			
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1;
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 0;
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = -1;
			}
		}
	}
}

void main()
{
	
	printf("Enter the first string :");
	gets(x);
	printf("Enter the second string :");
	gets(y);
	printf("LCS :\n");
	lcs();
	print_lcs(m,n);

}
