#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxv= 10001;
struct edge
{
	int cost,dis;
}map[maxv];
bool com(edge x,edge y)
	if (x.dis==y.dis)
	{
		return x.cost<y.cost;
	}
	return x.dis<y.dis
}

int main()
{
	int n,i,k,count;
	while(cin>>n && n)
	{
		
	}
}