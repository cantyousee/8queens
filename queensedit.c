#include <stdio.h>
#include <time.h>

void queen(int n);
static int unij = 0;
static int soln = 0;

int main()
{
	int n = 8;
	queen(n);
	return 0;
}
void queen(int n)
{
	//int soln = 0;
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
	int jindexvalue = 0;
	int coloccu[n];
	int sol[92];
	int backi = 0;
	int backj = 0;
	while(jindexvalue < 8)
	{
	do
	{
		countqueens = 0;
		for(l = 0; l < n; l++)
		{
			for(m = 0; m < n; m++)
			{
				
				board[l][m] = 0;
			}
		}
		for(k = 0; k < n; k++)
		{
			//initializing horizontal, vertical, diagonal values that a queen can occupy to a value that wont be used
			hor[k] = 42;
			ver[k] = 42;
			diag1[k] = 42;
			diag2[k] = 42;
			ipos[k] = 0;
			jpos[k] = 0;
			coloccu[k] = 0;
		}
		
		jpos[jindexvalue] = unij;
		
		int newi  = 0, newj = 0;//useless
		countqueens = 0;
		i = 0;
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
				
					int g;
					int checkg = 0;
					for(g = 0; g < 8; g++)
					{
						if(j == ver[g] || (i - j) == diag1[g] || (i + j) == diag2[g])
						checkg = 1;
					}
					if(checkg == 1)
					{
						break;
					}
					foundcounter = 1;
				
				}
				if(foundcounter == 1 && board[i][j] == 0)
				{
					countqueens++;
					//printf("%d %d %d %d %d %d \n", ver[0], diag1[0], i, j, i-j, i+j);
					//printf("found a position: %d %d queenscount: %d\n", i, j, countqueens);
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
				backi = hor[i-1];
				backj = ver[i-1] + 1;
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
		int place = 1;
		sol[soln] = 0;
		for(k = 0; k < n; k++)
		{
	
			//printf("%d %d\n", hor[k], ver[k]);
			sol[soln] = sol[soln] + ((ver[k] + hor[k]) * place);
			place = place * 10;
			/**printf("hor: %d\n", hor[k]);
			printf("ver: %d\n", ver[k]);
			printf("diag1: %d\n", diag1[k]);
			printf("diag2: %d\n", diag2[k]);**/
		}
		int si = 0, sj = 0;
		
		int check = 0;
		for(k = 0; k < soln; k++)
		{
			if(sol[k] == sol[soln])
			check = 1;
		}
		
		if(check == 1)
		{
			soln++;
			unij++;
			continue; 
		}
		printf("SOLUTION NO: %d solution id %d\n", soln, sol[soln]);
		soln++;
		
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
		unij++;
	}while(unij < 8);
	jindexvalue++;
	unij = 0;
	}
}
