#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
  
using namespace std;
static char mapc[20][20];
static int mapb[20][20],mapw[20][20],flip[20][20];
static int M=4, N=4;
static int dx[4] = { -1, 0, 0, 1 };
static int dy[4] = { 0, -1, 0, 0 };
 int solve(void);
 int get_colorb(const int, const int);
int get_colorw(const int, const int);


int solvew()
 {
     int ans = 0;
     for (int i = 1; i < N; i++)//从第二行开始一行一行模拟
         for (int j = 0; j < M; j++)
             if (get_colorw(j, i - 1) == 1)//记住是上一行翻的牌子
                 flip[i][j] = 1;//说明需要翻
 
     for (int j = 0; j < M; j++)//得到最后一行的所有格子的颜色，如果还有黑色，则说明这一步无法把格子全部翻转成白色
         if (get_colorw(j, N - 1) == 1)
             return -1;
 
     for (int i = 0; i < N; i++)//统计步数
         for (int j = 0; j < M; j++)
             if (flip[i][j])
                 ans++;
     return ans;
 }
int solveb()
 {
     int ans = 0;
     for (int i = 1; i < N; i++)//从第二行开始一行一行模拟
         for (int j = 0; j < M; j++)
             if (get_colorb(j, i - 1) == 0)//记住是上一行翻的牌子
                 flip[i][j] = 1;//说明需要翻
 
     for (int j = 0; j < M; j++)//得到最后一行的所有格子的颜色，如果还有黑色，则说明这一步无法把格子全部翻转成白色
         if (get_colorb(j, N - 1) == 0)
             return -1;
 
     for (int i = 0; i < N; i++)//统计步数
         for (int j = 0; j < M; j++)
             if (flip[i][j])
                 ans++;
     return ans;
 }
int get_colorw(const int x, const int y)
 {
     //得到(x,y)位置的颜色
     int ny, nx, sum = mapw[y][x];
 
     for (int i = 0; i < 4; i++)
    {
         nx = x + dx[i]; ny = y + dy[i];
         if ((0 <= nx&&nx < M) && (0 <= ny&&ny < N))
             sum += flip[ny][nx];
     }
     return sum % 2;
 }
int get_colorb(const int x, const int y)
 {
     //得到(x,y)位置的颜色
     int ny, nx, sum = mapb[y][x];
 
     for (int i = 0; i < 4; i++)
    {
         nx = x + dx[i]; ny = y + dy[i];
         if ((0 <= nx&&nx < M) && (0 <= ny&&ny < N))
             sum += flip[ny][nx];
     }
     return sum % 2;
 }
 

int main()
{//开关问题，枚举第一行即可得到下面几行的关系

    int ans1,ans2,tmp,ans;
        for (int i = 0; i < N; i++)
        {
                scanf("%s", mapc[i]);
        
            for (int j = 0; j < M; j++)
                {
                    
                    if(mapc[i][j]=='w')
                        {
                            mapb[i][j]=0;
                            mapw[i][j]=0;
                        }
                    else
                        {
                            mapb[i][j]=1;
                            mapw[i][j]=1;
                        }
                }
        }

    /*for (int i = 0; i < N; i++)
    {
            for (int j = 0; j < M; j++)
                    printf("%d ", mapw[i][j]);
            printf("\n");
    }
 for (int i = 0; i < N; i++)
    {
            for (int j = 0; j < M; j++)
                    printf("%d ", mapb[i][j]);
            printf("\n");
    }
    */
        int flag=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(mapw[i][j]==1)
                {
                    flag=1;
                    break;
                }

            }
            if(flag)
                break;
        }

        int flag1=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(mapb[i][j]==0)
                {
                    flag1=1;
                    break;
                }

            }
            if(flag1)
                break;
        }

    

        ans1 = 99999;
        for (int i = 0; i < pow(2,M); i++)//枚举第一行
        {
            memset(flip, 0, sizeof(flip));
        for (int j = 0; j < M; j++)//枚举结果填入第一行
            if ((1 << j & i) != 0)
                    flip[0][M - j - 1] = 1;
        tmp = solvew();
            if (tmp >= 0 && tmp < ans1)
            {
                ans1 = tmp;
            }
        }
         ans2 = 99999;
        for (int i = 0; i < pow(2,M); i++)//枚举第一行
        {
            memset(flip, 0, sizeof(flip));
        for (int j = 0; j < M; j++)//枚举结果填入第一行
            if ((1 << j & i) != 0)
                    flip[0][M - j - 1] = 1;
        tmp = solveb();
            if (tmp >= 0 && tmp < ans2)
            {
                ans2 = tmp;
            }
        }
        if(ans1>ans2)
            ans=ans2;
        else
            ans=ans1;
          
        if (ans == 99999)
            printf("Impossible\n");
         else
        {
            if(flag1==0||flag==0)
                printf("0\n");
            else
                printf("%d\n",ans);
        }

    return 0;
 }