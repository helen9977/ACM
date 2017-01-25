#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n ,d;

struct node
{
	double left,right;
	
}p[1010];

bool cmp(node x,node y)
{
	return x.left < y.left;
}

int main()
{

	int num=0;
	int x,y;
	while(~scanf("%d%d",&n,&d) && n && d)
	{
		memset(p,0,sizeof(p));
		int flag=0;
		int ans=1;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			if(y>d)
				{
					flag=1;
				}
			else
			{
				p[i].left = x - sqrt(d*d-y*y);
				p[i].right = x + sqrt(d*d-y*y);
			}
		}
		num++;	
		if(flag)
			{
				printf("Case %d: -1\n",num);	
			} 
		else
		{
			sort(p,p+n,cmp);
			//cur=p[0];
			double m=p[0].right;
			for(int i=1;i<n;i++)
			{
				if(m<p[i].left)
				{
					ans++;
					m=p[i].right;
				}
				else
				{
					m=min(m,p[i].right);
				}

			}
			printf("Case %d: %d\n",num,ans);
		}
	}
	return 0;
}
