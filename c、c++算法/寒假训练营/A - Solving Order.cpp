#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


struct node
{
	char color[20];
	int num;
}n[110];

bool cmp(node x,node y)
{
	return x.num > y. num;
}

int main ()
{
	int T,N;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		memset(n,0,sizeof(n));
		for(int i=0;i<N;i++)
		{
			scanf("%s%d",n[i].color,&n[i].num);
		}
		sort(n,n+N,cmp);
		for (int i = 0; i <N; ++i)
		{
			if(i==0)
			{
				printf("%s",n[i].color );
			}
			else
			{
				printf(" %s", n[i].color );
			}
		}
		printf("\n");
	}
	return 0;
}