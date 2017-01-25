#include <stdio.h>
#include <string.h>


int s,n,m;
int past[101][101][101];


struct cup
{
	int a,b,c;//三个杯子
	int num;//最少次数
}x,y,a[1024];

int ifok(struct cup x)
{
	if((x.a==x.b)&&(x.c==0))
		return 1;
	else if ((x.b==x.c)&&(x.a==0))
		return 1;
	else if ((x.a==x.c)&&(x.b==0))
		return 1;
	else 
		return 0;
}

int min(int x,int y)
{
	if(x>y)
		return y;
	else
		return x;
}

int pouraway()
{
	int front ,rear;
	
	front=0;
	rear=0;

	x.a=s;
	x.b=0;
	x.c=0;
	x.num=0;
	a[front]=x;
	rear++;//入队
	past[s][0][0]=1;

	while(front!=rear)
	{
		int pour;//倒水
		x=a[front];
		front++;//出队

		
		if (ifok(x))
			return x.num;
		if(x.a)//当有水的时候
		{
			if(pour=min(x.a,n-x.b))//b杯还没有满
			{
				y.a=x.a-pour;
				y.b=x.b+pour;
				y.c=x.c;
			
				if (!past[y.a][y.b][y.c])
				{
					y.num=x.num+1;//增加倒水次数
					a[rear]=y;
					rear++;//入队
					past[y.a][y.b][y.c]=1;//标注已有状态
				}
			}
			if(pour=min(x.a,m-x.c))
			{
				y.a=x.a-pour;
				y.c=x.c+pour;
				y.b=x.b;		
				if(!past[y.a][y.b][y.c])
				{
					y.num=x.num+1;
					a[rear]=y;
					rear++;
					past[y.a][y.b][y.c]=1;
				}
			}

		}
		if(x.b)
		{
			if(pour=min(s-x.a,x.b))
			{
				y.a=x.a+pour;
				y.b=x.b-pour;
				y.c=x.c;
			
				if(!past[y.a][y.b][y.c])
				{
					y.num=x.num+1;
					a[rear]=y;
					rear++;
					past[y.a][y.b][y.c]=1;
				}
			}
			if(pour=min(x.b,m-x.c))
			{
				y.a=x.a;
				y.b=x.b-pour;
				y.c=x.c+pour;
				

				if(!past[y.a][y.b][y.c])
				{
					y.num=x.num+1;
					a[rear]=y;
					rear++;
					past[y.a][y.b][y.c]=1;
				}
			}
		}
		if (x.c)
		{
			if(pour=min(s-x.a,x.c))
			{
				y.a=x.a+pour;
				y.b=x.b;
				y.c=x.c-pour;
				

				if(!past[y.a][y.b][y.c])
				{
					y.num=x.num+1;
					a[rear]=y;
					rear++;
					past[y.a][y.b][y.c]=1;
				}
			}
			if(pour=min(n-x.b,x.c))
			{
				y.a=x.a;
				y.b=x.b+pour;
				y.c=x.c-pour;
				

				if(!past[y.a][y.b][y.c])
				{
					y.num=x.num+1;
					a[rear]=y;
					rear++;
					past[y.a][y.b][y.c]=1;
				}
			}
		}
	}


	return 0;



}

int main ()
{
	while(scanf("%d%d%d",&s,&n,&m)!=EOF)
	{
		if(s==0&&n==0&&m==0)
			break;
		if(s%2!=0)
			printf("NO\n");
		else
		{
			memset (past,0,sizeof (past));
			int ans=pouraway();
			if (ans)
				printf ("%d\n",ans);
			else
				printf ("NO\n");
		}
		
	}
	return 0;
} 	
