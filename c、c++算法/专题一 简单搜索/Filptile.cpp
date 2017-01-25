#include <iostream>
#include <functional>
#include <algorithm>
#include <string.h>
#include <stdio.h>

  using namespace std;
  
  static int map[18][18], flip[18][18], ans_map[18][18], M, N;
  static int dirx[4] = { -1, 0, 0, 1 };
  static int diry[4] = { 0, -1, 0, 0 };
 
 int solve(void);
 int get_color(const int, const int);


 int solve()
 {
     int ans = 0;
     for (int i = 1; i < N; i++)//从第二行开始一行一行模拟
         for (int j = 0; j < M; j++)
             if (get_color(j, i - 1) == 1)//记住是上一行翻的牌子
                 flip[i][j] = 1;//说明需要翻
 
     for (int j = 0; j < M; j++)//得到最后一行的所有格子的颜色，如果还有黑色，则说明这一步无法把格子全部翻转成白色
         if (get_color(j, N - 1) == 1)
             return -1;
 
     for (int i = 0; i < N; i++)//统计步数
         for (int j = 0; j < M; j++)
             if (flip[i][j])
                 ans++;
     return ans;
 }
 
 int get_color(const int x, const int y)
 {
     //得到(x,y)位置的颜色
     int ny, nx, sum = map[y][x];
 
     for (int i = 0; i < 4; i++)
    {
         nx = x + dirx[i]; ny = y + diry[i];
         if ((0 <= nx&&nx < M) && (0 <= ny&&ny < N))
             sum += flip[ny][nx];
     }
     return sum % 2;
 }

 
 int main()//开关问题，枚举第一行即可得到下面几行的关系
 {
     int ans, tmp;
     while (~scanf("%d%d", &N, &M))//读图
     {
         for (int i = 0; i < N; i++)
             for (int j = 0; j < M; j++)
                 scanf("%d", &map[i][j]);
         ans = 99999;
         for (int i = 0; i < 1 << M; i++)//枚举第一行
         {
             memset(flip, 0, sizeof(flip));
             for (int j = 0; j < M; j++)//枚举结果填入第一行
                 if ((1 << j & i) != 0)
                     flip[0][M - j - 1] = 1;
             tmp = solve();
             if (tmp >= 0 && tmp < ans)
             {
                 ans = tmp;
                 memcpy(ans_map, flip, sizeof(flip));
             }
         }
 
         if (ans == 99999)
             printf("IMPOSSIBLE\n");
         else
         {
             for (int i = 0; i < N; i++)
             {
                 for (int j = 0; j < M; j++)
                     printf("%d ",ans_map[i][j]);
                 printf("\n");
             }
         }
     }
     return 0;
 }