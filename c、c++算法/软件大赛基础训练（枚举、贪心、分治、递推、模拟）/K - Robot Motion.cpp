#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

char map[11][11];
int book[11][11];
int vis[11][11];

int n,m,s;

struct node
{
	int x,y;
	int step;
};

void bfs()
{
		queue<node>q;
		node cur,next;
		memset(book,0,sizeof(book));
		memset(vis,0,sizeof(vis));

		cur.x=0;
		cur.y=s-1;
		cur.step=1;
		vis[cur.x][cur.y]=1;
		q.push(cur);
		while(!q.empty())
		{
			cur=q.front();
			q.pop();
			if(cur.x<0||cur.x>=n||cur.y<0||cur.y>=m)
			{
				printf("%d step(s) to exit\n",cur.step-1);
				return ;
			}

			if(map[cur.x][cur.y]=='N')
			{
				next.x=cur.x-1;
				next.y=cur.y;
				if(!vis[next.x][next.y])
				{
					vis[next.x][next.y]=1;
					book[next.x][next.y]=cur.step;
					next.step=cur.step+1;
					q.push(next);
				}
				else
				{
					printf("%d step(s) before a loop of %d step(s)\n", book[next.x][next.y],cur.step-book[next.x][next.y]);
					return ;
				}
			}
			if(map[cur.x][cur.y]=='S')
			{
				next.x=cur.x+1;
				next.y=cur.y;
				if(!vis[next.x][next.y])
				{
					vis[next.x][next.y]=1;
					book[next.x][next.y]=cur.step;
					next.step=cur.step+1;
					q.push(next);
				}
				else
				{
					printf("%d step(s) before a loop of %d step(s)\n", book[next.x][next.y],cur.step-book[next.x][next.y]);
					return ;
				}
			}
			if(map[cur.x][cur.y]=='E')
			{
				next.x=cur.x;
				next.y=cur.y+1;
				if(!vis[next.x][next.y])
				{
					vis[next.x][next.y]=1;
					book[next.x][next.y]=cur.step;
					next.step=cur.step+1;
					q.push(next);
				}
				else
				{
					printf("%d step(s) before a loop of %d step(s)\n", book[next.x][next.y],cur.step-book[next.x][next.y]);
					return ;
				}
			}
			if(map[cur.x][cur.y]=='W')
			{
				next.x=cur.x;
				next.y=cur.y-1;
				if(!vis[next.x][next.y])
				{
					vis[next.x][next.y]=1;
					book[next.x][next.y]=cur.step;
					next.step=cur.step+1;
					q.push(next);
				}
				else
				{
					printf("%d step(s) before a loop of %d step(s)\n", book[next.x][next.y],cur.step-book[next.x][next.y]);
					return ;
				}
			}

		}
		
}

int main()
{
	while(scanf("%d%d%d",&n,&m,&s) && n && m && s)
	{
		
		
		memset(map,0,sizeof(map));
		for(int i=0;i<n;i++)
			scanf("%s",map[i]);

		/*for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
					printf("%c ", map[i][j]);
				printf("\n");
			}
		*/
		
		bfs();
	}
	return 0;
}