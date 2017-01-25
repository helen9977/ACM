#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define N 1100
using namespace std;
struct node {
int u,v,w,next;
}bian[N*N*4];
int head[N],yong,dis[N],work[N];
void init(){
yong=0;
memset(head,-1,sizeof(head));
}
void addbian(int u,int v,int w) {
bian[yong].u=u;
bian[yong].v=v;
bian[yong].w=w;
bian[yong].next=head[u];
head[u]=yong++;
}
void add(int u,int v,int w) {
addbian(u,v,w);
addbian(v,u,0);
}
int min(int a,int b)
{
return aq;
q.push(s);
dis[s]=0;
while(!q.empty())
{
int u=q.front();
q.pop();
for(int i=head[u];i!=-1;i=bian[i].next)
{
int v=bian[i].v;
if(bian[i].w&&dis[v]==-1)
{
dis[v]=dis[u]+1;
q.push(v);
if(v==t)
return 1;
}
}
}
return 0;
}
int dfs(int s,int limit,int t)
{
if(s==t)return limit;
for(int &i=work[s];i!=-1;i=bian[i].next)
{
int v=bian[i].v;
if(bian[i].w&&dis[v]==dis[s]+1)
{
int tt=dfs(v,min(limit,bian[i].w),t);
if(tt)
{
bian[i].w-=tt;
bian[i^1].w+=tt;
return tt;
}
}
}
return 0;
}
int dinic(int s,int t)
{
int ans=0;
while(bfs(s,t))
{
memcpy(work,head,sizeof(head));
while(int tt=dfs(s,inf,t))
ans+=tt;
}
return ans;
}
int f[N],ff[N],dp[N][N],ma[N][N];
int judge(int n,int m) {
int i,j,k;
memset(dp,0,sizeof(dp)); 
for(i=1;i<=n;i++)
for(j=head[i];j!=-1;j=bian[j].next ){
int v=bian[j].v;
if(v>n&&v<=n+m)
ma[i][v-n]=bian[j^1].w;
}
for(i=1;i<=n;i++) {
if(f[i]==0||f[i]==9*m)continue;
for(j=1;j<=m;j++) {
if(ff[j]==0||ff[j]==9*n)continue;
for(k=j+1;k<=m;k++) {
int flag1=0,flag2=0;
if(ma[i][j]>0&&ma[i][k]<9) {
if(dp[k][j])return 1;
flag1=1;
}
if(ma[i][j]<9&&ma[i][k]>0) {
if(dp[j][k])return 1;
flag2=1;
}
if(flag1)dp[j][k]=1;
if(flag2)dp[k][j]=1;
}
}
}
return 0;
}
int main() {
int m,i,j,s,n,t,suma,k,sumb,T,cou=0;
scanf("%d",&T);
while(T--) {
scanf("%d%d",&n,&m);
k=9;
s=0;t=n+m+1;
init();
suma=0;sumb=0;
for(i=1;i<=n;i++) {
scanf("%d",&f[i]);
suma+=f[i];
add(s,i,f[i]);
}
for(i=1;i<=m;i++) {
scanf("%d",&ff[i]);
sumb+=ff[i];
add(i+n,t,ff[i]);
}
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
add(i,j+n,k);
if(suma!=sumb) {
printf("Case #%d: So naive!\n",++cou);
continue;
}
k=dinic(s,t);
if(k!=suma) {
printf("Case #%d: So naive!\n",++cou);
continue;
}
k=judge(n,m);
// printf("%d\n",k);
if(k)
printf("Case #%d: So young!\n",++cou);
else
printf("Case #%d: So simple!\n",++cou);
}
return 0;}