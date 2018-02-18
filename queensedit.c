#include <stdio.h>
#include <time.h>

void queen(int n);


int main()
{
	int n = 8;
	queen(n);
	return 0;
}
void queen(int n)
{

	int board[n][n];
	int l, m;
				for(l = 0; l < n; l++)
				{
					for(m = 0; m < n; m++)
					{
						
						board[l][m] = 0;
					}
				}
	int i = 0, j = 0;
	int k;
	int hor[n] , ver[n], diag1[n], diag2[n];
	int foundcounter = 0;
	int ipos[n], jpos[n];
	int countqueens = 0;
	int coloccu[n];
	for(k = 0; k < n; k++)
	{
		//initializing horizontal, vertical, diagonal values that a queen can occupy to a value that wont be used
		hor[k] = 42;
		ver[k] = 42;
		diag1[k] = 42;
		diag2[k] = 42;
		ipos[k] = 0;
		jpos[k] = 0;
		coloccu[n] = 0;
	}
	int newi  = 0, newj = 0;//useless
	countqueens = 0;
	i = newi;
	while(i < n)//for rows
	{
		
			for(l = i; l < n; l++)
			{
				//initializing horizontal, vertical, diagonal values that a queen can occupy to a value that wont be used
				hor[l] = 42;
				ver[l] = 42;
				diag1[l] = 42;
				diag2[l] = 42;
				ipos[l] = 0;
				jpos[l+1] = 0;
			}
		j = jpos[i];
		while(j < n)//for colums
		{
			if(i == 0)//to place the queen in the first row
			{
				foundcounter = 1;
			}
			int y = 0, z;
			if(i <= 4)
			{
				y = 0;
			}
			else 
			{
				y = 0;
			}
			
			for(k = y; k < i; k++)
			{
				
				
				if(j == ver[k] || (i - j) == diag1[k] || (i + j) == diag2[k] 
				|| 
				 j == ver[k+1] || (i - j) == diag1[k+1] || (i + j) == diag2[k+1]
				|| 
				j == ver[k+2] || (i - j) == diag1[k+2] || (i + j) == diag2[k+2]
				|| 
				j == ver[k+3] || (i - j) == diag1[k+3] || (i + j) == diag2[k+3] || coloccu[i] == 1
				|| 
				 j == ver[k+4] || (i - j) == diag1[k+4] || (i + j) == diag2[k+4]
				 || 
				j == ver[k+5] || (i - j) == diag1[k+5] || (i + j) == diag2[k+5]
				|| 
				j == ver[k+6] || (i - j) == diag1[k+6] || (i + j) == diag2[k+6]
				|| 
				j == ver[k+7] || (i - j) == diag1[k+7] || (i + j) == diag2[k+7])
				{
					
					break;
					
				}
				foundcounter = 1;
				
			}
			if(foundcounter == 1 && board[i][j] == 0)
			{
				countqueens++;
				//printf("%d %d %d %d %d %d \n", ver[0], diag1[0], i, j, i-j, i+j);
				printf("found a position: %d %d queenscount: %d\n", i, j, countqueens);
				board[i][j] = 1;
				
				for(l = 0; l < n; l++)
				{
					for(m = 0; m < n; m++)
					{
						if(l == i || m == j || (i - j) == (l-m) || (i + j) == (l+m))
						{
							board[l][m] = 1;
						}
					}
				}
				coloccu[i] = 1;
				ipos[i] = i;
				jpos[i] = j;
				hor[i] = i;
				ver[i] = j;
				diag1[i] = i-j;
				diag2[i] = i+j;
				foundcounter = 0;
				break;
			}
			j++;
		}
		//printf("%d %d",i-1, countqueens);
		//sleep(1);
		
		i++;
		if(countqueens != i)
		{
			printf("-----------------Backtrack-------------------\nZz");
			i = i - 2;
			//ipos[i] = i;
				//jpos[i] = j;
			
				for(l = 0; l < n; l++)
				{
					for(m = 0; m < n; m++)
					{
						if(l == i || m == jpos[i] || (i - jpos[i]) == (l-m) || (i + jpos[i]) == (l+m))
						{
							board[l][m] = 0;
						}
					}
				}
				coloccu[i] = 0;
				hor[i] = 42;
				ver[i] = 42;
				diag1[i] = 42;
				diag2[i] = 42;
			jpos[i] = jpos[i] + 1;
			countqueens = i;
		}
		//printf("i: %d, jpos: %d queens: %d\n", i, jpos[i], countqueens);
	}
	
	/**for(k = 0; k < n; k++)
	{
		printf("hor: %d\n", hor[k]);
		printf("ver: %d\n", ver[k]);
		printf("diag1: %d\n", diag1[k]);
		printf("diag2: %d\n", diag2[k]);
	}**/
	for(k = 0; k < n; k++)
	{
	
		printf("%d %d\n", hor[k], ver[k]);
		/**printf("hor: %d\n", hor[k]);
		printf("ver: %d\n", ver[k]);
		printf("diag1: %d\n", diag1[k]);
		printf("diag2: %d\n", diag2[k]);**/
	}
	int si = 0, sj = 0;
	for(k = 0; k < n; k++)
	{
	
		for(l = 0; l < n; l++)
		{
			if(k == hor[si] && l == ver[si])
			{
				printf("1 ");
				si++;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
	
}
