#include <stdio.h>
#include <queue>

using namespace std;
long long   n;

int ifok(long long   m)
{
	if(m%n==0)
		return 1;
	else
		return 0;
}

long long  BFS()
{
	long long  x=1,y;
	queue<long long >q;
	q.push(x);
	
	while(!q.empty())
	{
		x=q.front();
		q.pop();

		if(ifok(x))
			return x;

		y=x*10;
		q.push(y);
		y=x*10+1;
		q.push(y);

	}
	return 0;
}

int main()
{
	   
	while(scanf("%ld",&n)!=EOF && n)
	{
		long long  m=BFS();
		printf("%ld\n",m);
	}
	return 0;

}