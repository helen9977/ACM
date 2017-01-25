#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char map[5][5];
int m[5][5];

int main()
{
	int ans=0;
	memset(m,0,sizeof(m));
	memset(map,0,sizeof(map));

	int i,j,k;
	for(i=0;i<4;i++)
		scanf("%s",map[i]);
	/*for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}*/
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(map[i][j]=='+')
			{
				for(k=0;k<4;k++)
				{
					m[i][k]++;
					m[k][j]++;
				}
				m[i][j]--;
			}
		}

/*
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
*/
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(m[i][j]%2)
			{
				ans++;
			}
		}
	}
	printf("%d\n",ans);

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(m[i][j]%2)
			{
				printf("%d %d\n",i+1,j+1);
			}
		}
	}
	return 0;
}