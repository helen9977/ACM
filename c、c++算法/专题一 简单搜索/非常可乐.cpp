#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;

int s,n,m;
int past[111][111][111];


struct cup
{
    int a,b,c;//三个杯子
    int num;//最少次数
}x,y;

int ifok(int a,int b,int c)
{
    if(a==b&&c==0 || a==c&&b==0 || b==c&&a==0)
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
    queue<cup>a;
    x.a=s;
    x.b=0;
    x.c=0;
    x.num=0;
    past[x.a][0][0]=1;
    a.push(x); 

    while(!a.empty())
    {
        int pour;//倒水
        x=a.front();
        a.pop();
        if (ifok(x.a,x.b,x.c))
            return x.num;
        if(x.a)//当有水的时候
        {
            if(pour=min(x.a,n-x.b))//b杯还没有满
            {
                y.a=x.a-pour;
                y.b=x.b+pour;
                y.c=x.c;
                y.num=x.num+1;//增加倒水次数
                if (!past[y.a][y.b][y.c])
                {
                    a.push(y);
                    past[y.a][y.b][y.c]=1;//标注已有状态
                    
                }
            }
            if(pour=min(x.a,m-x.c))
            {
                y.a=x.a-pour;
                y.c=x.c+pour;
                y.b=x.b;
                y.num=x.num+1;      
                if(!past[y.a][y.b][y.c])
                {
                    a.push(y);
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
                y.num=x.num+1;
            
                if(!past[y.a][y.b][y.c])
                {
                    a.push(y);
                    past[y.a][y.b][y.c]=1;
                    
                }
            }
            if(pour=min(x.b,m-x.c))
            {
                y.a=x.a;
                y.b=x.b-pour;
                y.c=x.c+pour;
                y.num=x.num+1;
                if(!past[y.a][y.b][y.c])
                {
                
                    past[y.a][y.b][y.c]=1;
                    a.push(y);
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
                y.num=x.num+1;

                if(!past[y.a][y.b][y.c])
                {
                
                    past[y.a][y.b][y.c]=1;
                    a.push(y);
                }
            }
            if(pour=min(n-x.b,x.c))
            {
                y.a=x.a;
                y.b=x.b+pour;
                y.c=x.c-pour;
                y.num=x.num+1;

                if(!past[y.a][y.b][y.c])
                {
                
                    past[y.a][y.b][y.c]=1;
                    a.push(y);
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
