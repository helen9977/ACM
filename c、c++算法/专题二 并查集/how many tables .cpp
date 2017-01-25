#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int T,N,M;
int f[2020];

int find(int x)
{
	if (f[x]==0)
		return x;
	else
	{
		f[x]=find(f[x]);
		return f[x]; 
	} 

}
void Union(int x,int y)
{
	int fa,fb;
	fa=find(x);
	fb=find(y);
    if(fa!=fb)
    {
        f[fa]=fb;
    }
}

int main ()
{
	int x,y;
	cin>>T;
	while (T--)
	{
		int num=0;
		scanf("%d%d",&N,&M);
        memset(f,0,sizeof(f));
		
		while(M--)
		{
			cin>>x>>y;
            Union(x,y);
		}

        for(int i=1;i<=N;i++)
        {
            if(f[i]==0)
                num++;
        }
        cout<<num<<endl;

	}
    return 0;
}
