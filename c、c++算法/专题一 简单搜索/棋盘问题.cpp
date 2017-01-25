#include <stdio.h>
#include <string.h>
int book[8];
int n,k,q,C;
char a[8][8];

void DFS(int i)
{
    if(k==q)//当棋子都放到了棋盘上
    {
        C++;//方案数增加
        return;//返回前一步调用dfs的地方
    }
    if(i>=n)//判断边界
        return;
    for(int j=0;j<n;j++)
    {
        if(book[j]==0&&a[i][j]=='#')
        {
            book[j]=1;
            q++;
            DFS(i+1);
            book[j]=0;//拿起棋子
            q--;
        }
    }
    DFS(i+1);//搜索到下一行
}


int main ()
{
    
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        if (n==-1&&k==-1)
            break;
        
        int i;
        C=0;
        q=0; 
        for(i=0;i<n;i++)
            scanf("%s",a[i]);   
        
        memset(book,0,sizeof(book));
        DFS(0);         
        printf("%d\n",C);
    } 
    return 0;
}





 
