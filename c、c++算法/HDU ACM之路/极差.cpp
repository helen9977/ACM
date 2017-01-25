#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int T,n,s=0;
	int a[1001];
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		sort(a,a+n);
		s=a[n-1]-a[0];
		printf("%d",s);
	}
	return 0;
}
