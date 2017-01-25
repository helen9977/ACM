#include <stdio.h>
int  maze[5][5];
int  dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct node
{
    int x, y;
    int pre;//前一个路径
} path[25];

void print(int x)///打印
{
    if(path[x].pre != -1)//不为空
    {
        print(path[x].pre);//回溯
        printf("(%d, %d)\n",path[x].x, path[x].y);
    }
}
/*队列*/
void bfs(int x, int y)//广搜
{
    int rear=1;//队尾
    int front=0;//队头
    int dx,dy;
    path[front].x = x;
    path[front].y = y;
    path[front].pre = -1;
    while(front < rear)//不为空的时候
    {
        for(int i=0; i<4; i++)
        {
            dx = path[front].x + dir[i][0];
           	dy = path[front].y + dir[i][1];
            if(dx<0 || dx>=5 || dy<0 || dy>=5 || maze[dx][dy])//边界条件
                continue;
            maze[dx][dy] = 1;///标记，表示已经走过
            path[rear].x = dx;
            path[rear].y = dy;
            path[rear].pre = front;
            rear++;///入队
            if(dx==4 && dy==4) //找到出口
                print(front);
        }
        front++;///出队
    }
}
int main()
{
	int i,j;
    for(i=0; i<5; i++)
        for(j=0; j<5; j++)
            scanf("%d",&maze[i][j]);//获取迷宫地图
    printf("(0, 0)\n");
    bfs(0,0);
    printf("(4, 4)\n");
    return 0;
}