#include <stdio.h>
#include <string.h>
#include <math.h>
int n,m;
int g[100][100],l[100][100];
int ans[100],v[100],mark;
 int gcd1(int a,int b)
    {
        if(a==0)
        {
            return b;
        }else
        {
            return gcd1(b % a,a);
        }
    }
bool dfs(int c)
{
    int i;
    v[c]=mark;
    for (i=1;i<=n;i++)
    {
        if(g[c][i]){
            if(l[c][i]%g[c][i])return 0;
            if(v[i]==mark){
                if((long long)l[c][i]*g[c][i]/ans[c]!=ans[i])return 0;
            }
            else{
                ans[i]=(long long)l[c][i]*g[c][i]/ans[c];
                int gcd=gcd1(ans[i],ans[c]), lcm=(long long)ans[i]*ans[c]/gcd;
                printf("%d %d\n",gcd,lcm);
                if(gcd!=g[c][i]||lcm!=l[c][i]||!dfs(i))return 0;
            }
        }
    }
    return 1;
}

int main ()
{
    int i;
    memset(g,0,sizeof(g)); memset(l,0,sizeof(l));
    memset(ans,0,sizeof(ans));
    mark=0;
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        int a,b,gcd,lcm;
        scanf ("%d%d%d%d", &a, &b, &gcd, &lcm);
        a--; b--;
        g[a][b]=g[b][a]=gcd;
        l[a][b]=l[b][a]=lcm;
    }
    for (i=1;i<=n;i++)
    {
        if(!ans[i]){
        int j;
        for(j=1;j<=1000000;j++){
            mark++;
            ans[i]=j;
            if(dfs(i))break;
        }
        if(j>1000000){
            printf("NO\n");
            return 0;
        }
    }
    }
    printf("YES\n");
    for (i=1;i<=n;i++)
    {
        printf("%d",ans[i]);
        if (i==n)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
