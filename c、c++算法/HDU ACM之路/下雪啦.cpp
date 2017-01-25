#include <stdio.h>
#include <string.h>

int T,N;
int flawor[100001][6];
int book[6];


int main ()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&N)
		{
			for(int j=0;j<N;j++)
			{
				for(int k=0;k<6;k++)
					scanf("%d",&flawor[j][k]);//读入雪花
			}
		}

		for(int a=0;a<N;a++)
		{
			for(int b=0;b<6,b++)
			{	
				d=a;
				for(int c=0;c<6;c++)
				{
					if(flawor[a][b]==flawor[d+1][c])
						book[c]=1;
					d++
				}
			}
			for (int e=0;e<b;e++)
				if(book[e]==0)
					flag=0;
		}
	}
}