#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int n,m,k;
int f[30010];

int find(int x)
{
    if (f[x]==-1)
    {
        return x;
    }
    else
    {
        f[x]=find(f[x]);
        return f[x];
    }
}
void Union(int a,int b)
{
    int fx,fy;
    fx=find(a);
    fy=find(b);
    if(fx!=fy)
    {
        f[fx]=fy;
    }
}

int main ()
{
    while(scanf("%d%d",&n,&m) && (n || m))
    {   
        memset(f,-1,sizeof(f));
        for(int i=0;i<m;i++)
        {
            scanf("%d",&k);
            int x,y;
            scanf("%d",&x);
            for(int i=1;i<k;i++)
            {
                scanf("%d",&y);
                Union(x,y);
                x=y;
            }
        }
        int sus=find(0);
        if(sus==-1)
        {
            printf("0\n");
        }
        else
        {
            int ans=1;

            for(int j=1;j<n;j++)
            {
                if(find(j)==sus)
                {
                    ans++;
                }
            }
            printf("%d\n",ans );
        }

    }
    return 0;
}