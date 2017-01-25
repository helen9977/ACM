#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;

char map[202][202];
int a[202][202];
int b[202][202];

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int n,m;
int x1,y1,x2,y2;//两个人的坐标位置

struct node
{
	int x;
	int y;
};

void printmap()
{
	for(int i=0;i<n;i++)
		scanf("%s",map[i]);

	for(int i=0;i<n;i++)
		for (int j=0;j<m;j++)

		{
			/*cin>>map[i][j];*/
			if (map[i][j]=='Y')
			{
				x1=i;
				y1=j;
			}
			if(map[i][j]=='M')
			{
				x2=i;
				y2=j;
			}
		}
}

void BFS(int x,int y,int c[202][202])
{
	queue<node>q;
	node next,cur;
	next.x=x;
	next.y=y;
	c[x][y]=0;
	q.push(next);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			next.x=cur.x+dx[i];
			next.y=cur.y+dy[i];
			if(next.x>=0 && next.x<n && next.y>=0 && next.y<m && c[next.x][next.y]==0 && map[next.x][next.y]!='#')
			{ 
				c[next.x][next.y]=c[cur.x][cur.y]+1; //到当前坐标的步数
				q.push(next);
			}
		}
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		printmap();
		BFS(x1,y1,a);
		BFS(x2,y2,b);
		int minv=999999;
		for(int i=0;i<n;i++)
			for (int j=0;j<m;j++)
			{
				if (map[i][j]=='@'&&b[i][j]!=0&&a[i][j]!=0)
				{
					minv=min(minv,a[i][j]+b[i][j]);
				}
			}
		int sum= minv*11;
		printf("%d\n",sum);
	}
	return 0;
}

