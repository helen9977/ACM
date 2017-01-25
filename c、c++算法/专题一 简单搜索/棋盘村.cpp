#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int t,n,m,x,y;
char map[25][25];
int book[25][25];

int dx[2]={0,1};
int dy[2]={1,0};//向下 向右

int num = 0;//条数
//要记得，每次都初始化为0

void dfs(int a,int b)
{
	if(a>=n&&b>=m)
	{
		if (a==n&&b==m)
			num++;
		return;
	}
	for(int k=0;k<2;k++)
	{
		int bx,by;
		bx=a+dx[k];
		by=b+dy[k];
        if((book[bx][by]==0) && map[bx][by]!='#')
        {
            book[bx][by]=1;
            dfs(bx,by);
            book[bx][by]=0;
        }
	}

	return ;
}
int main ()
{
	scanf("%d",&t);
	while (t --)
	{
		scanf("%d%d%d%d",&n,&m,&x,&y);
		memset(book,0,sizeof(book));
		memset(map, 0, sizeof(map)); //不能走则设为1

        if ((x - 2 >= 0) && (y + 1 >= 0))
            map[x - 2][y + 1] = '#';
        if ((x - 2 >= 0) && (y - 1 >= 0))
            map[x - 2][y - 1] = '#';
        if ((x - 1 >= 0) && (y + 2 >= 0))
            map[x - 1][y + 2] = '#';
        if ((x - 1 >= 0) && (y - 2 >= 0))
            map[x - 1][y - 2] = '#';
        if ((x + 1 >= 0) && (y + 2 >= 0))
            map[x + 1][y + 2] = '#';
        if ((x + 1 >= 0) && (y - 2 >= 0))
            map[x + 1][y - 2] = '#';
        if ((x + 2 >= 0) && (y + 1 >= 0))
            map[x + 2][y + 1] = '#';
        if ((x + 2 >= 0) && (y - 1 >= 0))
            map[x + 2][y - 1] = '#';

       	map[x][y] = '#';

		dfs(0,0);
		printf("%d\n",num);
		num = 0;
	}
	return 0;
}
