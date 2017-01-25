#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

const int MAX = 100009;

struct  P//记录火山口的行列信息
{
    int r, c;
}map[MAX];

bool cmp(P a, P b)//按行排序后按列排序
{
    if (a.r < b.r)
        return true;
    else if (a.r == b.r && a.c < b.c)
    {
        return true;
    }
    else
        return false;
}

int N, M;

struct Section//区间信息
{
    int l, r;
}st[MAX];
int L = 0;//全局区间

void combine(Section s1[], int L1, Section s2[], int L2)//区间合并
{
   // int rL = 0;
    int j = 0;
    for (int i = 0; i < L2; i++)
    {
        if (s2[i].l > s2[i].r)
            continue;
        if (s1[j].l >= s2[i].l && s1[j].l <= s2[i].r)
        {
            s2[i].l = s1[j].l;
            continue;
        }

        if (s1[j].l >= s2[i].r && s1[j].l <= s2[i].r)
        {
            s2[i].l = s1[j].l;
        }

        if (s2[i].r < s1[j].l)
        {
            s2[i].l = -1;
            s2[i].r = -1;
            continue;
        }

        if (j>=1 && s2[i].l > s1[j - 1].r && s2[i].r < s1[j].l)
        {
            s2[i].l = -1;
            s2[i].r = -1;
            continue;
        }

        if (j == L1 - 1 && s2[i].l > s1[j ].r)
        {
            s2[i].l = -1;
            s2[i].r = -1;
            continue;
        }

        if (L1 == 1 && s2[i].l > s1[j].r)
        {
            s2[i].l = -1;
            s2[i].r = -1;
            continue;
        }
        while (s1[j].r < s2[i].l || s2[i].l > s1[j].r)
        {
            j++;
            i--;
        }
    }
    int m = 0;
    //合并完成后要更新全局区间，S1传进来就是st全局，有点难看！当时想的复杂
    //而且我是通过上一次的区间更新当前正判断行的区间后，再更新全局的
    for (int i = 0; i < L2; i++)
    {
        if (s2[i].l != -1)
        {
            s1[m].l = s2[i].l;
            s1[m++].r = s2[i].r;
        }
    }
    L = m;
}

void solve()
{
    int mi = 1;
    int i = 1;
    Section st2[MAX];
    memset(st2, 0, sizeof(st2));
    int st2L = 0;
    int index = 1;
    L = 0;
    st[L].l = 1;
    if (map[mi].r == 1)
    {
        st[L++].r = map[mi].c - 1;
        i++;
        while (map[mi].r != i && map[mi].r < i)
        {
            mi++;
        }
    }
    else
    {
        st[L++].r = N;
    }
    if (st[L - 1].r == 0)
    {
        L = 0;
        return;
    }
    while (mi < M + 1)//只要去合并有火山口的那行的行了
    {
        if (mi <= M &&  map[mi].r == i)
        {
            if (map[mi].c != 1)
            {
                if (map[mi].c > index)
                {
                    st2[st2L].l = index;
                    st2[st2L++].r = (map[mi].c - 1) >= index ? map[mi].c - 1 : index;
                }
            }
            index = map[mi].c + 1;
            mi++;
            continue;
        }
        if (index <= N)
        {

            st2[st2L].l = index;
            st2[st2L++].r = N;
        }
        combine(st, L, st2, st2L);
        st2L = 0;
        index = 1;
        if (L == 0)
            return;
        bool bb = false;
        bool bb2 = false;
        while (map[mi].r != i && map[mi].r > i + 1)//跳过连续的无火山口的区间
        {
            if (!bb)//第一次你需要更新一下
            {
                st2[st2L].l = index;
                st2[st2L++].r = N;
                L = 0;
                st[L++].r = N;//这时候全局的右起点为N，但左边不变
                st2L = 0;
                bb = true;
            }
            index = 1; 
            if (!bb2)
            {
                bb2 = true;
                i = map[mi].r - 2;//这是优化的地方，直接跳过中间那些连续的五火山口
            }
            i++;
        }
        i++;
    }
    bool bb2 = false;
    while (i <= N)
    {
        if (index <= N)
        {
            st2[st2L].l = index;
            st2[st2L++].r = N;
        }
        combine(st, L, st2, st2L); 
        if (i<N-3 && !bb2)//直接跳过中间那些连续的五火山口
        {
            bb2 = true;
            i = N - 2;
        }
        if (L == 0)
            return;
        st2L = 0;
        index = 1;
        i++;
    }
}

int main()
{
    while (scanf("%d %d", &N, &M) != EOF)
    {
        bool is = false;
        for (int i = 1; i <= M; i++)
        {
            scanf("%d %d",&map[i].r,&map[i].c);
            if (!is && map[i].r == N && map[i].c == N)
            {
                is = true;
            }
        }

        sort(map + 1, map + M + 1, cmp);
        solve();
        if (L!= 0 && st[L - 1].r >= N)
        {
            cout << 2 * (N - 1) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
