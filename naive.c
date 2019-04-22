#include  <stdio.h>
#include  <string.h>

void naive(char  T[] , char  P[]);

int main()
{
  char  T[100] , P[100];

  printf("Enter the Text string: ");
  gets(T);

  printf("Enter the Pattern string: ");
  gets(P);

  naive(T,P);
}

void naive(char  T[] , char  P[])
{
    int  i , j , n , m , count = 0 ;

    n=strlen(T);
    m=strlen(P);

    for(i=0 ; i<=n-m ; i++)
    {
		for(j=0 ; j<m ; j++)
		if(T[i+j]!=P[j])    
		break;

		if(j==m)
		{
			printf("Pattern string found at position %d \n",i);  
			count++;
		}
	}
	
	if(count==0)
	printf("Pattern string never found in text string \n");  
}
