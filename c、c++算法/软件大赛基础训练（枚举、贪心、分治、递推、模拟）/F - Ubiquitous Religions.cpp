#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int f[50010];
int n,m;

int find(int x)
{
	if(f[x]==-1)
		return x;
	else
	{
		f[x]=find(f[x]);
		return f[x];
	}
}

void Union(int x,int y)
{
	int fx,fy;
	fx=find(x);
	fy=find(y);
	if(fx!=fy)
		f[fx]=fy;
}


int main()
{
	int a,b;
	int num=1;
	while(~scanf("%d%d",&n,&m) && n && m)
	{
		memset(f,-1,sizeof(f));
		int ans=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		for(int i=0;i<n;i++)
		{
			if(find(i)==i)
				ans++;
		}
		printf("Case %d: %d\n",num,ans);
		num++;
	}
	return 0;
}