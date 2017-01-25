#include <stdio.h>
//#include <queue>
#include <string.h>

using namespace std;

struct node 
{
	int x,y;
	int k;
	int pre;
	int pos;
}q[11000];


char str[6][10] = {"FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"};
int book[102][102];
int A,B,C;
int k;
int ifok(int a ,int b)
{
	if (a==C || b==C)
		return 1;
	else 
		return 0;
}
void print(int x)
{
	if(q[x].pre!=-1)
	{
		print(q[x].pre);
		printf("%s\n",str[q[x].pos]);
	}
}
int min(int x,int y)
{
	if(x>y)
	return y;
	else
	return x;
}
void BFS()
{
	int rear=1;
	int front=0;
	k=0;
	memset(book,0,sizeof(book));
	q[front].x=0;
	q[front].y=0;
	q[front].pre=-1;
	book[0][0]=1;
	while(front<rear)
	{
	 int i=rear-front;
		/*if (ifok(cur.x,cur.y))
		{
			printf("%d\n",cur.k);
				for(int i=0;i<cur.k;i++)
				{
					printf("%d\n",cur.a[i]);
				}
			for(int i=0;i<cur.k;i++)
			{
				if(cur.a[i][]==1)
					printf("FILL(1)\n");
				if(cur.a[i]==2)
					printf("FILL(2)\n");
				if(cur.a[i]==3)
					printf("DROP(1)\n");
				if(cur.a[i]==4)
					printf("DROP(2)\n");
				if(cur.a[i]==5)
					printf("POUR(1,2)\n");
				if(cur.a[i]==6)
					printf("POUR(2,1)\n");
			}
			
			return ;
		}
	
		*/
		
	
		while(i--)
		{
			
			if(ifok(q[front].x,q[front].y))
			{
			printf("%d\n",k);
			print(front);
			return;
			}
	
			if(!book[A][q[front].y])
			{
			q[rear].x=A;
			q[rear].y=q[front].y;
				
			q[rear].pre=front;
			q[rear].pos=0;
				
			rear++;//入队
			book[q[rear].x][q[rear].y]=1;
			}

			
			if(!book[q[front].x][B])
			{
				q[rear].x=q[front].x;
				q[rear].y=B;
	
				q[rear].pre=front;
				q[rear].pos=1;
				
				rear++;
				book[q[rear].x][q[rear].y]=1;

				
			}
			if(!book[0][q[front].y])
			{
				q[rear].x=0;
				q[rear].y=q[front].y;
				q[rear].pre=front;
				q[rear].pos=2;
				
				
					rear++;
					book[q[rear].x][q[rear].y]=1;

			
			}
			if(!book[q[front].x][0])
			{
				q[rear].x=q[front].x;
				q[rear].y=0;
				
				q[rear].pre=front;
				q[rear].pos=3;
			
				
				rear++;
				book[q[rear].x][q[rear].y]=1;

	
			
			}
			int m=min(q[front].x,B-q[front].y);
			if(!book[(q[front].x)-m][(q[front].y)+m])
			{

				q[rear].x=q[front].x-m;
				q[rear].y=q[front].y+m;
				
				q[rear].pre=front;
				q[rear].pos=4;
		
				rear++;
				book[q[front].x-m][q[front].y+m]=1;
			
			}
			int n=min(A-q[front].x,q[front].y);
			if(!book[q[front].x+n][q[front].y-n])
			{

				q[rear].x=q[front].x+n;
				q[rear].y=q[front].y-n;
				
				q[rear].pre=front;
				q[rear].pos=5;
		
				rear++;
				book[q[front].x+n][q[front].y-n]=1;
			
			}
		front++;//出队
		}
		k++; 
		
	}

	printf("impossible\n");
	return ;

}


int main ()
{
	while(~scanf("%d%d%d",&A,&B,&C))
	{
		memset(book,0,sizeof(book));
		BFS();
	}
	return 0;
} 
